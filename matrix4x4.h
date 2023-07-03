#pragma once

#include <array>
#include <memory>
#include "vector3.h"

class matrix4x4
{
public:
	matrix4x4();
	~matrix4x4() = default;
	matrix4x4(const matrix4x4& rhs);

	//std::array doesn' support move semantic

	//operators
	matrix4x4& operator=(const matrix4x4& rhs);
	matrix4x4& operator+=(const matrix4x4& rhs);
	matrix4x4& operator-=(const matrix4x4& rhs);
	matrix4x4& operator*=(const matrix4x4& rhs);

	template<typename Type>
	matrix4x4& operator*=(const Type& value);
	float& operator[](const std::size_t index);
	const float& operator[](const std::size_t index) const;

	float& operator()(std::size_t r, std::size_t c);
	const float& operator()(std::size_t r, std::size_t c) const;

	//set values
	void setScale(const vector3<float>& vec);
	void setTransform(const vector3<float>& vec);

	//get values
	vector3<float> getScale() const;
	vector3<float> getTransform() const;

	//rotation

	std::size_t index(std::size_t r, std::size_t c) const;
	void showMatrix() const;
	void forMethod(const matrix4x4& other);
	
private:
	std::array<float, 16> mtxData;
	std::size_t row;
	std::size_t column;
};

matrix4x4::matrix4x4() : row(4), column(4)
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
	row = rhs.row;
	column = rhs.column;
}


matrix4x4& matrix4x4::operator=(const matrix4x4& rhs)
{
	if (this != &rhs)
	{
		forMethod(rhs);
		row = rhs.row;
		column = rhs.column;
	}
	return *this;
}

matrix4x4& matrix4x4::operator+=(const matrix4x4& rhs)
{
	for (int i = 0; i < rhs.mtxData.size(); i++)
	{
		mtxData[i] += rhs.mtxData[i];
	}

	return *this;
}

matrix4x4& matrix4x4::operator-=(const matrix4x4& rhs)
{
	for (int i = 0; i < rhs.mtxData.size(); i++)
	{
		mtxData[i] -= rhs.mtxData[i];
	}

	return *this;
}

matrix4x4 operator+(const matrix4x4& lhs, const matrix4x4& rhs)
{
	matrix4x4 newAddMtx(lhs);
	newAddMtx += rhs;
	return newAddMtx;
}

matrix4x4 operator-(const matrix4x4& lhs, const matrix4x4& rhs)
{
	matrix4x4 newSubMtx(lhs);
	newSubMtx -= rhs;
	return newSubMtx;
}

matrix4x4& matrix4x4::operator*=(const matrix4x4& rhs)
{
	matrix4x4 newMatrix;
	std::fill(newMatrix.mtxData.begin(), newMatrix.mtxData.end(), 0.0f);
	
	for (std::size_t r = 0; r < row; ++r)
	{
		for (std::size_t j = 0; j < column; ++j)
		{
			for (std::size_t c = 0; c < column; ++c)
			{
				newMatrix[index(r, j)] += mtxData[index(r, c)] * rhs.mtxData[index(c, j)];
			}
		}
	}

	this->mtxData = newMatrix.mtxData;
	return *this;
}

template<typename Type>
matrix4x4& matrix4x4::operator*=(const Type& value)
{
	for (int i = 0; i < mtxData.size(); i++)
	{
		mtxData[i] *= value;
	}
	return *this;
}

template<typename Type>
matrix4x4 operator*(const matrix4x4& lhs, const Type& value)
{
	matrix4x4 newMulMtx(lhs);
	newMulMtx *= value;
	return newMulMtx;
}

float& matrix4x4::operator[](const std::size_t index)
{
	if (index + 1 > mtxData.size())
	{
		throw std::out_of_range("INDEX OUT OF RANGE");
	}
	return mtxData[index];
}

const float& matrix4x4::operator[](const std::size_t index) const
{
	if (index + 1 > mtxData.size())
	{
		throw std::out_of_range("INDEX OUT OF RANGE");
	}
	return mtxData[index];
}

float& matrix4x4::operator()(std::size_t r, std::size_t c)
{
	//if (r < row && c < mtxData.size() / r)
	//{
	//	throw std::out_of_range("INDEX OUT OF RANGE");
	//}
	return mtxData[index(r, c)];
}

const float& matrix4x4::operator()(std::size_t r, std::size_t c) const
{
	//if (r < row && c < mtxData.size() / r)
	//{
	//	throw std::out_of_range("INDEX OUT OF RANGE");
	//}
	return mtxData[index(r, c)];
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

void matrix4x4::showMatrix() const
{
	int counter = 1;
	for (const auto& val : mtxData)
	{
		std::cout << val << "  ";
		if ( counter % 4 == 0)
		{
			std::cout << std::endl;
		}
		counter++;
	}
}

void matrix4x4::forMethod(const matrix4x4& other)
{
	for (int i = 0; i < other.mtxData.size(); i++)
	{
		mtxData[i] = other.mtxData[i];
	}
	//int counter = 0;
	//for (const auto& val : other.mtxData)
	//{
	//	mtxData[counter] = val;
	//	++counter;
	//}
}

std::size_t matrix4x4::index(std::size_t r, std::size_t c) const
{
	return r * column + c;
}