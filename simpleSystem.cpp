#include <cstdio>
#include <iostream>
#include "simpleSystem.h"

using namespace std;

SimpleSystem::SimpleSystem(int i)
{
    state.push_back(Vector3f(0,1,0));
    state.push_back(Vector3f(1,0,0));
}

// TODO: implement evalF
// for a given state, evaluate f(X,t)
vector<Vector3f> SimpleSystem::evalF(vector<Vector3f> state)
{
    vector<Vector3f> f;
	for(int i=0; i<state.size();i++)
    {
        Vector3f conversion(-state[i][1],state[i][0],0);
        f.push_back(conversion);
    }
	return f;
}

// render the system (ie draw the particles)
void SimpleSystem::draw()
{
    for(int i=0; i<state.size();i++)
    {
		Vector3f pos=state[i];//YOUR PARTICLE POSITION
	    glPushMatrix();
		glTranslatef(pos[0], pos[1], pos[2] );
		glutSolidSphere(0.075f,10.0f,10.0f);
		glPopMatrix();
    }
}
