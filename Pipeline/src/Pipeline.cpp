#include "Pipeline.h"

pipeline::Pipeline::Pipeline()
	: m_width(0), m_height(0), 
	m_pShader(nullptr), m_pFrontBuffer(nullptr), m_pBackBuffer(nullptr)
{
	m_vertices.clear();
	m_indices.clear();
}

pipeline::Pipeline::Pipeline(int width, int height)
	: m_width(width), m_height(height),
	m_pShader(nullptr), m_pFrontBuffer(nullptr), m_pBackBuffer(nullptr)
{
	m_vertices.clear();
	m_indices.clear();
}

pipeline::Pipeline::~Pipeline()
{
	if (m_pShader)
	{
		delete m_pShader;
		m_pShader = nullptr;
	}
	if (m_pFrontBuffer)
	{
		delete m_pFrontBuffer;
		m_pFrontBuffer = nullptr;
	}
	if (m_pBackBuffer)
	{
		delete m_pBackBuffer;
		m_pBackBuffer = nullptr;
	}
}

void pipeline::Pipeline::Initialize()
{
	if (m_pShader)			delete m_pShader;
	if (m_pFrontBuffer)		delete m_pFrontBuffer;
	if (m_pBackBuffer)		delete m_pBackBuffer;

	m_pShader = new Shader2D();
	m_pFrontBuffer = new FrameBuffer(m_width, m_height);
	m_pBackBuffer = new FrameBuffer(m_width, m_height);
	m_viewPortMatrix.setViewPort(0, 0, m_width, m_height);
}

void pipeline::Pipeline::clearBuffer(const Math::Vector4D& color, bool depth)
{
	(void)depth;
	m_pBackBuffer->clearColorBuffer(color);
}

void pipeline::Pipeline::setVertexBuffer(const std::vector<Vertex>& vertices)
{
	m_vertices = vertices;
}

void pipeline::Pipeline::setIndexBuffer(const std::vector<unsigned int>& indices)
{
	m_indices = indices;
}

void pipeline::Pipeline::setShaderMode(ShaderMode mode)
{
	if (m_pShader)		delete m_pShader;
	switch (mode)
	{
	case ShaderMode::Simple:
		m_pShader = new Shader2D();
		break;
	case ShaderMode::Gouraud:
		break;
	case ShaderMode::Blinning_Phone:
		break;
	default:
		break;
	}
}

void pipeline::Pipeline::drawIndex(RenderMode mode)
{
	if (m_indices.empty())	return;

	for (int i = 0; i < m_indices.size() / 3; i++)
	{
		Vertex p1, p2, p3;
		p1 = m_vertices[3 * i + 0];
		p2 = m_vertices[3 * i + 1];
		p3 = m_vertices[3 * i + 2];

		Fragment v1, v2, v3;
		v1 = m_pShader->vertexShader(p1);
		v2 = m_pShader->vertexShader(p2);
		v3 = m_pShader->vertexShader(p3);

		/*v1.posVToP = m_viewPortMatrix * v1.posVToP;
		v2.posVToP = m_viewPortMatrix * v2.posVToP;
		v3.posVToP = m_viewPortMatrix * v3.posVToP;*/

		m_pBackBuffer->drawPixel(static_cast<int>(v1.posVToP.x), static_cast<int>(v1.posVToP.y), v1.color);
		m_pBackBuffer->drawPixel(static_cast<int>(v2.posVToP.x), static_cast<int>(v2.posVToP.y), v2.color);
		m_pBackBuffer->drawPixel(static_cast<int>(v3.posVToP.x), static_cast<int>(v3.posVToP.y), v3.color);

		switch (mode)
		{
		case RenderMode::Wireframe:
			bresenham(v1, v2);
			bresenham(v1, v3);
			bresenham(v2, v3);
			break;
		case RenderMode::Fill:
			edgeWalkingFillRasterization(v1, v2, v3);
			break;
		default:
			break;
		}
	}
}

void pipeline::Pipeline::swapBuffer()
{
	FrameBuffer* temp = m_pFrontBuffer;
	m_pFrontBuffer = m_pBackBuffer;
	m_pBackBuffer = temp;
}

pipeline::Fragment pipeline::Pipeline::lerp(const Fragment& n1, const Fragment& n2, float weight)
{
	Fragment result;

	result.posVToP = n1.posVToP.lerp(n2.posVToP, weight);
	result.posMToW = n1.posMToW.lerp(n2.posMToW, weight);
	result.color = n1.color.lerp(n2.color, weight);
	result.normal = n1.normal.lerp(n2.normal, weight);
	result.textcoord = n1.textcoord.lerp(n2.textcoord, weight);

	return result;
}

void pipeline::Pipeline::bresenham(const Fragment& from, const Fragment& to)
{
	int dx = to.posVToP.x - from.posVToP.x;
	int dy = to.posVToP.y - from.posVToP.y;
	int stepX = 1, stepY = 1;

	if (dx < 0)
	{
		stepX = -1;
		dx = -dx;
	}

	if (dy < 0)
	{
		stepY = -1;
		dy = -dy;
	}

	int d2x = 2 * dx, d2y = 2 * dy;
	int d2y_minus_d2x = d2y - d2x;
	int sx = from.posVToP.x;
	int sy = from.posVToP.y;

	Fragment temp;
	if (dy <= dx)
	{
		int flag = d2y - dx;
		for (int i = 0; i <= dx; i++)
		{
			//线性插值
			temp = lerp(from, to, static_cast<float>(i) / dx);
			//片元着色器
			m_pBackBuffer->drawPixel(sx, sy, m_pShader->fragmentShader(temp));
			sx += stepX;
			if (flag <= 0)
			{
				flag += d2y;
			}
			else
			{
				sy += stepY;
				flag += d2y_minus_d2x;
			}
		}
	}
	else
	{
		int flag = d2y - dy;
		for (int i = 0; i <= dy; i++)
		{
			//线性插值
			temp = lerp(from, to, static_cast<float>(i) / dy);
			//片元着色器
			m_pBackBuffer->drawPixel(sx, sy, m_pShader->fragmentShader(temp));
			sy += stepY;
			if (flag <= 0)
			{
				flag += d2x;
			}
			else
			{
				sx += stepX;
				flag -= d2y_minus_d2x;
			}
		}
	}
}

void pipeline::Pipeline::scanLinePerRow(const Fragment& left, const Fragment& right)
{
	Fragment current;
	int length = right.posVToP.x - left.posVToP.x + 1;
	for (int i = 0; i <= length; i++)
	{
		//线性插值
		double weight = static_cast<double>(i) / length;
		current = lerp(left, right, weight);
		current.posVToP.x = left.posVToP.x + i;
		current.posVToP.y = left.posVToP.y;
		//片元着色器
		m_pBackBuffer->drawPixel(current.posVToP.x, current.posVToP.y, m_pShader->fragmentShader(current));
	}
}

void pipeline::Pipeline::rasterTopTriangle(const Fragment& v1, const Fragment& v2, const Fragment& v3)
{
	Fragment left = v2;
	Fragment right = v3;
	Fragment dest = v1;
	Fragment temp, newLeft, newRight;
	if (left.posVToP.x > right.posVToP.x)
	{
		temp = left;
		left = right;
		right = temp;
	}
	int dy = left.posVToP.y - dest.posVToP.y + 1;

	for (int i = 0; i < dy; i++)
	{
		double weight = 0.0;
		if (dy != 0)	weight = static_cast<double>(i) / dy;
		newLeft = lerp(left, dest, weight);
		newRight = lerp(right, dest, weight);
		newLeft.posVToP.y = newRight.posVToP.y = left.posVToP.y - i;
		scanLinePerRow(newLeft, newRight);
	}
}

void pipeline::Pipeline::rasterBottomTriangle(const Fragment& v1, const Fragment& v2, const Fragment& v3)
{
	Fragment left = v1;
	Fragment right = v2;
	Fragment dest = v3;
	Fragment temp, newLeft, newRight;
	if (left.posVToP.x > right.posVToP.x)
	{
		temp = left;
		left = right;
		right = temp;
	}
	int dy = left.posVToP.y - dest.posVToP.y + 1;

	for (int i = 0; i < dy; i++)
	{
		double weight = 0.0;
		if (dy != 0)	weight = static_cast<double>(i) / dy;
		newLeft = lerp(left, dest, weight);
		newRight = lerp(right, dest, weight);
		newLeft.posVToP.y = newRight.posVToP.y = left.posVToP.y + i;
		scanLinePerRow(newLeft, newRight);
	}
}

void pipeline::Pipeline::edgeWalkingFillRasterization(const Fragment& v1, const Fragment& v2, const Fragment& v3)
{
	Fragment temp;
	Fragment target[3] = { v1, v2, v3 };

	if (target[0].posVToP.y > target[1].posVToP.y)
	{
		temp = target[0];
		target[0] = target[1];
		target[1] = temp;
	}
	if (target[0].posVToP.y > target[2].posVToP.y)
	{
		temp = target[0];
		target[0] = target[2];
		target[2] = temp;
	}
	if (target[1].posVToP.y > target[2].posVToP.y)
	{
		temp = target[1];
		target[1] = target[2];
		target[2] = temp;
	}

	// bottom triangle
	if (target[0].posVToP.y == target[1].posVToP.y)
	{
		rasterBottomTriangle(target[0], target[1], target[2]);
	}
	// top triangle
	else if (target[1].posVToP.y == target[2].posVToP.y)
	{
		rasterTopTriangle(target[0], target[1], target[2]);
	}
	// split it.
	else
	{
		double weight = static_cast<double>(target[1].posVToP.y - target[0].posVToP.y) / (target[2].posVToP.y - target[0].posVToP.y);
		Fragment newPoint = lerp(target[0], target[2], weight);
		newPoint.posVToP.y = target[1].posVToP.y;
		rasterTopTriangle(target[0], newPoint, target[1]);
		rasterBottomTriangle(newPoint, target[1], target[2]);
	}
}
