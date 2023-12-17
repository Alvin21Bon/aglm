#include "../include/lina.h"

// scaling
Mat2 mat2ScaledX(const Mat2 mat, const float scalar)
{
	Mat2 transformation = mat2Identity();
	transformation.ihat.x = scalar;

	return mat2MultMat(transformation, mat);
}
Mat2 mat2ScaledY(const Mat2 mat, const float scalar)
{
	Mat2 transformation = mat2Identity();
	transformation.jhat.y = scalar;

	return mat2MultMat(transformation, mat);
}
Mat2 mat2Scaled(const Mat2 mat, const float scalar)
{
	Mat2 transformation = mat2Identity();
	transformation = mat2ScaledX(transformation, scalar);
	transformation = mat2ScaledY(transformation, scalar);

	return mat2MultMat(transformation, mat);
}

// rotating
Mat2 mat2Rotated(const Mat2 mat, const double radians, const Vec3 axis)
{
	Mat2 transformation = mat2Identity();
	transformation.ihat = vec2Rotated(transformation.ihat, radians, axis);
	transformation.jhat = vec2Rotated(transformation.jhat, radians, axis);

	return mat2MultMat(transformation, mat);
}
Mat2 mat2Pitch(const Mat2 mat, const double radians) 
{
	Mat2 transformation = mat2Rotated(mat2Identity(), radians, vec3(1,0,0));
	return mat2MultMat(transformation, mat);
}
Mat2 mat2Yaw(const Mat2 mat, const double radians) 
{
	Mat2 transformation = mat2Rotated(mat2Identity(), radians, vec3(0,1,0));
	return mat2MultMat(transformation, mat);
}
Mat2 mat2Roll(const Mat2 mat, const double radians) 
{
	Mat2 transformation = mat2Rotated(mat2Identity(), radians, vec3(0,0,1));
	return mat2MultMat(transformation, mat);
}

// reflecting
Mat2 mat2ReflectedX(const Mat2 mat);
Mat2 mat2ReflectedY(const Mat2 mat);

// shearing
Mat2 mat2ShearedX(const Mat2 mat, const float shearAmt);
Mat2 mat2ShearedY(const Mat2 mat, const float shearAmt);
