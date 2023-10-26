#include "../include/aglm.h"

void fillVec4(const float x, const float y, const float z, const float w, Vec4 outputVector)
{
	outputVector[0] = x;
	outputVector[1] = y;
	outputVector[2] = z;
	outputVector[3] = w;
}
void zeroVec4(Vec4 zeroedVector)
{
	fillVec4(0, 0, 0, 0, zeroedVector);
}
void copyVec4(const Vec4 inputVector, Vec4 copyIntoVector)
{
	fillVec4(inputVector[0], inputVector[1], inputVector[2], inputVector[3], copyIntoVector);
}

void addVec4(const Vec4 vectorA, const Vec4 vectorB, Vec4 outputVector)
{
	outputVector[0] = vectorA[0] + vectorB[0];
	outputVector[1] = vectorA[1] + vectorB[1];
	outputVector[2] = vectorA[2] + vectorB[2];
	outputVector[3] = vectorA[3] + vectorB[3];
}
void subtractVec4(const Vec4 vectorA, const Vec4 vectorB, Vec4 outputVector)
{
	outputVector[0] = vectorA[0] - vectorB[0];
	outputVector[1] = vectorA[1] - vectorB[1];
	outputVector[2] = vectorA[2] - vectorB[2];
	outputVector[3] = vectorA[3] - vectorB[3];
}

void sumOfVec4(Vec4 outputVector, const size_t numOfOperands, ...)
{
	int argIndex;
	va_list argInfo;
	Vec4 tempOutputVector; // to support outputVector being one of the operands

	va_start(argInfo, numOfOperands);

	zeroVec4(tempOutputVector);
	for (argIndex = 0; argIndex < numOfOperands; argIndex++)
	{
		addVec4(tempOutputVector, va_arg(argInfo, float*), tempOutputVector);
	}

	va_end(argInfo);

	copyVec4(tempOutputVector, outputVector);
}
void differenceOfVec4(Vec4 outputVector, const size_t numOfOperands, ...)
{
	int argIndex;
	va_list argInfo;
	Vec4 tempOutputVector; // to support outputVector being one of the operands

	va_start(argInfo, numOfOperands);

	// copy first argument/operand so that subtraction is not applied
	copyVec4(va_arg(argInfo, float*), tempOutputVector); 
	for (argIndex = 1; argIndex < numOfOperands; argIndex++)
	{
		subtractVec4(tempOutputVector, va_arg(argInfo, float*), tempOutputVector);
	}

	va_end(argInfo);

	copyVec4(tempOutputVector, outputVector);
}

void scaleVec4(const float scalar, Vec4 scaledVector)
{
	scaledVector[0] = scalar * scaledVector[0];
	scaledVector[1] = scalar * scaledVector[1];
	scaledVector[2] = scalar * scaledVector[2];
	scaledVector[3] = scalar * scaledVector[3];
}
void negVec4(Vec4 negatedVector)
{
	scaleVec4(-1, negatedVector);
}

