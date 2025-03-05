#pragma once
#include <iostream>

namespace Vector
{
	class Vector3
	{
	public:
		Vector3();
		Vector3(float nx, float ny, float nz);

		static Vector3 forward;
		static Vector3 back;
		static Vector3 up;
		static Vector3 down;
		static Vector3 right;
		static Vector3 left;
		static Vector3 one;
		static Vector3 zero;

		Vector3 operator+(const Vector3 v1);
		Vector3 operator-(const Vector3 v1);
		Vector3 operator*(const float f);
		Vector3 operator/(const float f);
		void operator=(const Vector3 v1);
		bool operator==(const Vector3 v1);
		bool operator!=(const Vector3 v1);
		friend std::ostream& operator<<(std::ostream& os, const Vector3 v1);

		float Magnitude();
		Vector3 Normalised();
		void Normalize();
		std::string ToString();

		static float Dot(Vector3 v1, Vector3 v2);
		static Vector3 Cross(Vector3 v1, Vector3 v2);
		static float Angle(Vector3 v1, Vector3 v2);
		static float Distance(Vector3 v1, Vector3 v2);
		static Vector3 Lerp(Vector3 v1, Vector3 v2, float t);

		float x;
		float y;
		float z;
	};
}
