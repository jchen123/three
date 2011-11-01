
#include "pendulumSystem.h"

/*PendulumSystem::PendulumSystem(int numParticles):ParticleSystem(numParticles)
{
	this->numParticles = numParticles;
	
	// fill in code for initializing the state based on the number of particles
	for (int i = 0; i < numParticles; i++) {
		
		// for this system, we care about the position and the velocity

	}
}*/


// TODO: implement evalF
// for a given state, evaluate f(X,t)
vector<Vector3f> PendulumSystem::evalF(vector<Vector3f> state)
{
	vector<Vector3f> f;

	// YOUR CODE HERE

	return f;
}

// render the system (ie draw the particles)
void PendulumSystem::draw()
{
	for (int i = 0; i < numParticles; i++) {
		Vector3f pos(0,0,0); //  position of particle i
		glPushMatrix();
		glTranslatef(pos[0], pos[1], pos[2] );
		glutSolidSphere(0.075f,10.0f,10.0f);
		glPopMatrix();
	}
}
