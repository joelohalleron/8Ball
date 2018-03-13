#include "vector.h" 

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
		//This simply returns the negative of the vector part (conjugate)
		Quaternion operator~(void) const { return Quaternion(n,
																												 -v.x,
																												 -v.y,
																												 -v.z);}
};
		