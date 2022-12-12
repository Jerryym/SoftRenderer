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

float Vector2D::getLength() const
{
	return sqrtf(x * x + y * y);
}

Vector2D Vector2D::normalized()
{
	float rModule = sqrtf(x * x + y * y);

	if (rModule == 0)	
		return Vector2D(0.0f, 0.0f);

	return Vector2D(x / rModule, y / rModule);
}

float Vector2D::dot(const Vector2D& vec) const
{
	return (x * vec.x + y * vec.y);
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

bool Vector2D::operator==(const Vector2D& rhs)
{
	if (x == rhs.x && y == rhs.y)
	{
		return true;
	}

	return false;
}

bool Vector2D::operator!=(const Vector2D& rhs)
{
	return !((*this) == rhs);
}

void Vector2D::operator+=(const Vector2D& rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
}

void Vector2D::operator-=(const Vector2D& rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
}

void Vector2D::operator*=(const float rhs)
{
	this->x *= rhs;
	this->y *= rhs;
}

void Vector2D::operator/=(const float rhs)
{
	if (rhs == 0)
	{
		this->x = 0.0f;
		this->y = 0.0f;
	}
	else
	{
		this->x /= rhs;
		this->y /= rhs;
	}
}

Vector2D Vector2D::operator-() const
{
	return Vector2D(-x, -y);
}

Vector2D Vector2D::operator+() const
{
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

float Vector3D::getLength() const
{
	return sqrtf(x * x + y * y + z * z);
}

Vector3D Vector3D::normalized()
{
	float rModule = sqrtf(x * x + y * y + z * z);

	if (rModule == 0)
		return Vector3D(0.0f, 0.0f, 0.0f);

	return Vector3D(x / rModule, y / rModule, z / rModule);
}

float Math::Vector3D::dot(const Vector3D& vec) const
{
	return (x * vec.x + y * vec.y + z * vec.z);
}

Vector3D Math::Vector3D::product(const Vector3D& vec) const
{
	Vector3D res;
	res.x = y * vec.z - z * vec.y;
	res.y = z * vec.x - x * vec.z;
	res.z = x * vec.y - y * vec.x;

	return res;
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
	this->z += other.z;
	return *this;
}

Vector3D Vector3D::operator-(const Vector3D& other)
{
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
	return *this;
}

Vector3D Vector3D::operator*(const float rhs)
{
	this->x *= rhs;
	this->y *= rhs;
	this->z *= rhs;
	return *this;
}

Vector3D Vector3D::operator/(const float rhs)
{
	if (rhs == 0)
		return Vector3D(0.0f, 0.0f, 0.0f);

	this->x /= rhs;
	this->y /= rhs;
	this->z /= rhs;
	return *this;
}

bool Vector3D::operator==(const Vector3D& rhs)
{
	if (x == rhs.x && y == rhs.y && z == rhs.z)
	{
		return true;
	}

	return false;
}

bool Vector3D::operator!=(const Vector3D& rhs)
{
	return !((*this) == rhs);
}

void Vector3D::operator+=(const Vector3D& rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;
}

void Vector3D::operator-=(const Vector3D& rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;
}

void Vector3D::operator*=(const float rhs)
{
	this->x *= rhs;
	this->y *= rhs;
	this->z *= rhs;
}

void Vector3D::operator/=(const float rhs)
{
	if (rhs == 0)
	{
		this->x = 0.0f;
		this->y = 0.0f;
		this->z = 0.0f;
	}
	else
	{
		this->x /= rhs;
		this->y /= rhs;
		this->z /= rhs;
	}
}

Vector3D Vector3D::operator-() const
{
	return Vector3D(-x, -y, -z);
}

Vector3D Vector3D::operator+() const
{
	return *this;
}
//////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////////////////////////////////////
// Vector4D
Vector4D::Vector4D()
	: x(0.0f), y(0.0f), z(0.0f), w(0.0f)
{

}

Vector4D::Vector4D(float newX, float newY, float newZ, float newW)
	: x(newX), y(newY), z(newZ), w(newW)
{

}

Vector4D::Vector4D(const Vector4D& other)
	: x(other.x), y(other.y), z(other.z), w(other.w)
{

}

Vector4D::~Vector4D()
{

}

float Vector4D::getLength() const
{
	return sqrtf(x * x + y * y + z * z + w * w);
}

Vector4D Vector4D::normalized()
{
	float rModule = sqrtf(x * x + y * y + z * z + w * w);

	if (rModule == 0)
		return Vector4D(0.0f, 0.0f, 0.0f, 0.0f);

	return Vector4D(x / rModule, y / rModule, z / rModule, w / rModule);
}

float Math::Vector4D::dot(const Vector4D& vec) const
{
	return (x * vec.x + y * vec.y + z * vec.z + w * vec.w);
}

Vector4D Vector4D::operator=(const Vector4D& other)
{
	if (this == &other)		return *this;

	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
	this->w = other.w;
	return *this;
}

Vector4D Vector4D::operator+(const Vector4D& other)
{
	this->x += other.x;
	this->y += other.y;
	this->z += other.z;
	this->w += other.w;

	return *this;
}

Vector4D Vector4D::operator-(const Vector4D& other)
{
	this->x -= other.x;
	this->y -= other.y;
	this->z -= other.z;
	this->w -= other.w;

	return *this;
}

Vector4D Vector4D::operator*(const float rhs)
{
	this->x *= rhs;
	this->y *= rhs;
	this->z *= rhs;
	this->w *= rhs;

	return *this;
}

Vector4D Vector4D::operator/(const float rhs)
{
	if (rhs == 0)
		return Vector4D(0.0f, 0.0f, 0.0f, 0.0f);

	this->x /= rhs;
	this->y /= rhs;
	this->z /= rhs;
	this->w /= rhs;

	return *this;
}

bool Vector4D::operator==(const Vector4D& rhs)
{
	if (x == rhs.x && y == rhs.y && z == rhs.z && w == rhs.w)
	{
		return true;
	}

	return false;
}

bool Vector4D::operator!=(const Vector4D& rhs)
{
	return !((*this) == rhs);
}

void Vector4D::operator+=(const Vector4D& rhs)
{
	this->x += rhs.x;
	this->y += rhs.y;
	this->z += rhs.z;
	this->w += rhs.w;
}

void Vector4D::operator-=(const Vector4D& rhs)
{
	this->x -= rhs.x;
	this->y -= rhs.y;
	this->z -= rhs.z;
	this->w -= rhs.w;
}

void Vector4D::operator*=(const float rhs)
{
	this->x *= rhs;
	this->y *= rhs;
	this->z *= rhs;
	this->w *= rhs;
}

void Vector4D::operator/=(const float rhs)
{
	if (rhs == 0)
	{
		this->x = 0.0f;
		this->y = 0.0f;
		this->z = 0.0f;
	}
	else
	{
		this->x /= rhs;
		this->y /= rhs;
		this->z /= rhs;
	}
}

Vector4D Vector4D::operator-() const
{
	return Vector4D(-x, -y, -z, -w);
}

Vector4D Vector4D::operator+() const
{
	return *this;
}
//////////////////////////////////////////////////////////////////////////