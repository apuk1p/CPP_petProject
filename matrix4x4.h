#pragma once

#include <iostream>
#include <array>
#include "vector3.h"
#include <memory>

class matrix4x4
{
public:
	matrix4x4();
	matrix4x4(const matrix4x4& rhs);
	matrix4x4(matrix4x4&& rhs) noexcept;
	~matrix4x4();

	matrix4x4& operator=(const matrix4x4& rhs);
	matrix4x4& operator=(matrix4x4&& rhs);

	vector3<float> getScale();
	void setScale(const vector3<float>& vec);
	//position
	//rotation
	//
	
	void showMatrix();
	
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
	int counter = 0;
	for (const auto& val : rhs.mtxData)
	{
		mtxData[counter] = val;
		++counter;
	}
}

matrix4x4::matrix4x4(matrix4x4&& rhs) noexcept
{
	for (auto& val : mtxData)
	{
		val = 0;
	}
	std::swap(mtxData, rhs.mtxData);
}

matrix4x4::~matrix4x4() { std::cout << "matrix destructor" << std::endl; }

vector3<float> matrix4x4::getScale()
{
	vector3 newVec(mtxData[0], mtxData[5], mtxData[10]);
	return newVec;
}

void matrix4x4::setScale(const vector3<float>& vec)
{
	mtxData[0] = vec.x;
	mtxData[5] = vec.y;
	mtxData[10] = vec.z;
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