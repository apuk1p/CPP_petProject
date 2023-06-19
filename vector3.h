#pragma once

#include <iostream>
#include <stdexcept>
#include <algorithm>
#include <cmath>
#include <type_traits>

template<typename Type>
class vector3
{
public:
	Type x, y, z;

	vector3();
	vector3(Type x, Type y, Type z);
	~vector3();

	vector3(const vector3& vec);
	vector3(vector3&& vec) noexcept;

	vector3& operator=(const vector3& vec);
	vector3& operator=(vector3&& vec) noexcept;

	vector3& operator-=(const vector3& vec);
	vector3& operator+=(const vector3& vec);

	vector3& operator*=(const Type value);
	vector3& operator/=(const Type value);

	void moveSwap(vector3& vecF, vector3& vecS);

	float magnitude();
	float magnitude(const vector3<Type>& vec);

	vector3& normalize();
	vector3& crossProduct(const vector3& vecF, const vector3& vecS);
	float dotProduct(const vector3& vecF, const vector3& vecS);

};

template<typename Type>
vector3<Type>::vector3() : x(0), y(0), z(0)
{
	static_assert(!std::is_integral_v<Type>, "Type shouldn't be integer");
}

template<typename Type>
vector3<Type>::vector3(Type x, Type y, Type z)
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
vector3<Type>::~vector3() {}

template<typename Type>
vector3<Type>::vector3(const vector3<Type>& vec)
{
	x = vec.x;
	y = vec.y;
	z = vec.z;
}

template<typename Type>
vector3<Type>::vector3(vector3<Type>&& vec) noexcept : x(0),y(0),z(0)
{
	moveSwap(*this, vec);
}

template<typename Type>
vector3<Type>& vector3<Type>::operator=(const vector3<Type>& vec)
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
vector3<Type>& vector3<Type>::operator=(vector3<Type>&& vec) noexcept
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
vector3<Type> operator-(vector3<Type> lhs, const vector3<Type>& rhs)
{
	vector3 newVec(lhs);
	return newVec -= rhs;
}

template<typename Type>
vector3<Type>& vector3<Type>::operator-=(const vector3<Type>& vec)
{
	x -= vec.x;
	y -= vec.y;
	z -= vec.z;
	return *this;
}

template<typename Type>
vector3<Type> operator+(vector3<Type> lhs, const vector3<Type>& rhs)
{
	vector3 newVec(lhs);
	return newVec += rhs;
}

template<typename Type>
vector3<Type>& vector3<Type>::operator+=(const vector3<Type>& vec)
{
	x += vec.x;
	y += vec.y;
	z += vec.z;
	return *this;
}

template<typename Type>
vector3<Type> operator*(vector3<Type> vec, const Type value)
{
	vector3 newVec(vec);
	return newVec *= value;
}

template<typename Type>
vector3<Type>& vector3<Type>::operator*=(const Type value)
{
	x *= value;
	y *= value;
	z *= value;
	return *this;
}

template<typename Type>
vector3<Type> operator/(vector3<Type> vec, const Type value)
{
	_ASSERT(value != 0);
	/*if (value == 0)
	{
		throw std::domain_error("Divide by zero exception!");
	}*/
	vector3 newVec(vec);
	return newVec /= value;
}

template<typename Type>
vector3<Type>& vector3<Type>::operator/=(const Type value)
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
void vector3<Type>::moveSwap(vector3<Type>& vecF, vector3<Type>& vecS)
{
	std::swap(vecF.x, vecS.x);
	std::swap(vecF.y, vecS.y);
	std::swap(vecF.z, vecS.z);
}

template<typename Type>
float vector3<Type>::magnitude()
{
	float length= std::sqrtf((x * x) + (y * y) + (z * z)); 
	return length;
}

template<typename Type>
float vector3<Type>::magnitude(const vector3<Type>& vec)
{
	float length = std::sqrtf((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z));
	return length;
}

template<typename Type>
vector3<Type>& vector3<Type>::normalize()
{
	float length = this->magnitude();
	x /= length;
	y /= length;
	z /= length;

	return *this;
}

template<typename Type>
vector3<Type>& vector3<Type>::crossProduct(const vector3& vecF, const vector3& vecS)
{
	x = vecF.y * vecS.z - vecF.z * vecS.y;
	y = vecF.z * vecS.x - vecF.x * vecS.z;
	z = vecF.x * vecS.y - vecF.y * vecS.x;

	return *this;
}

template<typename Type>
float vector3<Type>::dotProduct(const vector3& vecF, const vector3& vecS)
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