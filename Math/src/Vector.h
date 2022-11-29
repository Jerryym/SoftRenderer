#pragma once

namespace Math {
	class Vector2D
	{
	public:
		float x, y;

	public:
		//Constructors
		Vector2D();
		Vector2D(float newX, float newY);
		Vector2D(const Vector2D& ref);
		~Vector2D();

		//Set
		void set(float newX, float newY);
		void setX(float newX);
		void setY(float newY);

		//Get
		float getX() const;
		float getY() const;

		//Normalization
		void normalize();
		Vector2D getNormalize() const;

		float length() const;
	};
}


