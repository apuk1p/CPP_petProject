#pragma once

#include <iostream>
#include <stdexcept>
#include <algorithm>

template<typename Type>

class Vector3
{
public:
	Type x, y, z;

	Vector3();
	Vector3(Type x, Type y, Type z);
	~Vector3();

	Vector3(const Vector3& other);
	Vector3(Vector3&& other) noexcept;

	Vector3& operator=(const Vector3& other);
	Vector3& operator=(Vector3&& other) noexcept;

	Vector3& operator-(const Vector3& other);
	Vector3& operator-=(const Vector3& other);

	Vector3& operator+(const Vector3& other);
	Vector3& operator+=(const Vector3& other);

	Vector3& operator*(const Type value);
	Vector3& operator*=(const Type value);

	Vector3& operator/(const Type value);
	Vector3& operator/=(const Type value);

	void moveSwap(Vector3& first, Vector3& second);

};

template<typename Type>
void Vector3<Type>::moveSwap(Vector3<Type>& first, Vector3<Type>& second)
{
	std::swap(first.x, second.x);
	std::swap(first.y, second.y);
	std::swap(first.z, second.z);
}

template<typename Type>
Vector3<Type>::Vector3() : x(0), y(0), z(0) {}

template<typename Type>
Vector3<Type>::Vector3(Type x, Type y, Type z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

template<typename Type>
Vector3<Type>::~Vector3() {}

template<typename Type>
Vector3<Type>::Vector3(const Vector3<Type>& other)
{
	x = other.x;
	y = other.y;
	z = other.z;
}

template<typename Type>
Vector3<Type>::Vector3(Vector3<Type>&& other) noexcept : x(0),y(0),z(0)
{
	moveSwap(*this, other);
}

template<typename Type>
Vector3<Type>& Vector3<Type>::operator=(const Vector3<Type>& other)
{
	if (this != &other)
	{
		x = other.x;
		y = other.y;
		z = other.z;
	}
	return *this;
}

template<typename Type>
Vector3<Type>& Vector3<Type>::operator=(Vector3<Type>&& other) noexcept
{
	if (this != &other)
	{
		this->x = 0;
		this->y = 0;
		this->z = 0;
		moveSwap(*this, other);
	}
	return *this;
}

template<typename Type>
Vector3<Type>& Vector3<Type>::operator-(const Vector3& other)
{
	return (x - other.x, y - other.y, z - other.z);
}

template<typename Type>
Vector3<Type>& Vector3<Type>::operator-=(const Vector3& other)
{
	return (x -= other.x, y -= other.y, z -= other.z);
}

template<typename Type>
Vector3<Type>& Vector3<Type>::operator+(const Vector3& other)
{
	return (x + other.x, y + other.y, z + other.z);
}

template<typename Type>
Vector3<Type>& Vector3<Type>::operator+=(const Vector3& other)
{
	return (x += other.x, y += other.y, z += other.z);
}

template<typename Type>
Vector3<Type>& Vector3<Type>::operator*(const Type value)
{
	return (x * value, y * value, z * value);
}

template<typename Type>
Vector3<Type>& Vector3<Type>::operator*=(const Type value)
{
	return (x *= value, y *= value, z *= value);
}

template<typename Type>
Vector3<Type>& Vector3<Type>::operator/(const Type value)
{
	_ASSERT(value != 0);
	return (x / value, y / value, z / value);
}

template<typename Type>
Vector3<Type>& Vector3<Type>::operator/=(const Type value)
{
	/*if (value == 0)
	{
		throw std::domain_error("Divide by zero exception!");
	}*/
	_ASSERT(value != 0);
	return (x /= value, y /= value, z /= value);
}