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
    static void euler(ParticleSystem * p);

    static void trapezoid(ParticleSystem * p);
};


#endif
