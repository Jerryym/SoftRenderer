#pragma once

namespace Math {

	class Matrix4f
	{
	public:
		float elements[4][4];

	public:
		//Constructors
		Matrix4f();
		Matrix4f(float e0,	float e1,	float e2,	float e3,
				float e4,	float e5,	float e6,	float e7,
				float e8,	float e9,	float e10,	float e11,
				float e12,  float e13,	float e14,	float e15);
		Matrix4f(const Matrix4f& other);
		~Matrix4f();

		//operator
		Matrix4f operator+(const Matrix4f& other);
		Matrix4f operator-(const Matrix4f& other);
		Matrix4f operator*(const Matrix4f& other);
		Matrix4f operator*(const float value);
		Matrix4f operator/(const float value);

		//Identity
		Matrix4f Identity();

		//Inverse
	};
}


