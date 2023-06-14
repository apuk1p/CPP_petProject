#pragma once

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <type_traits>

template<typename Type>
class Vector3
{
public:
	Type x, y, z;

	Vector3();
	Vector3(Type x, Type y, Type z);
	~Vector3();

	Vector3(const Vector3& vec);
	Vector3(Vector3&& vec) noexcept;

	Vector3& operator=(const Vector3& vec);
	Vector3& operator=(Vector3&& vec) noexcept;

	Vector3& operator-=(const Vector3& vec);
	Vector3& operator+=(const Vector3& vec);

	Vector3& operator*=(const Type value);
	Vector3& operator/=(const Type value);

	void moveSwap(Vector3& vecF, Vector3& vecS);

	float magnitude();
	float magnitude(const Vector3<Type>& vec);

	Vector3& normalize();
	Vector3& crossProduct(const Vector3& vecF, const Vector3& vecS);
	float dotProduct(const Vector3& vecF, const Vector3& vecS);

};

template<typename Type>
Vector3<Type>::Vector3() : x(0), y(0), z(0)
{
	static_assert(!std::is_integral_v<Type>, "Type shouldn't be integer");
}

template<typename Type>
Vector3<Type>::Vector3(Type x, Type y, Type z)
{
	if constexpr (std::is_floating_point_v<Type>)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}
	else
	{
		static_assert(!std::is_integral_v<Type>, "Type shouldn't be integer" );
	}
}

template<typename Type>
Vector3<Type>::~Vector3() {}

template<typename Type>
Vector3<Type>::Vector3(const Vector3<Type>& vec)
{
	x = vec.x;
	y = vec.y;
	z = vec.z;
}

template<typename Type>
Vector3<Type>::Vector3(Vector3<Type>&& vec) noexcept : x(0),y(0),z(0)
{
	moveSwap(*this, vec);
}

template<typename Type>
Vector3<Type>& Vector3<Type>::operator=(const Vector3<Type>& vec)
{
	if (this != &vec)
	{
		x = vec.x;
		y = vec.y;
		z = vec.z;
	}
	return *this;
}

template<typename Type>
Vector3<Type>& Vector3<Type>::operator=(Vector3<Type>&& vec) noexcept
{
	if (this != &vec)
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
		moveSwap(*this, vec);
	}
	return *this;
}

template<typename Type>
Vector3<Type> operator-(Vector3<Type> lhs, const Vector3<Type>& rhs)
{
	return lhs -= rhs;
}

template<typename Type>
Vector3<Type>& Vector3<Type>::operator-=(const Vector3<Type>& vec)
{
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
	return *this;
}

template<typename Type>
Vector3<Type> operator+(Vector3<Type> lhs, const Vector3<Type>& rhs)
{
	return lhs += rhs;
}

template<typename Type>
Vector3<Type>& Vector3<Type>::operator+=(const Vector3<Type>& vec)
{
	x += vec.x;
	y += vec.y;
	z += vec.z;
	return *this;
}

template<typename Type>
Vector3<Type> operator*(Vector3<Type> vec, const Type value)
{
	return vec *= value;
}

template<typename Type>
Vector3<Type>& Vector3<Type>::operator*=(const Type value)
{
	x *= value;
	y *= value;
	z *= value;
	return *this;
}

template<typename Type>
Vector3<Type> operator/(Vector3<Type> vec, const Type value)
{
	_ASSERT(value != 0);
	return vec /= value;
}

template<typename Type>
Vector3<Type>& Vector3<Type>::operator/=(const Type value)
{
	/*if (value == 0)
	{
		throw std::domain_error("Divide by zero exception!");
	}*/
	_ASSERT(value != 0);
	x /= value;
	y /= value;
	z /= value;
	return *this;
}

template<typename Type>
void Vector3<Type>::moveSwap(Vector3<Type>& vecF, Vector3<Type>& vecS)
{
	std::swap(vecF.x, vecS.x);
	std::swap(vecF.y, vecS.y);
	std::swap(vecF.z, vecS.z);
}

template<typename Type>
float Vector3<Type>::magnitude()
{
	float length = std::sqrtf((x * x) + (y * y) + (z * z)); 
	return length;
}

template<typename Type>
float Vector3<Type>::magnitude(const Vector3<Type>& vec)
{
	float length = std::sqrtf((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
	return length;
}

template<typename Type>
Vector3<Type>& Vector3<Type>::normalize()
{
	float length = this->magnitude();
	x /= length;
	y /= length;
	z /= length;

	return *this;
}

template<typename Type>
Vector3<Type>& Vector3<Type>::crossProduct(const Vector3& vecF, const Vector3& vecS)
{
	x = vecF.y * vecS.z - vecF.z * vecS.y;
	y = vecF.z * vecS.x - vecF.x * vecS.z;
	z = vecF.x * vecS.y - vecF.y * vecS.x;

	return *this;
}

template<typename Type>
float Vector3<Type>::dotProduct(const Vector3& vecF, const Vector3& vecS)
{
	float dot;
	float mulVec = vecF.x * vecS.x + vecF.y * vecS.y + vecF.z * vecS.z;
	if (mulVec >= -1 && mulVec <= 1)
	{
		dot = mulVec;
		return dot;
	}
	else
	{
		float mulMgnt = magnitude(vecF) * magnitude(vecS);
		dot = mulVec / mulMgnt;
		return dot;
	}
}