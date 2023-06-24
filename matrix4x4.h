#pragma once

#include <array>
#include <memory>
#include "vector3.h"

class matrix4x4
{
public:
	matrix4x4();
	~matrix4x4();
	matrix4x4(const matrix4x4& rhs);
	matrix4x4(matrix4x4&& rhs) noexcept;

	//operators
	matrix4x4& operator=(const matrix4x4& rhs);
	matrix4x4& operator=(matrix4x4&& rhs) noexcept;
	matrix4x4& operator+=(const matrix4x4& rhs);
	matrix4x4& operator-=(const matrix4x4& rhs);
	matrix4x4& operator*=(const matrix4x4& rhs);

	template<typename Type>
	matrix4x4& operator*=(const Type& value);
	float& operator[](const std::size_t index);

	//set values
	void setScale(const vector3<float>& vec);
	void setTransform(const vector3<float>& vec);

	//get values
	vector3<float> getScale() const;
	vector3<float> getTransform() const;

	//rotation

	void showMatrix() const;
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


matrix4x4& matrix4x4::operator=(const matrix4x4& rhs)
{
	if (this != &rhs)
	{
		forMethod(rhs);
	}
	return *this;
}

matrix4x4& matrix4x4::operator=(matrix4x4&& rhs) noexcept
{
	if (this != &rhs)
	{
		cleanArr();
		std::swap(mtxData, rhs.mtxData);
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
	std::size_t startClm = 0;
	std::size_t columnShift = 0;

	std::size_t newMtxIt = 0;
	matrix4x4 newMatrix;
	float mulResult = 0;

	for (std::size_t i = 0; i < mtxData.size();)
	{
		std::size_t lineCtr = i;

		for (std::size_t b = 0; b < mtxData.size(); ++b)
		{
			if (b % 4 == 0 && b != 0)
			{
				//shift start column line
				++startClm;
				columnShift = startClm;
				//shift line
				lineCtr = i;
				
				//write value to new matrix
				newMatrix[newMtxIt] = mulResult;
				mulResult = 0;
				++newMtxIt;
			}

			if (b % 4 == 0 || b == 0)
			{
				mulResult += mtxData[lineCtr] * rhs.mtxData[columnShift];
			}
			else
			{
				columnShift += 4;
				mulResult += mtxData[lineCtr] * rhs.mtxData[columnShift];
			}
			++lineCtr;
		}
		//write the last cicle value after b = 15
		newMatrix[newMtxIt] = mulResult;
		mulResult = 0;
		++newMtxIt;

		//reset value of second mtx
		startClm = 0;
		columnShift = 0;
		i += 4;
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
	/*int counter = 0;
	for (const auto& val : other.mtxData)
	{
		mtxData[counter] = val;
		++counter;
	}*/
}

void matrix4x4::cleanArr()
{
	for (auto& val : mtxData)
	{
		val = 0;
	}
}