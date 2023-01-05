#pragma once

#include "Vertex.h"
#include "Vector.h"

namespace pipeline {
	/// @brief 着色方式
	enum ShaderMode 
	{
		Simple, 
		Gouraud,			//Gouraud光照模型
		Blinning_Phone		//Blinning_Phone反射模型
	};

	/// @brief 渲染方式
	enum RenderMode
	{
		Wireframe,		//线框模式
		Fill			//默认模式
	};

	/// @brief 着色器类 抽象类
	class Shader
	{
	public:
		Shader() {};
		virtual ~Shader() {};

		/// @brief 顶点着色器
		/// @param vertexObj 顶点对象
		/// @return 返回片元对象
		virtual Fragment vertexShader(const Vertex& vertexObj) = 0;

		/// @brief 片段着色器
		/// @param fragmentObj 片元对象
		/// @return 返回对应片元颜色
		virtual Math::Vector4D fragmentShader(const Fragment& fragmentObj) = 0;
	};
}


