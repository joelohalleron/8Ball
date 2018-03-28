#include "Quaternion.h"
#include <math.h>

#define const float pi = 3.14159265358979323846

//Constructor no-args
inline Quaternion::Quaternion(void)
{
	n = 0;
	v.x = 0;
	v.y = 0;
	v.z = 0;
}

//Constructor with args
inline  Quaternion::Quaternion(float e0, float e1, float e2, float e3)
{
	n = e0;
	v.x = e1;
	v.y = e2;
	v.z = e3;
}

// Magnitude
inline float Quaternion::Magnitude(void)
{
	return (float) sqrt(n*n + v.x*v.x + v.y*v.y + v.z*v.z);
}	

// GetVector - returns vector part of the Quaternion
inline Vector Quaternion::GetVector(void)
{
	return Vector(v.x, v.y, v.z);
}

// GetScalar - returns the scalar part of the Quaternion
inline float Quaternion::GetScalar(void)
{
	return n;
}

// Quaternion addition - adds argument vector to the current vector values by element
inline Quaternion Quaternion::operator+=(Quaternion q)
{
	n += q.n;
	v.x += q.v.x;
	v.y += q.v.y;
	v.z += q.v.z;
	return *this;
}
	
// Quaternion subtraction - subtracts argument vector from current vector values by element
inline Quaternion Quaternion::operator-=(Quaternion q)
{
	n += q.n;
	v.x += q.v.x;
	v.y += q.v.y;
	v.z += q.v.z;
	return *this;
}

// Quaternion scalar multiplication - multiplies each element by the argument scalar
inline Quaternion Quaternion::operator*=(float s)
{
	  n *= s;
	v.x *= s;
	v.y *= s;
	v.z *= s;
	return *this;
}

// Quaternion scalar division - divides each element by the argument scalar
inline Quaternion Quaternion::operator/=(float s)
{
		n /= s;
	v.x /= s;
	v.y /= s;
	v.z /= s;
	return *this;
}

// Quaternion Functions and operators

//Conversion Functions
float DegreesToRadians(float deg)
{
	return (deg * 3.14159265358979323846)/180.0f;
}	

float RadiansToDegrees(float rad)
{
	return (rad * 180.0f)/3.14159265358979323846;
}	


// Two quaternion addition - adding two quaternions by element
Quaternion operator+(Quaternion q1, Quaternion q2)
{
	return Quaternion(q1.n + q2.n,
											q1.v.x + q2.v.x,
											q1.v.y + q2.v.y,
											q1.v.z + q2.v.z);
}

// Two quaternion subtraction - subtracting one quaternion from another
Quaternion operator-=(Quaternion q1, Quaternion q2)
{
	return Quaternion(q1.n - q2.n,
											q1.v.x - q2.v.x,
											q1.v.y - q2.v.y,
											q1.v.z - q2.v.z);
}

// Two Quaternion multplication - multiplied together
Quaternion operator*(Quaternion q1, Quaternion q2)
{
	return Quaternion(q1.n*q2.n - q1.v.x*q2.v.x
											- q1.v.y*q2.v.y - q1.v.z*q2.v.z,
										q1.n*q2.v.x + q1.v.x*q2.n
											+ q1.v.y*q2.v.z - q1.v.z*q2.v.y,
										q1.n*q2.v.y - q1.v.y*q2.n
											+ q1.v.z*q2.v.x - q1.v.x*q2.v.z,
										q1.n*q2.v.z + q1.v.z*q2.n
											+ q1.v.x*q2.v.y - q1.v.y*q2.v.x);
}

	




// Scalar division - divides each component by the scalar
Quaternion operator/(Quaternion q, float s)
{
	return Quaternion(q.n/s, q.v.x/s, q.v.y/s, q.v.z/s);
}

// QGetAngle - Returns a unit vector along the axis of rotation
float QGetAngle(Quaternion q)
{
	return (float) (2*acos(q.n));
}

// QGetAxis - Returns a unit vector along the axis of rotation represented by the vector part of the Quaternion
Vector QGetAxis(Quaternion q)
{
	Vector v;
	float m;
	float tol = 0.0001f;
	
	v = q.GetVector();
	m = q.Magnitude();
	
	if(m <= tol)
		return Vector();
	else
		return v/=m;
}



// QRotate - Rotates the quaternion by the argument quaternion 
Quaternion QRotate(Quaternion q1, Quaternion q2)
{
	return q1*q2*(~q1);
}

// QVRotate - Rotates a vector by a unit quaternion
Vector Quaternion::QVRotate(Quaternion q, Vector v)
{
	Quaternion t;
	
	t = q*v*(q);
	
	return t.GetVector();
}

// MakeQFromEulerAngles - Constructs a Quaternion from a set of euler angles (yaw, pitch and roll) about the z axis
Quaternion Quaternion::MakeQFromEulerAngles(float x, float y, float z)
{
	Quaternion q;
	double roll = DegreesToRadians(x);
	double pitch = DegreesToRadians(y);
	double yaw = DegreesToRadians(z);
	
	double cyaw, cpitch, croll, syaw, spitch, sroll;
	double cyawcpitch, syawspitch, cyawspitch, syawcpitch;
	
	cyaw = cos(0.5f * yaw);
	cpitch = cos(0.5f * pitch);
	croll = cos(0.5f * roll);
	
	syaw = sin(0.5f * yaw);
	spitch = sin(0.5f * pitch);
	sroll = sin(0.5f * roll);
	
	cyawcpitch = cyaw*cpitch;
	syawspitch = syaw*spitch;
	cyawspitch = cyaw*spitch;
	syawcpitch = syaw*cpitch;
	
	q.n = (float) (cyawcpitch * croll + syawspitch*sroll);
	q.v.x = (float) (cyawcpitch * sroll - syawspitch * croll);
	q.v.y = (float) (cyawspitch * croll + syawcpitch * sroll);
	q.v.z = (float) (syawcpitch * croll - cyawspitch * sroll);
	
	return q;
}

// Make Euler angles (yaw, pitch and roll) based on a quaternion
Vector Quaternion::MakeEulerAnglesFromQ(Quaternion q)
{
	double r11, r21, r31, r32, r33, r12, r13;
	double q00, q11, q22, q33;
	double tmp;
	Vector u;
	
	q00 = q.n * q.n;
	q11 = q.v.x * q.v.x;
	q22 = q.v.y * q.v.y;
	q33 = q.v.z * q.v.z;
	
	r11 = q00 + q11 - q22- q33;
	r21 = 2 * (q.v.x*q.v.y + q.n*q.v.z);
	r31 = 2 * (q.v.x*q.v.z - q.n*q.v.y);
	r32 = 2*  (q.v.y*q.v.z + q.n*q.v.x);
	r33 = q00 - q11 - q22 + q33;
	
	tmp = fabs(r31);
	if(tmp > 0.999999)
	{
		r12 = 2 * (q.v.x*q.v.y - q.n*q.v.z);
		r13 = 2 * (q.v.x*q.v.z + q.n*q.v.y);
		
		u.x = RadiansToDegrees(0.0f); //roll
		u.y = RadiansToDegrees((float) (-(3.14159265358979323846/2) * r31/tmp)); //pitch
		u.z = RadiansToDegrees((float) (atan2(-r12, -r31*r13))); //yaw
	}
	
	u.x = RadiansToDegrees((float) atan2(r32, r33)); //roll
	u.y = RadiansToDegrees((float) asin(-r31));      //pitch
	u.z = RadiansToDegrees((float) atan2(r21, r11)); //yaw
	
	return u;
}

// Vector multiplication - vector by quaternion multiplication
// Two types for different encounter order
Quaternion operator*(Quaternion q, Vector v)
{
	return Quaternion(   -(q.v.x*v.x + q.v.y*v.y + q.v.z*v.z),
													q.n*v.x + q.v.y*v.z - q.v.z*v.y,
													q.n*v.y +q.v.z*v.x - q.v.x*v.z,
												  q.n*v.z + q.v.x*v.y - q.v.y*v.x);
}

Quaternion operator*(Vector v, Quaternion q)
{
	return Quaternion(   -(q.v.x*v.x + q.v.y*v.y + q.v.z*v.z),
													q.n*v.x + q.v.y*v.z - q.v.z*v.y,
													q.n*v.y +q.v.z*v.x - q.v.x*v.z,
												  q.n*v.z + q.v.x*v.y - q.v.y*v.x);
}

// Scalar multiplication - multiplies each element in the Quaternion by the scalar
// Two types for different encounter order
Quaternion operator*(Quaternion q, float s)
{
	return Quaternion(q.n*s, q.v.x*s, q.v.y*s, q.v.z*s);
}

Quaternion operator*(float s, Quaternion q)
{
	return Quaternion(q.n*s, q.v.x*s, q.v.y*s, q.v.z*s);
}
	
