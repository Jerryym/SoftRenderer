#include <iostream>
#include "Vector.h"

int main()
{
	//testing code
	{
		//Vector2D
		Math::Vector2D vec2d(1.2f, 2.2f);
		std::cout << vec2d.x << ", " << vec2d.y << std::endl;

		//Vector3D
		Math::Vector3D vec3d(1.2f, 2.2f, 0.0);
		std::cout << vec3d.x << ", " << vec3d.y << ", "<< vec3d.z << std::endl;
	}

	return 0;
}