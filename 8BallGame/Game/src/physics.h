#ifndef PHYSICS_H
#define PHYSICS_H
#define _USE_MATH_DEFINES
//=================================
// forward declared dependencies
class Vector;
class Quaternion;
class Matrix3x3;

//=================================
// included dependencies
#include "vector.h"
#include "Quaternion.h"
#include "Matrix3x3.h"

//=================================
// Struct Definitions
typedef struct _RigidBody {
	float			fMass; //Total mass (constant)
	Matrix3x3 			mInertia; //Mass moment of inertia in body coordinates
	Matrix3x3       mInertiaInverse; //Inverse of mass moment of inertia matrix
	Vector			vPosition; //Position in earth coordinates
	Vector			vVelocity; //Velocity in earth coordinates
	Vector			vVelocityBody; //Velocity in body coordinates
	Vector			vAcceleration; //Acceleration of cg in earth space
	Vector			vAngularAcceleration; //Angular acceleration in body coordinates
	Vector			vAngularAccelerationGlobal; //Global angular acceleration
	
	Vector			vAngularVelocity; //Angular velocity in body coordinates
	Vector			vAngularVelocityGlobal; //Angular velocity in global coordinates
	Vector			vEulerAngles; //Euler angles in body coordinates
	float			  fSpeed; //Speed (magnitude) of the velocity
	Quaternion  qQuaternion; //Orientation in earth coordinates
	Vector		  vForces; //Total force on body
	Vector 			vMoments; //Totel moment (torque) on the body
	Matrix3x3		mIeInverse; //Inverse of moment of inertia in earth coordinates
	float				fRadius; //Ball radius
} RigidBody, *pRigidBody;

typedef struct _Collision {
	int			body1;
	int			body2;
	Vector	vCollsionNormal;
	Vector 	vCollsionPoint;
	Vector	vRelativeVelocity;
	Vector  vRelativeAcceleration;
	Vector  VCollisionTangent;
} Collision, *pCollision;

//Collision Check
enum {NOCOLLISION, COLLISION};

//=================================
// Global data definitions
#define   NUMBODIES									4
#define		BALLDIAMETER							0.05715f
#define		BALLWEIGHT								1.612f
#define		GRAVITY										-9.87f
#define		LINEARDRAGCOEFFICIENT			0.5f
#define		ANGULARDRAGCOEFFICIENT		0.05f
#define		FRICTIONFACTOR						0.5f
#define		COEFFICIENTOFRESTITUTION  0.8f
#define		COEFFICIENTOFRESTITUTIONGROUND 0.1f
#define		FRICTIONCOEFFICIENTBALLS      0.1f
#define		FRICTIONCOEFFICIENTGROUND     0.1f
#define   ROLLINGRESISTANCECOEFFICIENT  0.025f
#define   RHO                           1.225f
#define   PI                            3.141f


//=================================
// Global Variable Declarations
RigidBody			Bodies[NUMBODIES];
Collision     Collisons[NUMBODIES*8];
int           NumCollsions = 0;
#endif

