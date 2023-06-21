#pragma once

#include <iostream>
#include <array>
#include "vector3.h"
#include <memory>

class matrix4x4
{
public:
	matrix4x4();
	~matrix4x4();
	matrix4x4(const matrix4x4& rhs);
	matrix4x4(matrix4x4&& rhs) noexcept;

	matrix4x4& operator=(const matrix4x4& rhs);
	matrix4x4& operator=(matrix4x4&& rhs) noexcept;
	float& operator[](const std::size_t index);

	//set values
	void setScale(const vector3<float>& vec);
	void setTransform(const vector3<float>& vec);

	//get values
	vector3<float> getScale() const;
	vector3<float> getTransform() const;

	//rotation

	void showMatrix();
	void forMethod(const matrix4x4& other);
	void cleanArr();
	
private:
	std::array<float, 16> mtxData;
};

matrix4x4::matrix4x4()
{
	mtxData =
	{
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 0,
	};
}

matrix4x4::matrix4x4(const matrix4x4& rhs)
{
	forMethod(rhs);
}

matrix4x4::matrix4x4(matrix4x4&& rhs) noexcept
{
	cleanArr();
	std::swap(mtxData, rhs.mtxData);
}

matrix4x4::~matrix4x4() {}


matrix4x4& matrix4x4::operator=(const matrix4x4& right)
{
	if (this != &right)
	{
		forMethod(right);
	}
	return *this;
}

matrix4x4& matrix4x4::operator=(matrix4x4&& right) noexcept
{
	if (this != &right)
	{
		cleanArr();
		std::swap(mtxData, right.mtxData);
	}

	return *this;
}

float& matrix4x4::operator[](const std::size_t index)
{
	if (index + 1 > mtxData.size())
	{
		throw std::out_of_range("INDEX OUT OF RANGE");
	}
	return mtxData[index];
}


void matrix4x4::setScale(const vector3<float>& vec)
{
	mtxData[0] = vec.x;
	mtxData[5] = vec.y;
	mtxData[10] = vec.z;
}

void matrix4x4::setTransform(const vector3<float>& vec)
{
	mtxData[3] = vec.x;
	mtxData[7] = vec.y;
	mtxData[11] = vec.z;
}


vector3<float> matrix4x4::getScale() const
{
	vector3 newVec(mtxData[0], mtxData[5], mtxData[10]);
	return newVec;
}

vector3<float> matrix4x4::getTransform() const
{
	vector3 newVec(mtxData[3], mtxData[7], mtxData[11]);
	return newVec;
}

void matrix4x4::showMatrix()
{
	int counter = 1;
	for (auto& val : mtxData)
	{
		std::cout << val << '\t';
		if (counter % 4 == 0)
		{
			std::cout << '\n' << std::endl;
		}
		++counter;
	}
}

void matrix4x4::forMethod(const matrix4x4& other)
{
	int counter = 0;
	for (const auto& val : other.mtxData)
	{
		this->mtxData[counter] = val;
		++counter;
	}
}

void matrix4x4::cleanArr()
{
	for (auto& val : this->mtxData)
	{
		val = 0;
	}
}