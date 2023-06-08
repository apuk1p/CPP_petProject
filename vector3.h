#pragma once

#include <iostream>
#include <stdexcept>

template<typename Type>

class Vector3
{
public:
	Type x, y, z;

	Vector3();
	Vector3(Type x, Type y, Type z);
	~Vector3();

	Vector3(const Vector3& other) {}
	Vector3(Vector3&& other) {}

	//Vector3& normalize() {};

	Vector3& operator=(const Vector3& other) {}
	Vector3& operator=(Vector3&& other) noexcept {}

	Vector3& operator-(const Vector3& other);
	Vector3& operator-=(const Vector3& other);

	Vector3& operator+(const Vector3& other);
	Vector3& operator+=(const Vector3& other);

	Vector3& operator*(const Type value);
	Vector3& operator*=(const Type value);

	Vector3& operator/(const Type value);
	Vector3& operator/=(const Type value);

};
template<typename Type>
Vector3<Type>::Vector3()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

template<typename Type>
Vector3<Type>::Vector3(Type x, Type y, Type z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

template<typename Type>
Vector3<Type>::~Vector3()
{

}

template<typename Type>
Vector3<Type>& Vector3<Type>::operator-(const Vector3& other)
{
	return (x - other.x, y - other.y, z - other.z);
}

template<typename Type>
Vector3<Type>& Vector3<Type>::operator-=(const Vector3& other)
{
	x -= other.x;
	y -= other.y;
	z -= other.z;
	return *this;
}

template<typename Type>
Vector3<Type>& Vector3<Type>::operator+(const Vector3& other)
{
	return (x + other.x, y + other.y, z + other.z);
}

template<typename Type>
Vector3<Type>& Vector3<Type>::operator+=(const Vector3& other)
{
	x += other.x;
	y += other.y;
	z += other.z;
	return *this;
}

template<typename Type>
Vector3<Type>& Vector3<Type>::operator*(const Type value)
{
	return (x * value, y * value, z * value);
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
		throw std::exception("Divide by zero exception!");
	}*/
	_ASSERT(value != 0);
	x /= value;
	y /= value;
	z /= value;
	return *this;
}