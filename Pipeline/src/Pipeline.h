#pragma once

#include "Shader2D.h"
#include "FrameBuffer.h"
#include "Matrix.h"

namespace pipeline {
	/// @brief 管线类
	class Pipeline
	{
	public:
		Pipeline();
		Pipeline(int width, int height);
		~Pipeline();

		/// @brief 初始化
		void Initialize();

		/// @brief 清除缓冲区
		/// @param color 
		/// @param depth 是否打开深度
		void clearBuffer(const Math::Vector4D& color, bool depth = false);

		void setVertexBuffer(const std::vector<Vertex>& vertices);
		void setIndexBuffer(const std::vector<unsigned int>& indices);

		void setShaderMode(ShaderMode mode = ShaderMode::Simple);
		void drawIndex(RenderMode mode = RenderMode::Fill);
		void swapBuffer();

		Fragment lerp(const Fragment& n1, const Fragment& n2, float width);

		unsigned char* output() { return m_pFrontBuffer->getColorBuffer(); }

	protected:
		/// @brief bresenham直线光栅化
		/// @param from 
		/// @param to 
		void bresenham(const Fragment& from, const Fragment& to);

		/// @brief 
		/// @param left 
		/// @param right 
		void scanLinePerRow(const Fragment& left, const Fragment& right);

		void rasterTopTriangle(const Fragment& v1, const Fragment& v2, const Fragment& v3);

		void rasterBottomTriangle(const Fragment& v1, const Fragment& v2, const Fragment& v3);

		void edgeWalkingFillRasterization(const Fragment& v1, const Fragment& v2, const Fragment& v3);

	private:
		int m_width;
		int m_height;
		Shader* m_pShader;
		FrameBuffer* m_pFrontBuffer;			//上一帧渲染缓冲
		FrameBuffer* m_pBackBuffer;				//下一帧渲染缓冲
		std::vector<Vertex> m_vertices;			//顶点数组对象
		std::vector<unsigned int> m_indices;	//索引数组对象
		Math::Matrix4f m_viewPortMatrix;		//视口矩阵
	};
}


