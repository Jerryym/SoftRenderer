#pragma once
#include "Vector.h"

namespace pipeline {
	/// @brief 顶点类
	/// <summary>
	/// 顶点：最基本的集合单位
	/// 顶点中包括的属性：
	///		位置、颜色、纹理、法线
	/// </summary>
	class Vertex
	{
	public:
		Math::Vector4D position;		//位置
		Math::Vector4D color;			//颜色
		Math::Vector2D texcoord;		//纹理
		Math::Vector3D normal;			//法线

	public:
		Vertex();
		Vertex(const Math::Vector4D& pos,
			   const Math::Vector4D& color, 
			   const Math::Vector2D& texture, 
			   const Math::Vector3D& normal);
		Vertex(const Vertex& RefObj);
		void operator=(const Vertex& RefObj);
		~Vertex();
	};

	/// @brief 片元类
	/// <summary>
	///		通过着色器转换后的在屏幕坐标系下的顶点数据
	/// </summary>
	class Fragment
	{
	public:
		Math::Vector4D posMToW;		//模型坐标系下的坐标转换为世界坐标系下的坐标
		Math::Vector4D posVToP;		//视野坐标系下的坐标转换为投影坐标系下的坐标
		Math::Vector4D color;
		Math::Vector2D textcoord;
		Math::Vector3D normal;
		double oneDivZ;				//深度测试指标

	public:
		Fragment();
		Fragment(const Math::Vector4D& PMW,
				 const Math::Vector4D& PVP,
				 const Math::Vector4D& color,
			     const Math::Vector2D& texture,
				 const Math::Vector3D& normal,
				 const double rOneDivZ);
		Fragment(const Fragment& RefObj);
		void operator=(const Fragment& RefObj);
		~Fragment();
	};
}

