#include "particleSystem.h"
#include "integrator.h"
#include <iostream>
ParticleSystem::ParticleSystem()
{
     
}

ParticleSystem::ParticleSystem(int i)
{
     

}

// step the system according to your integrator function
void ParticleSystem::stepSystem(float h)
{
    state=Integrator::Euler(state,evalF(state),h);
}
	
	// for a given state, evaluate f(X,t)
vector<Vector3f> ParticleSystem::evalF(vector<Vector3f> state)
{
     
}

vector<Vector3f> ParticleSystem::getState()
{
    return state;
}

void ParticleSystem::setState(vector<Vector3f> newState)
{
     state=newState;
}
