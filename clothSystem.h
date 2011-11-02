#ifndef CLOTHSYSTEM_H
#define CLOTHSYSTEM_H

#include <vecmath.h>
#include <vector>
#include <GL/glut.h>

#include "particleSystem.h"

class ClothSystem: public ParticleSystem
{
public:

    int w;
    float space;
    bool toggle;

	ClothSystem(char rule, float h, int ind);
	
	vector<Vector3f> evalF(vector<Vector3f> state);
	//adjacency matrix of the particles. the vector3f is distance, stiffness and rest length
    vector<vector<Vector3f> > struc;
    vector<vector<Vector3f> > shear;
    vector<vector<Vector3f> > flex;
	void draw();
	
};

#endif
