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

void Math::Vector2D::operator=(const Vector2D& other)
{
	x = other.x;
	y = other.y;
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

Vector2D Vector2D::operator=(const Vector2D& other) const
{
	if (this == &other)		return *this;

	return Vector2D(other.x, other.y);
}

Vector2D Vector2D::operator+(const Vector2D& other) const
{
	return Vector2D(x + other.x, y + other.y);
}

Vector2D Vector2D::operator-(const Vector2D& other) const
{
	return Vector2D(x - other.x, y - other.y);
}

Vector2D Vector2D::operator*(const float rhs) const
{
	return Vector2D(x * rhs, y * rhs);
}

Vector2D Vector2D::operator/(const float rhs) const
{
	if (rhs == 0)
		return Vector2D(0.0f, 0.0f);

	return Vector2D(x / rhs, y / rhs);
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

Vector2D Vector2D::lerp(const Vector2D& v2, const float factor) const
{
	Vector2D result;
	result = (*this) * (1.0f - factor) + v2 * factor;

	return result;
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

void Math::Vector3D::operator=(const Vector3D& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
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

float Vector3D::dot(const Vector3D& vec) const
{
	return (x * vec.x + y * vec.y + z * vec.z);
}

Vector3D Vector3D::product(const Vector3D& vec) const
{
	Vector3D res;
	res.x = y * vec.z - z * vec.y;
	res.y = z * vec.x - x * vec.z;
	res.z = x * vec.y - y * vec.x;

	return res;
}

Vector3D Vector3D::operator=(const Vector3D& other)	const
{
	if (this == &other)		return *this;

	return Vector3D(other.x, other.y, other.z);
}

Vector3D Vector3D::operator+(const Vector3D& other)	const
{
	return Vector3D(x + other.x, y + other.y, z + other.z);
}

Vector3D Vector3D::operator-(const Vector3D& other)	const
{
	return Vector3D(x - other.x, y - other.y, z - other.z);
}

Vector3D Vector3D::operator*(const float rhs) const
{
	return Vector3D(x * rhs, y * rhs, z * rhs);
}

Vector3D Vector3D::operator/(const float rhs) const
{
	if (rhs == 0)
		return Vector3D(0.0f, 0.0f, 0.0f);

	return Vector3D(x / rhs, y / rhs, z / rhs);
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
Vector3D Math::Vector3D::lerp(const Vector3D& v2, const float factor) const
{
	Vector3D result;
	result = (*this) * (1.0f - factor) + v2 * factor;

	return result;
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

void Math::Vector4D::operator=(const Vector4D& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
	w = other.w;
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

float Vector4D::dot(const Vector4D& vec) const
{
	return (x * vec.x + y * vec.y + z * vec.z + w * vec.w);
}

Vector4D Vector4D::operator=(const Vector4D& other) const
{
	if (this == &other)		return *this;

	return Vector4D(other.x, other.y, other.z, other.w);
}

Vector4D Vector4D::operator+(const Vector4D& other) const
{
	return Vector4D(x + other.x, y + other.y, z + other.z, w + other.w);
}

Vector4D Vector4D::operator-(const Vector4D& other) const
{
	return Vector4D(x - other.x, y - other.y, z - other.z, w - other.w);
}

Vector4D Vector4D::operator*(const float rhs) const
{
	return Vector4D(x * rhs, y * rhs, z * rhs, w * rhs);
}

Vector4D Vector4D::operator/(const float rhs) const
{
	if (rhs == 0)
		return Vector4D(0.0f, 0.0f, 0.0f, 0.0f);
	
	return Vector4D(x / rhs, y / rhs, z / rhs, w / rhs);
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

Vector4D Vector4D::lerp(const Vector4D& v2, const float factor) const
{
	Vector4D result;
	result = (*this) * (1.0f - factor) + v2 * factor;

	return result;
}

void Math::Vector4D::printVec()
{
	std::cout << "Vec4 = (" << x <<" " << y << " " << z << " " << w << ")" << std::endl;
}
//////////////////////////////////////////////////////////////////////////