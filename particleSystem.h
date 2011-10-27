#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include <vector>
#include <vecmath.h>

using namespace std;

class ParticleSystem
{
public:

	// YOUR CONSTRUCTOR
    ParticleSystem(int i);
	
    ParticleSystem();

	int numParticles;

    vector<Vector3f> state;

	// step the system according to your integrator function
	virtual void stepSystem(float h);
	
	// for a given state, evaluate f(X,t)
	virtual vector<Vector3f> evalF(vector<Vector3f> state) = 0;
	
	// getter method for the system's state
	vector<Vector3f> getState();
	
	// setter method for the system's state
	void setState(vector<Vector3f> newState);
	
	virtual void draw() = 0;
	
protected:

};

#endif
