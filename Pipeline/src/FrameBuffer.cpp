#include "FrameBuffer.h"

PipeLine::FrameBuffer::FrameBuffer()
	: m_nWidth(0), m_nHeight(0)
{
	m_colorBuffer.clear();
}

PipeLine::FrameBuffer::FrameBuffer(const int nWidth, const int nHeight)
	: m_nWidth(nWidth), m_nHeight(nHeight)
{
	m_colorBuffer.resize(m_nWidth * m_nHeight * 4, 255);
}

PipeLine::FrameBuffer::~FrameBuffer()
{

}

void PipeLine::FrameBuffer::Initialization(const Vector4D& color)
{
	char red = static_cast<unsigned char> (255 * color.x);
	char green = static_cast<unsigned char> (255 * color.y);
	char blue = static_cast<unsigned char> (255 * color.z);
	char alpht = static_cast<unsigned char> (255 * color.w);

	for (int i = 0; i < m_nHeight; i++)
	{
		for (int j = 0; j < m_nWidth; j++)
		{
			m_colorBuffer[(i * m_nWidth + j) * 4 + 0] = red;
			m_colorBuffer[(i * m_nWidth + j) * 4 + 1] = green;
			m_colorBuffer[(i * m_nWidth + j) * 4 + 2] = blue;
			m_colorBuffer[(i * m_nWidth + j) * 4 + 3] = alpht;
		}
	}
}

bool PipeLine::FrameBuffer::drawPixel(unsigned int x, unsigned int y, const Vector4D& color)
{
	if (x < 0 || x >= (unsigned int)m_nWidth)		return false;
	if (y < 0 || y >= (unsigned int)m_nHeight)	return false;

	char red = static_cast<unsigned char> (255 * color.x);
	char green = static_cast<unsigned char> (255 * color.y);
	char blue = static_cast<unsigned char> (255 * color.z);
	char alpht = static_cast<unsigned char> (255 * color.w);

	unsigned int iIndex = (y * m_nWidth + x) * 4;
	
	m_colorBuffer[iIndex + 0] = red;
	m_colorBuffer[iIndex + 1] = green;
	m_colorBuffer[iIndex + 2] = blue;
	m_colorBuffer[iIndex + 3] = alpht;

	return true;
}
