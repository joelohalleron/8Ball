#ifndef VECTOR_CPP
#define VECTOR_CPP
//Vector Class definition and function prototypes
class Vector{
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

// Scalar multiplication
inline Vector operator*(float s, Vector u) 
{
	return Vector(u.x*s, u.y*s, u.z*s);
}	

inline Vector operator*(Vector u, float s)
{
	return Vector(u.x*s, u.y*s, u.z*s);
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

//Scalar Division the / Operator
inline Vector operator/(Vector u, float s)
{
	return Vector(u.x/s, u.y/s, u.z/s);
}


// Triple scalar product
inline float TripleScalarProduct(Vector u, Vector v, Vector w)
{
	return float(	(u.x * (v.y*w.z - v.z*w.y)) +
								 (u.y * (-v.x*w.z + v.z*w.x)) +
								 (u.z * (v.x*w.y - v.y*w.x)) );
	
}

#endif

