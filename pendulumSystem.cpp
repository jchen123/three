#include<ctime>
#include "pendulumSystem.h"
#include<iostream>

PendulumSystem::PendulumSystem(char rule, float h):ParticleSystem(rule, h)
{
    this->h=h;
    this->rule=rule;
	this->numParticles = 5;
	srand((unsigned)time(0));
    // fill in code for initializing the state based on the number of particles
	for (int i = 0; i < numParticles; i++) {
        this->state.push_back(Vector3f(rand()/(float)RAND_MAX,rand()/(float)RAND_MAX,0));
        this->state.push_back(Vector3f(0,0,0));
	}
    float k=0.2;
    for(int a=0; a<numParticles;a++)
    {
        vector<Vector3f> v;
        for(int b=0; b<numParticles;b++)
        {
            if(a==b) v.push_back(Vector3f(-1,0,0));
            else v.push_back(Vector3f(1,k,0));//(state[2*b]-state[2*a]).abs()));
        }
        adjmat.push_back(v);
    }
}


// TODO: implement evalF
// for a given state, evaluate f(X,t)
vector<Vector3f> PendulumSystem::evalF(vector<Vector3f> state)
{
	vector<Vector3f> f;
    /*
    for(int a=0; a<numParticles;a++)
    {
         for(int b=0; b<numParticles;b++)
         {
              cout<<adjmat[a][b][0]<<" "<<adjmat[a][b][1]<<" "<<adjmat[a][b][2]<<" ";
         }
         cout<<endl;
    }*/
    float m=.2;
    float g=9.8;
    float k=.1;
    //calculate drag
    //calculate spring tension
    //calculate gravity
    for(int i=0; i<state.size();i+=2)
    {
        f.push_back(state[i+1]);
        //sum the forces together
        Vector3f forces(0,0,0);
        //gravity
        //forces[1]-=m*g;
        //viscous drag
        forces-=k*state[i+1];
        //forces from the thing thangs yo
        for(int n=0; n<numParticles;n++)
        {
            if(adjmat[i/2][n][0]!=-1)
            {
                float dist=(state[i]-state[2*n]).abs();
                forces+=-adjmat[i/2][n][1]*(dist-adjmat[i/2][n][2])/dist*(-state[2*n]+state[i]);
            }
        }
        f.push_back(forces);
    }
	return f;
}

// render the system (ie draw the particles)
void PendulumSystem::draw()
{
	for (int i = 0; i < numParticles*2; i+=2) {
		Vector3f pos=state[i]; //  position of particle i
		glPushMatrix();
		glTranslatef(pos[0], pos[1], pos[2] );
		glutSolidSphere(0.075f,10.0f,10.0f);
		glPopMatrix();
	}
}
