
#include "Matrix3x3.h"


// Constructor no args
inline Matrix3x3::Matrix3x3(void)
{
	e11 = 0;
	e12 = 0;
	e13 = 0;
	e21 = 0;
	e22 = 0;
	e23 = 0;
	e31 = 0;
	e32 = 0;
	e33 = 0;
}

// Construct with args
inline Matrix3x3::Matrix3x3(float r1c1, float r1c2, float r1c3,
														float r2c1, float r2c2, float r2c3,
														float r3c1, float r3c2, float r3c3)
{
	e11 = r1c1;
	e12 = r1c2;
  e13 = r1c3;
  e21 = r2c1;
  e22 = r2c2;
  e23 = r2c3;
  e31 = r3c1;
  e32 = r3c2;
  e33 = r3c3;
}

// Determinant
inline float Matrix3x3::det(void)
{
	return  e11*e22*e33 -
					e11*e32*e23 +
					e21*e32*e13 -
					e21*e12*e33 +
					e31*e12*e23 -
		      e31*e22*e13;
}

// Transpose
inline Matrix3x3 Matrix3x3::Transpose(void)
{
	return Matrix3x3(e11, e21, e31, e12, e22, e32, e13, e23, e33);
}

// Inverse
inline Matrix3x3 Matrix3x3::Inverse(void)
{
	float d = e11*e22*e33 -
            e11*e32*e23 +
            e21*e32*e13 -
            e21*e12*e33 +
            e31*e12*e23 -
            e31*e22*e13;
	
	if(d==0) d = 1;
	
	return Matrix3x3(    (e22*e33-e23*e32)/d,
											-(e12*e33-e13*e32)/d,
											 (e12*e23-e13*e22)/d,
											-(e21*e33-e23*e31)/d,
											 (e11*e33-e13*e31)/d,
											-(e11*e23-e13*e21)/d,
											 (e21*e32-e22*e31)/d,
											-(e11*e32-e12*e31)/d,
											 (e11*e22-e12*e21)/d );
}

// Matrix addition +=Operator
inline  Matrix3x3& Matrix3x3::operator+=(Matrix3x3 m)
{
	e11 += m.e11;
	e12 += m.e12;
  e13 += m.e13;
  e21 += m.e21;
  e22 += m.e22;
  e23 += m.e23;
  e31 += m.e31;
  e32	+= m.e32;
  e33 += m.e33;
	return *this;
}

// Matrix subtraction -=Operator
inline Matrix3x3& Matrix3x3::operator-=(Matrix3x3 m)
{
	e11 -= m.e11;
	e12 -= m.e12;
  e13 -= m.e13;
  e21 -= m.e21;
  e22 -= m.e22;
  e23 -= m.e23;
  e31 -= m.e31;
  e32	-= m.e32;
  e33 -= m.e33;
	return *this;
}

// Matrix scalar multiplication *=operator
inline Matrix3x3& Matrix3x3::operator*=(float s)
{
	e11 *= s; 
  e12 *= s; 
  e13 *= s; 
  e21 *= s; 
  e22 *= s; 
  e23 *= s; 
  e31 *= s; 
  e32	*= s; 
  e33 *= s; 
	return *this;
}

// Matrix scalar division /=operator
inline Matrix3x3& Matrix3x3::operator/=(float s)
{
	e11 /= s; 
  e12 /= s; 
  e13 /= s; 
  e21 /= s; 
  e22 /= s; 
  e23 /= s; 
  e31 /= s; 
  e32	/= s; 
  e33 /= s; 
	return *this;
}

