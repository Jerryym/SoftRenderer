#pragma once
#include "Shader.h"

namespace pipeline {
	/// @brief 2D×ÅÉ«Æ÷
	class Shader2D : public Shader
	{
	public:
		Shader2D();
		virtual ~Shader2D();

		virtual Fragment vertexShader(const Vertex& vertexObj);
		virtual Math::Vector4D fragmentShader(const Fragment& fragmentObj);
	};
}


