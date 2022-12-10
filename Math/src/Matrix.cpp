#include "Matrix.h"

using namespace Math;

Matrix4f::Matrix4f()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			elements[i][j] = 0.0f;
		}
	}

}

Matrix4f::Matrix4f(float e0, float e1, float e2, float e3, float e4, float e5, float e6, float e7, float e8, float e9, float e10, float e11, float e12, float e13, float e14, float e15)
	: elements{ e0, e1, e2, e3, 
				e4, e5, e6, e7, 
				e8, e9, e10, e11, 
				e12, e13, e14, e15 }
{
	
}

Matrix4f::Matrix4f(const Matrix4f& other)
	: elements{	other.elements[0][0], other.elements[0][1], other.elements[0][2], other.elements[0][3], 
				other.elements[1][0], other.elements[1][1], other.elements[1][2], other.elements[1][3], 
				other.elements[2][0], other.elements[2][1], other.elements[2][2], other.elements[2][3], 
				other.elements[3][0], other.elements[3][1], other.elements[3][2], other.elements[3][3] }
{
	
}

Matrix4f::~Matrix4f()
{

}

void Matrix4f::set(const float value, int x, int y)
{
	elements[x][y] = value;
}

Matrix4f Matrix4f::operator+(const Matrix4f& other)
{
	Matrix4f result(*this);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result.elements[i][j] += other.elements[i][j];
		}
	}

	return result;
}

Matrix4f Matrix4f::operator-(const Matrix4f& other)
{
	Matrix4f result(*this);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result.elements[i][j] -= other.elements[i][j];
		}
	}

	return result;
}

Matrix4f Matrix4f::operator*(const Matrix4f& other)
{
	Matrix4f result(*this);

	float sum = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			sum = 0;
			for (int k = 0; k < 4; k++)
			{
				sum += result.elements[i][k] * other.elements[i][k];
			}
			result.elements[i][j] = sum;
		}
	}

	return result;
}

Matrix4f Matrix4f::operator*(const float value)
{
	Matrix4f result(*this);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result.elements[i][j] *= value;
		}
	}

	return result;
}

Matrix4f Matrix4f::operator/(const float value)
{
	Matrix4f result(*this);

	if (value == 0.0f)
	{
		return Matrix4f();
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result.elements[i][j] /= value;
		}
	}

	return result;
}

bool Matrix4f::operator==(const Matrix4f& other)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (elements[i][j] != other.elements[i][j])
			{
				return false;
			}
		}
	}

	return true;
}

bool Matrix4f::operator!=(const Matrix4f& other)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (elements[i][j] != other.elements[i][j])
			{
				return true;
			}
		}
	}

	return false;
}

void Matrix4f::operator+=(const Matrix4f& other)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			elements[i][j] += other.elements[i][j];
		}
	}
}

void Matrix4f::operator-=(const Matrix4f& other)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			elements[i][j] -= other.elements[i][j];
		}
	}
}

void Matrix4f::operator*=(const Matrix4f& other)
{
	float sum = 0;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			sum = 0;
			for (int k = 0; k < 4; k++)
			{
				sum += elements[i][k] * other.elements[i][k];
			}
			elements[i][j] = sum;
		}
	}
}

void Matrix4f::operator*=(const float value)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			elements[i][j] *= value;
		}
	}
}

void Matrix4f::operator/=(const float value)
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			elements[i][j] /= value;
		}
	}
}

Matrix4f Matrix4f::Identity()
{
	Matrix4f result;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if (i != j)
				result.elements[i][j] = 0;
			else
				result.elements[i][j] = 1;
		}
	}

	return result;
}

bool Matrix4f::Inverse(Matrix4f& mat)
{
	//行列式为0 矩阵不可逆
	if (determinant() == 0.0f)
	{
		return false;
	}

	Matrix4f InverseMat;

	return true;
}

void Matrix4f::Transopose()
{
	Matrix4f tempMatrix;

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			tempMatrix.elements[i][j] = elements[j][i];
		}
	}

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			elements[i][j] = tempMatrix.elements[i][j];
		}
	}
}

float Matrix4f::determinant()
{
	float rdet = 0.0f;
	rdet = determinant(*this, 4);
	return rdet;
}

float Matrix4f::determinant(Matrix4f& mat, int nSize)
{
	if (nSize == 1)
		return mat.elements[0][0];

	float det = 0.0f;
	Matrix4f subMat;

	for (int i = 0; i < nSize; i++)
	{
		subMat = subMatrix(mat, nSize - 1, i);
		det += mat.elements[0][i] * determinant(subMat, nSize - 1) * ((i % 2) ? -1 : 1);
	}

	return det;
}

Matrix4f Matrix4f::subMatrix(const Matrix4f& mat, int nSize, int nIndex)
{
	Matrix4f subMat;

	for (int i = 0; i < nSize; i++)
	{
		for (int j = 0; j < nSize; j++)
		{
			subMat.elements[i][j] = mat.elements[i + 1][j + (j >= nIndex)];
		}
	}

	return subMat;
}
