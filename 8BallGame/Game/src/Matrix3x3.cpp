
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
// Matrix Functions and Operators //

// Inter-Matrix addition, adds two matices together
Matrix3x3 operator+=(Matrix3x3 m1, Matrix3x3 m2)
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
Matrix3x3 operator-=(Matrix3x3 m1, Matrix3x3 m2)
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
Matrix3x3 operator/(Matrix3x3 m, float s)
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
Matrix3x3 operator*(Matrix3x3 m1, Matrix3x3 m2)
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
Matrix3x3 operator*(Matrix3x3 m, float s)
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

Matrix3x3 operator*(float s, Matrix3x3 m)
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
Vector operator*(Matrix3x3 m, Vector u)
{
	return Vector( m.e11*u.x + m.e12*u.y + m.e13*u.z,
								 m.e21*u.x + m.e22*u.y + m.e23*u.z,
								 m.e31*u.x + m.e32*u.y + m.e33*u.z);
}

Vector operator*(Vector u, Matrix3x3 m)
{
		return Vector( m.e11*u.x + m.e12*u.y + m.e13*u.z,
								 m.e21*u.x + m.e22*u.y + m.e23*u.z,
								 m.e31*u.x + m.e32*u.y + m.e33*u.z);
}

//Create a matrix from a quaternion
Matrix3x3 MakeMatrixFromQuaternion(Quaternion q)
{
	  float sqn = q.n*q.n;
    float sqx = q.v.x*q.v.x;
    float sqy = q.v.y*q.v.y;
    float sqz = q.v.z*q.v.z;
	
		float m00 = ( sqx - sqy - sqz + sqn);
    float m11 = (-sqx + sqy - sqz + sqn);
    float m22 = (-sqx - sqy + sqz + sqn);
	
	  float tmp1 = q.v.x*q.v.y;
    float tmp2 = q.v.z*q.n;
    float m10 = 2.0 * (tmp1 + tmp2);
    float m01 = 2.0 * (tmp1 - tmp2);
    
    tmp1 = q.v.x*q.v.z;
    tmp2 = q.v.y*q.n;
    float m20 = 2.0 * (tmp1 - tmp2);
    float m02 = 2.0 * (tmp1 + tmp2);
    tmp1 = q.v.y*q.v.z;
    tmp2 = q.v.x*q.n;
    float m21 = 2.0 * (tmp1 + tmp2);
    float m12 = 2.0 * (tmp1 - tmp2);   
	
		return Matrix3x3(m00, m01, m02, m10, m11, m12, m20, m21, m22);

}

