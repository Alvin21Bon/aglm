#ifndef AGLM_TRANSFORM_MAT4_H
#define AGLM_TRANSFORM_MAT4_H

#include "shared.h"
#include "mat4.h"

/******************************************************************************
* SCALING FUNCTIONS
******************************************************************************/

//
void scaleXMat4(Mat4 matrixToTransform, const float scaleAmt);
void scaleYMat4(Mat4 matrixToTransform, const float scaleAmt);
void scaleZMat4(Mat4 matrixToTransform, const float scaleAmt);

/******************************************************************************
* ROTATING FUNCTIONS
*
* NOTE: All of these functions use radians
******************************************************************************/

//
void rotateXMat4(Mat4 matrixToTransform, const double angleInRadians);
void rotateYMat4(Mat4 matrixToTransform, const double angleInRadians);
void rotateZMat4(Mat4 matrixToTransform, const double angleInRadians);

void pitchMat4(Mat4 matrixToTransform, const double angleInRadians);
void yawMat4(Mat4 matrixToTransform, const double angleInRadians);
void rollMat4(Mat4 matrixToTransform, const double angleInRadians);

/******************************************************************************
* REFLECTING FUNCTIONS
******************************************************************************/

//
void reflectPlaneYZMat4(Mat4 matrixToTransform); 
void reflectPlaneZYMat4(Mat4 matrixToTransform);

void reflectPlaneZXMat4(Mat4 matrixToTransform);
void reflectPlaneXZMat4(Mat4 matrixToTransform);

void reflectPlaneXYMat4(Mat4 matrixToTransform);
void reflectPlaneYXMat4(Mat4 matrixToTransform);

/******************************************************************************
* TRANSLATING FUNCTIONS
******************************************************************************/

//
void translate2DMat4(Mat4 matrixToTransform, const float x, const float y);
void translate3D(Mat4 matrixToTransform, const float x, const float y, const float z);

/******************************************************************************
* SHEARING FUNCTIONS
******************************************************************************/

//
void shearPlaneYZMat4(Mat4 matrixToTransform, const float shearAmt);
void shearPlaneZYMat4(Mat4 matrixToTransform, const float shearAmt);

void shearPlaneZXMat4(Mat4 matrixToTransform, const float shearAmt);
void shearPlaneXZMat4(Mat4 matrixToTransform, const float shearAmt);

void shearPlaneXYMat4(Mat4 matrixToTransform, const float shearAmt);
void shearPlaneYXMat4(Mat4 matrixToTransform, const float shearAmt);

#endif // AGLM_TRANSFORM_MAT4_H