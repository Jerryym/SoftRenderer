#include <iostream>
#include "Vector.h"

int main()
{
	Math::Vector2D vec2d(1.2f, 2.2f);
	std::cout << vec2d.x << ", " << vec2d.y << std::endl;

	return 0;
}