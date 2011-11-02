#include<ctime>
#include "clothSystem.h"
#include<iostream>
#include<cmath>

ClothSystem::ClothSystem(char rule, float h, int ind):ParticleSystem(rule, h, ind)
{
    this->h=h;
    this->toggle=false;
    this->rule=rule;
    this->ind=ind;
	this->numParticles = 0;
    this->w=10;
    this->space=.2;
    //create points
    for(double h=0;h>-1*space*w;h-=space)
    {
        for(double d=0;d<space*w;d+=space)
        {
            this->numParticles++;
            this->state.push_back(Vector3f(d,h,0));
            this->state.push_back(Vector3f(0,0,0));
        }
    }
    
    //do struct
    for(int a=0; a<numParticles;a++)
    {
        vector<Vector3f> v;
        for(int b=0; b<numParticles;b++)
        {
            if(a==b||a==0||a==w-1) 
                v.push_back(Vector3f(-1,0,0));
            else
            {
                if(b==a-w||b==a+w||b==a-1&&a%w!=0||b==a+1&&(a+1)%w!=0)
                    v.push_back(Vector3f(1,30,space));
                else v.push_back(Vector3f(-1,0,0));
            }
        }
        struc.push_back(v);
    }

    //do shear
    for(int a=0; a<numParticles;a++)
    {
        vector<Vector3f> v;
        for(int b=0; b<numParticles;b++)
        {
            if(a==b||a==0||a==w-1) 
                v.push_back(Vector3f(-1,0,0));
            else
            {
                if(a%w!=0&&b==a-(w+1)||(a+1)%w!=0&&b==a-(w-1)||(a+1)%w!=0&&b==a+w+1||a%w!=0&&b==a+(w-1))
                    v.push_back(Vector3f(1,30,pow(2*space*space,.5)));
                else v.push_back(Vector3f(-1,0,0));
            }
        }
        shear.push_back(v);
    }

    //do flex
    for(int a=0; a<numParticles;a++)
    {
        vector<Vector3f> v;
        for(int b=0; b<numParticles;b++)
        {
            if(a==b||a==0||a==w-1) 
                v.push_back(Vector3f(-1,0,0));
            else
            {
                if(a%w>1&&b==a-2||a%w<w-2&&b==a+2||b==a+2*w||b==a-2*w)
                    v.push_back(Vector3f(1,22.8,2*space));
                else v.push_back(Vector3f(-1,0,0));
            }
        }
        flex.push_back(v);
    }
}


// for a given state, evaluate f(X,t)
vector<Vector3f> ClothSystem::evalF(vector<Vector3f> state)
{
	vector<Vector3f> f;
    float m=.02;
    float g=9.8;
    float k=.02;
    
    //calculate forces
    for(int i=0; i<state.size();i+=2)
    {
        //anchors
        if(i/2==0||i/2==w-1)
        {
            if(!toggle)
            {
                f.push_back(Vector3f(0,0,0));
                f.push_back(Vector3f(0,0,0));
                continue;
            }
            f.push_back(state[i+1]);
            if(state[i][2]<=-1*space*w||state[i][2]>=space*w)
                f.push_back(Vector3f(0,0,-.05));
            else f.push_back(Vector3f(0,0,.05));
            continue;
        }
        f.push_back(state[i+1]);
        Vector3f forces(0,0,0);
        //gravity
        forces[1]-=m*g;
        //viscous drag
        forces-=k*state[i+1];
        for(int n=0; n<numParticles;n++)
        {
            float dist=(state[i]-state[2*n]).abs();
            //struct
            if(struc[i/2][n][0]!=-1)
                forces+=-struc[i/2][n][1]*(dist-struc[i/2][n][2])/dist*(-state[2*n]+state[i]);
            //shear
            if(shear[i/2][n][0]!=-1)
                forces+=-shear[i/2][n][1]*(dist-shear[i/2][n][2])/dist*(-state[2*n]+state[i]);
            //flex
            if(flex[i/2][n][0]!=-1)
                forces+=-flex[i/2][n][1]*(dist-flex[i/2][n][2])/dist*(-state[2*n]+state[i]);
        }
        f.push_back(forces);
    }
	return f;
}

// render the system (ie draw the particles)
void ClothSystem::draw()
{
	for (int i = 0; i < numParticles; i++) 
    {
		Vector3f pos=state[2*i]; //  position of particle i
		glPushMatrix();
		glTranslatef(pos[0], pos[1], pos[2] );
		glutSolidSphere(0.03f,10.0f,10.0f);
		glPopMatrix();
        for(int n=0; n<numParticles;n++)
        {
            if(!(ind==-1||n==ind)) continue;
            if(flex[i][n][0]==1)
            {
                glBegin(GL_LINES);
                glVertex3f(state[2*i][0],state[2*i][1],state[2*i][2]);
                glVertex3f(state[2*n][0],state[2*n][1],state[2*n][2]);
                glEnd();
            }
            if(struc[i][n][0]==1)
            {
                glBegin(GL_LINES);
                glVertex3f(state[2*i][0],state[2*i][1],state[2*i][2]);
                glVertex3f(state[2*n][0],state[2*n][1],state[2*n][2]);
                glEnd();
            }
            if(shear[i][n][0]==1)
            {
                glBegin(GL_LINES);
                glVertex3f(state[2*i][0],state[2*i][1],state[2*i][2]);
                glVertex3f(state[2*n][0],state[2*n][1],state[2*n][2]);
                glEnd();
            }
        }

	}
}
