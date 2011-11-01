#include "particleSystem.h"
#include "integrator.h"
#include <iostream>
ParticleSystem::ParticleSystem()
{
     
}

ParticleSystem::ParticleSystem(char rule, float h)
{
    this->rule=rule;
    this->h=h;    
}

// step the system according to your integrator function
void ParticleSystem::stepSystem()
{
    if(this->rule=='t')
        Integrator::trapezoid(this);
    else if(this->rule=='e')
        Integrator::euler(this);
    else cout<<"dog u got bad parameterz yo"<<endl;
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
