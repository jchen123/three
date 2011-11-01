#include "integrator.h"
#include<iostream>

using namespace std;

void Integrator::euler(ParticleSystem * p)
{
    vector<Vector3f> newState;
    vector<Vector3f> f0=p->evalF(p->state);
    for(int i=0; i<p->state.size();i++)
        newState.push_back(p->state[i]+p->h*f0[i]);
    p->setState(newState);
}

void Integrator::trapezoid(ParticleSystem * p)
{
    vector<Vector3f> newState;
    vector<Vector3f> f0=p->evalF(p->state);
    vector<Vector3f> incstate;
    for(int i=0; i<p->state.size();i++)
         incstate.push_back(p->state[i]+p->h*f0[i]);
    vector<Vector3f> f1=p->evalF(incstate);
    for(int i=0; i<p->state.size();i++)
        newState.push_back(p->state[i]+.5*p->h*(f0[i]+f1[i]));
    p->setState(newState);
}
