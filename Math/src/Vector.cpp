#include <math.h>
#include "Vector.h"

//////////////////////////////////////////////////////////////////////////
//	Constructors
//////////////////////////////////////////////////////////////////////////
Math::Vector2D::Vector2D()
	: x(0.0f), y(0.0f)
{

}

Math::Vector2D::~Vector2D()
{

}

Math::Vector2D::Vector2D(float newX, float newY)
	: x(newX), y(newY)
{

}

Math::Vector2D::Vector2D(const Vector2D& ref)
	: x(ref.x), y(ref.y)
{

}

//////////////////////////////////////////////////////////////////////////
//	Set And Get
//////////////////////////////////////////////////////////////////////////
void Math::Vector2D::set(float newX, float newY)
{
	this->x = newX;
	this->y = newY;
}

void Math::Vector2D::setX(float newX)
{
	this->x = newX;
}

void Math::Vector2D::setY(float newY)
{
	this->y = newY;
}

float Math::Vector2D::getX() const
{
	return x;
}

float Math::Vector2D::getY() const
{
	return y;
}

//////////////////////////////////////////////////////////////////////////
//	Normalization
//////////////////////////////////////////////////////////////////////////
void Math::Vector2D::normalize()
{
	float rlength = length();
	if (rlength != 0.0f)
	{
		x /= rlength;
		y /= rlength;
	}
}

Math::Vector2D Math::Vector2D::getNormalize() const
{
	return Vector2D(x / length(), y / length());
}

float Math::Vector2D::length() const
{
	return static_cast<float>(sqrtf(x * x + y * y));
}
