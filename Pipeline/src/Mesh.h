#pragma once

#include <iostream>
#include <vector>
#include "Vertex.h"
#include "Vector.h"

namespace pipeline {
	/// @brief 网格类
	class Mesh
	{
	public:
		std::vector<Vertex> vertices;		//顶点数组
		std::vector<unsigned int> indices;			//索引数组

	public:
		Mesh();
		Mesh(const Mesh& RefObj);
		~Mesh();

		Mesh& operator=(const Mesh& RefObj);

		/// @brief 设置顶点数组
		/// @param VO		Vertex Object = 顶点对象 
		/// @param Count	网格包含的顶点个数
		void setVertices(Vertex* VO, int Count);

		/// @brief	设置索引数组
		/// @param IO		Index Object = 索引对象
		/// @param Count	网格包含的顶点索引个数
		void setIndices(unsigned int* IO, int Count);

		/// @brief	三角化
		/// @param pos1 三角形第一个顶点坐标
		/// @param pos2 三角形第二个顶点坐标
		/// @param pos3 三角形第三个顶点坐标
		void triangle(const Math::Vector4D& pos1, const Math::Vector4D& pos2, const Math::Vector4D& pos3);
	};
}

