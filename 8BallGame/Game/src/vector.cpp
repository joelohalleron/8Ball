#include <math.h>

//--------------------------------------------------------------------------------------------------------------------------------------
//Vector class and vector functions
//--------------------------------------------------------------------------------------------------------------------------------------
class Vector {
	public: 
		float x;
		float y;
		float z;
	
	Vector(void);
	Vector(float xi, float yi, float zi);
	
	float Magnitude(void);
	void Normalise(void);
	void Reverse(void);
	
	Vector& operator+=(Vector u);
	Vector& operator-=(Vector u);
	Vector& operator*=(float s);
	Vector& operator/=(float s);
	
	Vector operator-(void);
};

//Constructor no arguments
inline Vector::Vector(void)
{
	x=0;
	y=0;
	z=0;
}

//Constructor with defined arguments
inline Vector::Vector(float xi, float yi, float zi)
{
	x=xi;	
	y=yi;
	z=zi;
}	

//Magnitude
inline float Vector::Magnitude(void)
{
	return(float) sqrt(x*x + y*y +z*z);
}	

//Normalise
inline void Vector::Normalise(void)
{
	float const tol = 0.0001f;
	float m = (float) sqrt(x*x + y*y +z*z);
	if(m<=tol) m=1;
	x /= m;
	y /= m;
	z /= m;
	
	if(fabs(x) < tol) x = 0.0f;
	if(fabs(y) < tol) y = 0.0f;
	if(fabs(z) < tol) z = 0.0f;	
}	


//Reverses values of x, y and z
inline void Vector::Reverse(void)
{
	x = -x;
	y = -y;
	z = -z;
}

//+= Operator for vector addition
inline Vector& Vector::operator+=(Vector u)
{
	x += u.x;
	y += u.x;
	z += u.x;
	return *this;
}

//-= Operator for Vector subtraction 
inline Vector& Vector::operator-=(Vector u)
{
	x -= u.x;
	y -= u.y;
	z -= u.z;
	return *this;
}

//*= Operator for Scalar multiplication
inline Vector& Vector::operator*=(float s)
{
	x *= s;
	y *= s;
  z *= s;	
	return *this;
}

//  /= Operator for Scalar division
inline Vector& Vector::operator/=(float s)
{
	x /= s;
	y /= s;
	z /= s;
	return *this;
}	

//Conjugate - takes the negative of each vector component 
inline Vector Vector::operator-(void)
{
	return Vector(-x, -y, -z);
}

//Vector functions and operators

// Adds vector v to vector u
inline Vector operator+(Vector v, Vector u)
{
	return Vector(u.x + v.x, u.y + v.y, u.z + v.z);
}	

// Subtracts vector v from vector u
inline Vector operator-(Vector v, Vector u)
{
	return Vector(u.x - v.x, u.y - v.y, u.z - v.z);
}	

// Cross product of vector v and u
inline Vector operator^(Vector u, Vector v)
{
	return Vector(u.y*v.z - u.z*v.y,
								-u.x*v.z + u.z*v.x,
								u.x*v.y - u.y*v.x);
	
}	

// Dot product of vector v and u (element by element multiplication)
inline float operator*(Vector u, Vector v)
{
	return (u.x*v.x + u.y*v.y + u.z*v.z);
}

// Scalar multiplication
inline Vector operator*(float s, Vector u)
{
	return Vector(u.x*s, u.y*s, u.z*s);
}	

inline Vector operator*(Vector u, float s)
{
	return Vector(u.x*s, u.y*s, u.z*s);
}	

// Triple scalar product
inline float TripleScalarProduct(Vector u, Vector v, Vector w)
{
	return float(	(u.x * (v.y*w.z - v.z*w.y)) +
								 (u.y * (-v.x*w.z + v.z*w.x)) +
								 (u.z * (v.x*w.y - v.y*w.x)) );
	
}
