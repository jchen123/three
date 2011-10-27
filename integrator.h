#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include "vecmath.h"
#include <vector>
#include "particleSystem.h"

using namespace std;

//YOUR INTEGRATORS
class Integrator
{
public:
    static vector<Vector3f> Euler(vector<Vector3f> state, vector<Vector3f> force, double h);

    //static vector<Vector3f> Trapezoid(vector<Vector3f> state,vector<Vector3f> force, double h);
};


#endif
