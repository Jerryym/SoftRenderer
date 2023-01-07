#include "RenderLoop.h"

RenderLoop::RenderLoop(int width, int height, QObject* parent)
	: QObject(parent), m_nWidth(width), m_nHeight(height), m_nFps(0)
{
	m_bStoped = false;
	m_pPPL = new pipeline::Pipeline(m_nWidth, m_nHeight);
}

RenderLoop::~RenderLoop()
{
	if (m_pPPL)
	{
		delete m_pPPL;
		m_pPPL = nullptr;
	}
}

void RenderLoop::stopIt()
{
	m_bStoped = true;
}

void RenderLoop::loop()
{
	//Pipeline ³õÊ¼»¯
	m_pPPL->Initialize();

	Math::Vector4D v1(100, 100, 0, 0), v2(1200, 200, 0, 0), v3(500, 700, 0, 0);

	pipeline::Mesh* pMesh = new pipeline::Mesh;
	pMesh->triangle(v1, v2, v3);

	m_pPPL->setVertexBuffer(pMesh->vertices);
	m_pPPL->setIndexBuffer(pMesh->indices);

	while (!m_bStoped)
	{
		m_pPPL->clearBuffer(Math::Vector4D(0, 0, 0, 1.0f));
		m_pPPL->drawIndex(pipeline::RenderMode::Fill);
		m_pPPL->swapBuffer();
		emit frameOut(m_pPPL->output());
		m_nFps++;
	}

	delete pMesh;
}
