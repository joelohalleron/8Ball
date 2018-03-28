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
#include "Vector.h"
#include "Quaternion.h"
#include "Matrix3x3.h"
#include <assert.h>
#include <stdio.h>

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
	Quaternion  qOrientation; //Orientation in earth coordinates
	Vector		  vForces; //Total force on body
	Vector 			vMoments; //Totel moment (torque) on the body
	Matrix3x3		mIeInverse; //Inverse of moment of inertia in earth coordinates
	float				fRadius; //Ball radius
} RigidBody, *pRigidBody;

typedef struct _Collision {
	int			body1;
	int			body2;
	Vector	vCollisionNormal;
	Vector 	vCollisionPoint;
	Vector	vRelativeVelocity;
	Vector  vRelativeAcceleration;
	Vector  vCollisionTangent;
} Collision, *pCollision;


//Collision Checks
typedef enum {NOCOLLISION = 0, COLLISION, CONTACT, DOCONTACT} collision_t;

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
#define   COLLISIONTOLERANCE            0.5f   //Can be tuned based on results
#define   VELOCITYTOLERANCE             0.2f   //Can be tuned based on results
#define   DOFRICTION                    true
	

//=================================
// Global Variable Declarations
RigidBody			Bodies[NUMBODIES];
Collision     Collisions[NUMBODIES*8];
int           NumCollisions = 0;
#endif

