#ifndef QUATERNION_H
#define QUATERNION_H

//=================================
// forward declared dependencies
class Vector;

//=================================
// included dependencies
#include "Vector.h" 
#include "Matrix3x3.h"


// Quaternion Class definition and Function prototypes 
class Quaternion{
	public:
		float		n;    //number (scalar) part
	  Vector  v;		// vector part: v.x, v.y, v.z
		
	
		Quaternion(void);
		Quaternion(float e0, float e1, float e2, float e3);
		
		float Magnitude(void);
		Vector GetVector(void);
		float GetScalar(void);
		Quaternion operator+=(Quaternion q);
		Quaternion operator-=(Quaternion q);
		Quaternion operator*=(float s);
		Quaternion operator/=(float s);
	  Quaternion MakeQFromEulerAngles(float x, float y, float z);
	  Vector MakeEulerAnglesFromQ(Quaternion q);
	  Vector QVRotate(Quaternion q, Vector v);
	
		//This simply returns the negative of the vector part (conjugate)
		Quaternion operator~(void) const { return Quaternion(n,
																												 -v.x,
																												 -v.y,
																												 -v.z);}
};

// Vector multiplication - vector by quaternion multiplication
// Two types for different encounter order
inline Quaternion operator*(Quaternion q, Vector v)
{
	return Quaternion(   -(q.v.x*v.x + q.v.y*v.y + q.v.z*v.z),
													q.n*v.x + q.v.y*v.z - q.v.z*v.y,
													q.n*v.y +q.v.z*v.x - q.v.x*v.z,
												  q.n*v.z + q.v.x*v.y - q.v.y*v.x);
}

inline Quaternion operator*(Vector v, Quaternion q)
{
	return Quaternion(   -(q.v.x*v.x + q.v.y*v.y + q.v.z*v.z),
													q.n*v.x + q.v.y*v.z - q.v.z*v.y,
													q.n*v.y +q.v.z*v.x - q.v.x*v.z,
												  q.n*v.z + q.v.x*v.y - q.v.y*v.x);
}

// Scalar multiplication - multiplies each element in the Quaternion by the scalar
// Two types for different encounter order
inline Quaternion operator*(Quaternion q, float s)
{
	return Quaternion(q.n*s, q.v.x*s, q.v.y*s, q.v.z*s);
}

inline Quaternion operator*(float s, Quaternion q)
{
	return Quaternion(q.n*s, q.v.x*s, q.v.y*s, q.v.z*s);
}
//Create a matrix from a quaternion
inline Matrix3x3 MakeMatrixFromQuaternion(Quaternion q)
{
	return Matrix3x3(1.0f - 2.0f*q.v.y*q.v.y - 2.0f*q.v.z*q.v.z, 2.0f*q.v.x*q.v.y - 2.0f*q.v.z*q.n, 2.0f*q.v.x*q.v.z + 2.0f*q.v.y*q.n, 0.0f,
    2.0f*q.v.x*q.v.y + 2.0f*q.v.z*q.n, 1.0f - 2.0f*q.v.x*q.v.x - 2.0f*q.v.z*q.v.z, 2.0f*q.v.y*q.v.z - 2.0f*q.v.x*q.n, 0.0f,
    2.0f*q.v.x*q.v.z - 2.0f*q.v.y*q.n, 2.0f*q.v.y*q.v.z + 2.0f*q.v.x*q.n, 1.0f - 2.0f*q.v.x*q.v.x - 2.0f*q.v.y*q.v.y, 0.0f,
    0.0f, 0.0f, 0.0f, 1.0f)
}

#endif
