//Vector Class definition and function prototypes
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
