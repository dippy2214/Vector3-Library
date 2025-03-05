#include <iostream>
#include "Vector.h"

int main()
{
	Vector::Vector3 v1(3, 4, 5);
	Vector::Vector3 v2(6, 7, 8);

	v1 = v1 * 3.0f;

	std::cout << "Multiply test: " << v1 << ": expected (9, 12, 15)\n";

	Vector::Vector3 v3 = v1 + v2;

	std::cout << "Addition test: " << v3 << ": expected (15, 19, 23)\n";

	std::cout << "Dot test: " << Vector::Vector3::Dot(v1, v2) << ": expected 258\n";
	std::cout << "Cross test: " << Vector::Vector3::Cross(v1, v2) << ": expected (-9, 18, -9)\n";
	std::cout << "Lerp tests: " << Vector::Vector3::Lerp(v1, v2, 0) << ": expected" << v1 << "\n";
	std::cout << "Lerp tests: " << Vector::Vector3::Lerp(v1, v2, 1) << ": expected" << v2 << "\n";
	std::cout << "Lerp tests: " << Vector::Vector3::Lerp(v1, v2, 0.5f) << ": expected (7.5, 9.5, 11.5)\n";

	std::cout << "Angle test: " << Vector::Vector3::Angle(v1, v2) << ": expected 0.085...\n";
	std::cout << "Distance test: " << Vector::Vector3::Distance(v1, v2) << ": expected 9.110...\n";
	std::cout << "ToString test: " << v1.ToString() << ": expected (9.000000, 12.000000, 15.000000)\n";

	std::cout << "Magnitude test: " << v3.Magnitude() << ": expected 33.391...\n";
	std::cout << "Normalised test: " << v3.Normalised() << ": expected (0.45, 0.57, 0.69)\n";
	v3.Normalize();
	std::cout << "Normalize test: " << v3 << ": expected (0.45, 0.57, 0.69)\n";


	
}