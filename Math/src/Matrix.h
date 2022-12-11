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

		//set
		void set(const float value, int x, int y);

		//operator
		Matrix4f operator+(const Matrix4f& other);
		Matrix4f operator-(const Matrix4f& other);
		Matrix4f operator*(const Matrix4f& other);
		Matrix4f operator*(const float value);
		Matrix4f operator/(const float value);

		bool operator == (const Matrix4f& other);
		bool operator != (const Matrix4f& other);

		void operator += (const Matrix4f& other);
		void operator -= (const Matrix4f& other);
		void operator *= (const Matrix4f& other);
		void operator *= (const float value);
		void operator /= (const float value);

		//Identity
		static Matrix4f Identity();

		//Inverse¡¢ Determinant¡¢Transopose
		float determinant();
		bool Inverse(Matrix4f& mat);
		void Transopose();

		//cofactor matrix
		bool cofactorMatrix(Matrix4f &mat);

	protected:
		static float determinant(const Matrix4f& mat, int nSize = 4);
		static float determinantofCofactorMat(const Matrix4f& mat, int iRow, int iCol, int nSize = 4);
		static Matrix4f subMatrix(const Matrix4f& mat, int nSize, int nIndex);
		static Matrix4f subMatrix(const Matrix4f& mat, int nSize, int iRow, int iCol);
	};
}


