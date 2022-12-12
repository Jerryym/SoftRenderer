#include <iostream>
#include "Vector.h"
#include "Matrix.h"
#include "MathFunctions.h"

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

		//Matrix4f
		Math::Matrix4f mat(5, 2, 0, 0,
			2, 1, 0, 0,
			0, 0, 8, 3,
			0, 0, 5, 2);

		std::cout << "det(mat): " << mat.determinant() << std::endl;

		Math::Matrix4f InverseMat;
		mat.Inverse(InverseMat);
		std::cout << "InverseMat:" << std::endl;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				std::cout << InverseMat.elements[i][j] << " ";
			}
			std::cout << std::endl;
		}

		mat.translation(vec3d);
		std::cout << "Translation:" << std::endl;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				std::cout << mat.elements[i][j] << " ";
			}
			std::cout << std::endl;
		}

		mat.rotationX(D_TO_R(60));
		std::cout << "RotationX:" << std::endl;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				std::cout << mat.elements[i][j] << " ";
			}
			std::cout << std::endl;
		}

		mat.rotationY(D_TO_R(60));
		std::cout << "RotationY:" << std::endl;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				std::cout << mat.elements[i][j] << " ";
			}
			std::cout << std::endl;
		}

		mat.rotationZ(D_TO_R(60));
		std::cout << "RotationZ:" << std::endl;
		for (int i = 0; i < 4; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				std::cout << mat.elements[i][j] << " ";
			}
			std::cout << std::endl;
		}
	}

	return 0;
}