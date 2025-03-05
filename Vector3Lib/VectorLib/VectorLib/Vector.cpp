#include "pch.h"
#include "Vector.h"
#include <string>
#include <math.h>

namespace Vector
{

	Vector3 forward = Vector3(0, 0, 1);
	Vector3 back = Vector3(0, 0, -1);
	Vector3 up = Vector3(0, 1, 0);
	Vector3 down = Vector3(0, -1, 0);
	Vector3 right = Vector3(1, 0, 0);
	Vector3 left = Vector3(-1, 0, 0);
	Vector3 one = Vector3(1, 1, 1);
	Vector3 zero = Vector3(0, 0, 0);

	Vector3::Vector3()
	{
		x = 0;
		y = 0;
		z = 0;
	}

	Vector3::Vector3(float nx, float ny, float nz)
	{
		x = nx;
		y = ny;
		z = nz;
	}

	Vector3 Vector3::operator+(const Vector3 v1)
	{
		Vector3 result(x, y, z);
		result.x += v1.x;
		result.y += v1.y;
		result.z += v1.z;
		return result;
	}

	Vector3 Vector3::operator-(const Vector3 v1)
	{
		Vector3 result(x, y, z);
		result.x -= v1.x;
		result.y -= v1.y;
		result.z -= v1.z;
		return result;
	}

	Vector3 Vector3::operator*(const float f)
	{
		return Vector3(x * f, y * f, z * f);
	}

	Vector3 Vector3::operator/(const float f)
	{
		return Vector3(x / f, y / f, z / f);
	}

	void Vector3::operator=(const Vector3 v1)
	{
		x = v1.x;
		y = v1.y;
		z = v1.z;
	}

	bool Vector3::operator==(const Vector3 v1)
	{
		if (x == v1.x && y == v1.y && z == v1.z)
		{
			return true;
		}
		return false;
	}

	bool Vector3::operator!=(const Vector3 v1)
	{
		if (x != v1.x && y != v1.y && z != v1.z)
		{
			return true;
		}
		return false;
	}

	std::ostream& operator<<(std::ostream& os, const Vector3 v1)
	{
		os << "(" << v1.x << ", " << v1.y << ", " << v1.z << ")";
		return os;
	}

	float Vector3::Magnitude()
	{
		float mag = fabs(sqrtf(pow(x, 2) + pow(y, 2) + pow(z, 2)));
		return mag;
	}

	Vector3 Vector3::Normalised()
	{
		float mag = this->Magnitude();
		return Vector3(x / mag, y / mag, z / mag);
	}

	void Vector3::Normalize()
	{
		Vector3 normalised = this->Normalised();
		x = normalised.x;
		y = normalised.y;
		z = normalised.z;
	}

	std::string Vector3::ToString()
	{
		std::string output;
		output += "(";
		output += std::to_string(x);
		output += ", ";
		output += std::to_string(y);
		output += ", ";
		output += std::to_string(z);
		output += ")";
		return output;
	}

	float Vector3::Dot(Vector3 v1, Vector3 v2)
	{
		float dot = 0;
		dot += v1.x * v2.x;
		dot += v1.y * v2.y;
		dot += v1.z * v2.z;
		return dot;
	}

	Vector3 Vector3::Cross(Vector3 v1, Vector3 v2)
	{
		float x = (v1.y * v2.z) - (v1.z * v2.y);
		float y = (v1.z * v2.x) - (v1.x * v2.z);
		float z = (v1.x * v2.y) - (v1.y * v2.x);
		return Vector3(x, y, z);
	}

	float Vector3::Angle(Vector3 v1, Vector3 v2)
	{
		float angle = acosf(Vector3::Dot(v1, v2) / (v1.Magnitude() * v2.Magnitude()));
		return angle;
	}

	float Vector3::Distance(Vector3 v1, Vector3 v2)
	{
		float dist = sqrtf(powf((v1.x - v2.x), 2) + powf((v1.y - v2.y), 2) + powf((v1.z - v2.z), 2));
		return dist;
	}

	Vector3 Vector3::Lerp(Vector3 v1, Vector3 v2, float t)
	{
		return v1 + (v2 - v1) * t;
	}

}