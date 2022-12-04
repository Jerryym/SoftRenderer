#include <math.h>
#include "Vector.h"

using namespace Math;

//////////////////////////////////////////////////////////////////////////
/// Vector2D
Vector2D::Vector2D()
	: x(0.0f), y(0.0f)
{

}

Vector2D::~Vector2D()
{

}

Vector2D::Vector2D(float x, float y)
	: x(x), y(y)
{

}

Vector2D::Vector2D(const Vector2D& other)
	: x(other.x), y(other.y)
{

}

Vector2D Vector2D::operator=(const Vector2D& other)
{
	if (this == &other)		return *this;

	this->x = other.x;
	this->y = other.y;
	return *this;
}

Vector2D Vector2D::operator+(const Vector2D& other)
{
	this->x += other.x;
	this->y += other.y;
	return *this;
}

Vector2D Vector2D::operator-(const Vector2D& other)
{
	this->x -= other.x;
	this->y -= other.y;
	return *this;
}

Vector2D Vector2D::operator*(const float rhs)
{
	this->x *= rhs;
	this->y *= rhs;
	return *this;
}

Vector2D Vector2D::operator/(const float rhs)
{
	if (rhs == 0)
		return Vector2D(0.0f, 0.0f);

	this->x /= rhs;
	this->y /= rhs;
	return *this;
}

//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// Vector3D

Vector3D::Vector3D()
	: x(0.0f), y(0.0f), z(0.0f)
{

}

Vector3D::Vector3D(float newX, float newY, float newZ)
	: x(newX), y(newY), z(newZ)
{

}

Vector3D::Vector3D(const Vector3D& other)
	: x(other.x), y(other.y), z(other.z)
{

}

Vector3D::~Vector3D()
{

}

Vector3D Vector3D::operator=(const Vector3D& other)
{
	if (this == &other)		return *this;

	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
	return *this;
}

Vector3D Vector3D::operator+(const Vector3D& other)
{
	this->x += other.x;
	this->y += other.y;
	return *this;
}

Vector3D Vector3D::operator-(const Vector3D& other)
{
	this->x -= other.x;
	this->y -= other.y;
	return *this;
}

Vector3D Vector3D::operator*(const float rhs)
{
	this->x *= rhs;
	this->y *= rhs;
	return *this;
}

Vector3D Vector3D::operator/(const float rhs)
{
	if (rhs == 0)
		return Vector3D(0.0f, 0.0f, 0.0f);

	this->x /= rhs;
	this->y /= rhs;
	return *this;
}
