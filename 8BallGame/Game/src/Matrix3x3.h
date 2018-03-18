#ifndef MATRIX3X3_H
#define MATRIX3X3_H

//=================================
// forward declared dependencies
class Vector;

//=================================
// included dependencies
#include <math.h>
#include "Vector.h"

class Matrix3x3 {
	public:
		//elements eij: i-> row, j -> column
		float   e11, e12, e13, e21, e22, e23, e31, e32, e33;
		
		Matrix3x3(void);
		Matrix3x3(float r1c1, float r1c2, float r1c3,
							float r2c1, float r2c2, float r2c3,
							float r3c1, float r3c2, float r3c3);
		
		float det(void);
		Matrix3x3 Transpose(void);
		Matrix3x3 Inverse(void);
							
		Matrix3x3& operator+=(Matrix3x3 m);
		Matrix3x3& operator-=(Matrix3x3 m);
		Matrix3x3& operator*=(float s);
		Matrix3x3& operator/=(float s);						
};

// Matrix Functions and Operators //

// Inter-Matrix addition, adds two matices together
inline Matrix3x3 operator+=(Matrix3x3 m1, Matrix3x3 m2)
{
	return Matrix3x3( m1.e11 + m2.e11,
										m1.e12 + m2.e12,
										m1.e13 + m2.e13,
										m1.e21 + m2.e21,
										m1.e22 + m2.e22,
										m1.e23 + m2.e23,
										m1.e31 + m2.e31,
										m1.e32 + m2.e32,
										m1.e33 + m2.e33);
}

// Inter-Matrix subtraction, subtrracts one matrix from another
inline Matrix3x3 operator-=(Matrix3x3 m1, Matrix3x3 m2)
{
	return Matrix3x3( m1.e11 - m2.e11,
										m1.e12 - m2.e12,
										m1.e13 - m2.e13,
										m1.e21 - m2.e21,
										m1.e22 - m2.e22,
										m1.e23 - m2.e23,
										m1.e31 - m2.e31,
										m1.e32 - m2.e32,
										m1.e33 - m2.e33);
}

// Scalar divide, divides each matrix element by the scalar
inline Matrix3x3 operator/(Matrix3x3 m, float s)
{
	return Matrix3x3(	m.e11/s,
		                m.e12/s,
                    m.e13/s,
                    m.e21/s,
                    m.e22/s,
                    m.e23/s,
                    m.e31/s,
                    m.e32/s,
                    m.e33/s);
}

// Multiply two matrices 
inline Matrix3x3 operator*(Matrix3x3 m1, Matrix3x3 m2)
{
	return Matrix3x3(	m1.e11*m2.e11 + m1.e12*m2.e21 + m1.e13*m2.e31,
										m1.e11*m2.e12 + m1.e12*m2.e22 + m1.e13*m2.e32,
										m1.e11*m2.e13 + m1.e12*m2.e23 + m1.e13*m2.e33,
										m1.e21*m2.e11 + m1.e22*m2.e21 + m1.e23*m2.e31,
										m1.e21*m2.e12 + m1.e22*m2.e22 + m1.e23*m2.e32,
										m1.e21*m2.e13 + m1.e22*m2.e23 + m1.e23*m2.e33,
										m1.e31*m2.e11 + m1.e32*m2.e21 + m1.e33*m2.e31,
										m1.e31*m2.e12 + m1.e32*m2.e22 + m1.e33*m2.e32,
										m1.e31*m2.e13 + m1.e32*m2.e23 + m1.e33*m2.e33);
}

// Multiply each element in a matrix m by a scalar s
// Two types for different order of encounter
inline Matrix3x3 operator*(Matrix3x3 m, float s)
{
	return	Matrix3x3(m.e11*s,
										m.e12*s,
										m.e13*s,
										m.e21*s,
										m.e22*s,
										m.e23*s,
										m.e31*s,
										m.e32*s,
										m.e33*s);
}

inline Matrix3x3 operator*(float s, Matrix3x3 m)
{
	return	Matrix3x3(m.e11*s,
										m.e12*s,
										m.e13*s,
										m.e21*s,
										m.e22*s,
										m.e23*s,
										m.e31*s,
										m.e32*s,
										m.e33*s);
}

// Matrix-Vector Multiplication
// Two types depending on order of the encounter
inline Vector operator*(Matrix3x3 m, Vector u)
{
	return Vector( m.e11*u.x + m.e12*u.y + m.e13*u.z,
								 m.e21*u.x + m.e22*u.y + m.e23*u.z,
								 m.e31*u.x + m.e32*u.y + m.e33*u.z);
}

inline Vector operator*(Vector u, Matrix3x3 m)
{
		return Vector( m.e11*u.x + m.e12*u.y + m.e13*u.z,
								 m.e21*u.x + m.e22*u.y + m.e23*u.z,
								 m.e31*u.x + m.e32*u.y + m.e33*u.z);
}


#endif
