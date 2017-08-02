#include "vec3.h"
#include "vec2.h"
#include "angle.h"

#include <iostream>

int main()
{
	geo::vec3 a;
	geo::vec3 b = 5 * a - 3;

	geo::angle angle(geo::toRadian(90));

	geo::vec2 vec(1, 0);

	for (int i = 0; i < 5; i++)
	{
		std::cout << "( " << vec.x << ", " << vec.y << " )" << std::endl;
		vec *= angle;
	}

	std::cin.get();

	return 0;
}