#include "Physics.h"

//=================================
// Function definitions

void InitialiseObjects(int configuration)
{
	float			iRoll, iPitch, iYaw;
	int				i;
	float			Ixx, Iyy, Izz;
	float			s;
	
	////////////////////////////////////////
	//Initialise cue ball
	//Set initial position
	Bodies[0].vPosition.x = -BALLDIAMETER*50.0f;
	Bodies[0].vPosition.y = 0.0f;
	Bodies[0].vPosition.z =	BALLDIAMETER/2.0f;
	
	//Set initial velocity
	s = 7.0;
	Bodies[0].vVelocity.x = s;
	Bodies[0].vVelocity.y = 0.0f;
	Bodies[0].vVelocity.z = 0.0f;
	Bodies[0].fSpeed = s;
	
	//Set initial angular velocity
	Bodies[0].vAngularVelocity.x = 0.0f; // rotate about long'l axis
	Bodies[0].vAngularVelocity.y = 0.0f; // rotate about transverse axis
	Bodies[0].vAngularVelocity.z = 0.0f; //rotate about vertical axis
	
	//Set initial angular acceleration
	Bodies[0].vAngularAcceleration.x = 0.0f;
	Bodies[0].vAngularAcceleration.y = 0.0f;
	Bodies[0].vAngularAcceleration.z = 0.0f;
	
	//Set initial earth space acceleration
	Bodies[0].vAcceleration.x = 0.0f;
	Bodies[0].vAcceleration.y = 0.0f;
	Bodies[0].vAcceleration.z = 0.0f;
	
	// Set the initial forces and moments
	Bodies[0].vForces.x = 0.0f;
	Bodies[0].vForces.y = 0.0f;
	Bodies[0].vForces.z = 0.0f;
	
	Bodies[0].vMoments.x = 0.0f;
	Bodies[0].vMoments.y = 0.0f;
	Bodies[0].vMoments.z = 0.0f;
	
	//Zero the velocity in body space coordinates
	Bodies[0].vVelocityBody.x = 0.0f;
	Bodies[0].vVelocityBody.y = 0.0f;
	Bodies[0].vVelocityBody.z = 0.0f;
	
	//Set the initial orientation
	iRoll = 0.0f;
	iPitch = 0.0f;
	iYaw = 0.0f;
	Bodies[0].qQuaternion = Bodies[0].qQuaternion.MakeQFromEulerAngles(iRoll, iPitch, iYaw);
	
	//Set the mass properties
	Bodies[0].fMass = BALLWEIGHT/(GRAVITY);
	
	Ixx = 2.0f * Bodies[0].fMass / 5.0f *(BALLDIAMETER/2*BALLDIAMETER/2);
	Izz = Iyy = Ixx;
	
	Bodies[0].mInertia.e11 = Ixx;
	Bodies[0].mInertia.e12 = 0;
	Bodies[0].mInertia.e13 = 0;
	Bodies[0].mInertia.e21 = 0;
	Bodies[0].mInertia.e22 = Iyy;
	Bodies[0].mInertia.e23 = 0;
	Bodies[0].mInertia.e31 = 0;
	Bodies[0].mInertia.e32 = 0;
	Bodies[0].mInertia.e33 = Izz;
	
	Bodies[0].mInertiaInverse = Bodies[0].mInertia.Inverse();
	
	Bodies[0].fRadius = BALLDIAMETER/2;
	
	////////////////////////////////////////
	//Initialise other balls
	for(i=1; i<NUMBODIES; i++)
	{
		if(i==1)
		{
			Bodies[i].vPosition.x = 0.0;
			Bodies[i].vPosition.y = -(BALLDIAMETER/2.0f+0.25*BALLDIAMETER);
			Bodies[i].vPosition.x = BALLDIAMETER/2.0f;
		}
		else if(i==2)
		{
			Bodies[i].vPosition.x = 0.0;
			Bodies[i].vPosition.y = BALLDIAMETER/2.0f+0.25*BALLDIAMETER;
			Bodies[i].vPosition.x = BALLDIAMETER/2.0f;
		}
		else{
			Bodies[i].vPosition.x = -BALLDIAMETER;
			Bodies[i].vPosition.y = 0.0f;
			Bodies[i].vPosition.x = BALLDIAMETER/2.0f;
		}
	
	
	//Set initial velocity
	Bodies[i].vVelocity.x = 0.0f;
	Bodies[i].vVelocity.y = 0.0f;
	Bodies[i].vVelocity.z = 0.0f;
	Bodies[i].fSpeed = 0.0f;
	
	//Set initial angular velocity
	Bodies[i].vAngularVelocity.x = 0.0f; // rotate about long'l axis
	Bodies[i].vAngularVelocity.y = 0.0f; // rotate about transverse axis
	Bodies[i].vAngularVelocity.z = 0.0f; //rotate about vertical axis
		
	//Set initial angular acceleration
	Bodies[i].vAngularAcceleration.x = 0.0f;
	Bodies[i].vAngularAcceleration.y = 0.0f;
	Bodies[i].vAngularAcceleration.z = 0.0f;
		
	//Set initial earth space acceleration
	Bodies[i].vAcceleration.x = 0.0f;
	Bodies[i].vAcceleration.y = 0.0f;
	Bodies[i].vAcceleration.z = 0.0f;
	
	// Set the initial forces and moments
	Bodies[i].vForces.x = 0.0f;
	Bodies[i].vForces.y = 0.0f;
	Bodies[i].vForces.z = 0.0f;
	
	Bodies[i].vMoments.x = 0.0f;
	Bodies[i].vMoments.y = 0.0f;
	Bodies[i].vMoments.z = 0.0f;
	
	//Zero the velocity in body space coordinates
	Bodies[i].vVelocityBody.x = 0.0f;
	Bodies[i].vVelocityBody.y = 0.0f;
	Bodies[i].vVelocityBody.z = 0.0f;
	
	//Set the initial orientation
	iRoll = 0.0f;
	iPitch = 0.0f;
	iYaw = 0.0f;
	Bodies[i].qQuaternion = Bodies[i].qQuaternion.MakeQFromEulerAngles(iRoll, iPitch, iYaw);
	
	//Set the mass properties
	Bodies[i].fMass = BALLWEIGHT/(GRAVITY);
	
	Ixx = 2.0f * Bodies[i].fMass / 5.0f *(BALLDIAMETER/2*BALLDIAMETER/2);
	Izz = Iyy = Ixx;
	
	Bodies[i].mInertia.e11 = Ixx;
	Bodies[i].mInertia.e12 = 0;
	Bodies[i].mInertia.e13 = 0;
	Bodies[i].mInertia.e21 = 0;
	Bodies[i].mInertia.e22 = Iyy;
	Bodies[i].mInertia.e23 = 0;
	Bodies[i].mInertia.e31 = 0;
	Bodies[i].mInertia.e32 = 0;
	Bodies[i].mInertia.e33 = Izz;
	
	Bodies[i].mInertiaInverse = Bodies[i].mInertia.Inverse();
	
	Bodies[i].fRadius = BALLDIAMETER/2;
}
	
	
}

void CalcObjectForces(void)
{
	Vector			Fb, Mb;
	Vector			vDragVector;
	Vector			vAngularDragVector;
	int         i, j;
	Vector 			ContactForce;
	Vector 			pt;
	int					check = NOCOLLISION;
	pCollision  pCollisionData;
	Vector 			FrictionForce;
	Vector      fDir;
	double      speed;
	Vector      FRn, FRt;
	
	for(i=0; i<NUMBODIES; i++)
	{
		//Reset forces and moments
		Bodies[i].vForces.x = 0.0f;
		Bodies[i].vForces.y = 0.0f;
		Bodies[i].vForces.z = 0.0f;
		
		Bodies[i].vMoments.x = 0.0f;
		Bodies[i].vMoments.y = 0.0f;
		Bodies[i].vMoments.z = 0.0f;
		
		Fb.x = 0.0f;			Mb.x = 0.0f;
		Fb.y = 0.0f;			Mb.y = 0.0f;
		Fb.z = 0.0f;			Mb.z = 0.0f;
		
		//Do Drag forces
		vDragVector = -Bodies[i].vVelocityBody;
		vDragVector.Normalise();
		speed = Bodies[i].vVelocityBody.Magnitude();
		Fb += vDragVector * ((1.0f/2.0f) * speed * speed * RHO * /////////////////POTENTIAL FUALTY CODE (Should be * not *= ?)////////////////////
					LINEARDRAGCOEFFICIENT * pow(Bodies[i].fRadius, 2) *
					Bodies[i].fRadius*PI);
		
		vAngularDragVector = -Bodies[i].vAngularVelocity;
		vAngularDragVector.Normalise();
		float dragFactor = Bodies[i].vAngularVelocity.Magnitude() *
		      Bodies[i].vAngularVelocity.Magnitude() * RHO * ANGULARDRAGCOEFFICIENT
					* 4 * pow(Bodies[i].fRadius, 2)*PI;
		Mb +=  vAngularDragVector * dragFactor;
	}
	
}

