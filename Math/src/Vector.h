#pragma once
//v1.0 分别实现各个维度的向量
//v2.0 使用模板类实现

namespace Math {
	//二维
	class Vector2D
	{
	public:
		float x, y;

	public:
		//Constructors
		Vector2D();
		Vector2D(float x, float y);
		Vector2D(const Vector2D& other);
		~Vector2D();

		//normalization
		Vector2D normalization();

		//operator
		Vector2D operator = (const Vector2D& other);
		Vector2D operator + (const Vector2D& other);
		Vector2D operator - (const Vector2D& other);
		Vector2D operator * (const float rhs);
		Vector2D operator / (const float rhs);
	};

	//三维
	class Vector3D
	{
	public:
		float x, y, z;
	public:
		//Constructors
		Vector3D();
		Vector3D(float newX, float newY, float newZ);
		Vector3D(const Vector3D& other);
		~Vector3D();

		//operator
		Vector3D operator = (const Vector3D& other);
		Vector3D operator + (const Vector3D& other);
		Vector3D operator - (const Vector3D& other);
		Vector3D operator * (const float rhs);
		Vector3D operator / (const float rhs);
	};
}


