#ifndef PENDULUMSYSTEM_H
#define PENDULUMSYSTEM_H

#include <vecmath.h>
#include <vector>
#include <GL/glut.h>

#include "particleSystem.h"

class PendulumSystem: public ParticleSystem
{
public:
	PendulumSystem(char rule, float h);
	
	vector<Vector3f> evalF(vector<Vector3f> state);
	//adjacency matrix of the particles. the vector3f is distance, stiffness and rest length
    vector<vector<Vector3f> > adjmat;
	void draw();
	
};

#endif
