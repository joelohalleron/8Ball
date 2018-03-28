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

Quaternion operator*(Quaternion q, Vector v);
Quaternion operator*(Vector v, Quaternion q);


Quaternion operator*(float s, Quaternion q);
Quaternion operator*(Quaternion q, float s);


#endif
