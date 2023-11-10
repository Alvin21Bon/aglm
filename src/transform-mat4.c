#include "../include/aglm.h"

void scaleXMat4(Mat4 matrixToTransform, const float scaleAmt)
{
	Mat4 transformation;
	fillIdentityMat4(transformation);

	scaleVec4(scaleAmt, transformation[0]);

	multMat4Mat(transformation, matrixToTransform);
}
void scaleYMat4(Mat4 matrixToTransform, const float scaleAmt)
{
	Mat4 transformation;
	fillIdentityMat4(transformation);

	scaleVec4(scaleAmt, transformation[1]);

	multMat4Mat(transformation, matrixToTransform);
}
void scaleZMat4(Mat4 matrixToTransform, const float scaleAmt)
{
	Mat4 transformation;
	fillIdentityMat4(transformation);

	scaleVec4(scaleAmt, transformation[2]);

	multMat4Mat(transformation, matrixToTransform);
}

void rotateXMat4(Mat4 matrixToTransform, const double angleInRadians)
{
	Mat4 transformation;
	Vec4 transformedIHat = {1, 0, 0, 0};
	Vec4 transformedJHat = {0, cos(angleInRadians), sin(angleInRadians), 0};
	Vec4 transformedKHat = {0, -sin(angleInRadians), cos(angleInRadians), 0};
	Vec4 transformedLHat = {0, 0, 0, 1};

	fillMat4(transformedIHat, transformedJHat, transformedKHat, transformedLHat, transformation);

	multMat4Mat(transformation, matrixToTransform);
}
void rotateYMat4(Mat4 matrixToTransform, const double angleInRadians)
{
	Mat4 transformation;
	Vec4 transformedIHat = {cos(angleInRadians), 0, -sin(angleInRadians), 0};
	Vec4 transformedJHat = {0, 1, 0, 0};
	Vec4 transformedKHat = {sin(angleInRadians), 0, cos(angleInRadians), 0};
	Vec4 transformedLHat = {0, 0, 0, 1};

	fillMat4(transformedIHat, transformedJHat, transformedKHat, transformedLHat, transformation);

	multMat4Mat(transformation, matrixToTransform);
}
void rotateZMat4(Mat4 matrixToTransform, const double angleInRadians)
{
	Mat4 transformation;
	Vec4 transformedIHat = {cos(angleInRadians), sin(angleInRadians), 0, 0};
	Vec4 transformedJHat = {-sin(angleInRadians), cos(angleInRadians), 0, 0};
	Vec4 transformedKHat = {0, 0, 1, 0};
	Vec4 transformedLHat = {0, 0, 0, 1};

	fillMat4(transformedIHat, transformedJHat, transformedKHat, transformedLHat, transformation);

	multMat4Mat(transformation, matrixToTransform);
}

void pitchMat4(Mat4 matrixToTransform, const double angleInRadians)
{
	rotateXMat4(matrixToTransform, angleInRadians);
}
void yawMat4(Mat4 matrixToTransform, const double angleInRadians)
{
	rotateYMat4(matrixToTransform, angleInRadians);
}
void rollMat4(Mat4 matrixToTransform, const double angleInRadians)
{
	rotateZMat4(matrixToTransform, angleInRadians);
}

void reflectPlaneYZMat4(Mat4 matrixToTransform); 
void reflectPlaneZYMat4(Mat4 matrixToTransform);

void reflectPlaneZXMat4(Mat4 matrixToTransform);
void reflectPlaneXZMat4(Mat4 matrixToTransform);

void reflectPlaneXYMat4(Mat4 matrixToTransform);
void reflectPlaneYXMat4(Mat4 matrixToTransform);

void translate2DMat4(Mat4 matrixToTransform, const float x, const float y);
void translate3D(Mat4 matrixToTransform, const float x, const float y, const float z);

void shearPlaneYZMat4(Mat4 matrixToTransform, const float shearAmtY, const float shearAmtZ);
void shearPlaneZYMat4(Mat4 matrixToTransform, const float shearAmtY, const float shearAmtZ);

void shearPlaneZXMat4(Mat4 matrixToTransform, const float shearAmtZ, const float shearAmtX);
void shearPlaneXZMat4(Mat4 matrixToTransform, const float shearAmtZ, const float shearAmtX);

void shearPlaneXYMat4(Mat4 matrixToTransform, const float shearAmtX, const float shearAmtY);
void shearPlaneYXMat4(Mat4 matrixToTransform, const float shearAmtX, const float shearAmtY);

