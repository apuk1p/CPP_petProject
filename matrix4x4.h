#pragma once

#include <iostream>
#include <array>
#include "vector3.h"
//#include <memory>

class matrix4x4
{
public:
	matrix4x4();
	matrix4x4(const matrix4x4& rhs) = default;
	~matrix4x4() = default;

	vector3<float> getScale();
	void setScale(const vector3<float>& vec);
	
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