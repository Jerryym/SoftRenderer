#pragma once

#include <QObject>
#include "Pipeline.h"
#include "Mesh.h"

class RenderLoop  : public QObject
{
	Q_OBJECT

public:
	explicit RenderLoop(int width, int height, QObject* parent = nullptr);
	~RenderLoop();

	void stopIt();

	void setFpsZero() { m_nFps = 0; }

	int getFps() { return m_nFps; }

signals:
	void frameOut(unsigned char* image);

public slots:
	void loop();

private:
	int m_nWidth;
	int m_nHeight;
	int m_nFps;
	bool m_bStoped;
	pipeline::Pipeline* m_pPPL;
};
