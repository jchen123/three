#include "integrator.h"

using namespace std;

vector<Vector3f> Integrator::Euler(vector<Vector3f> state,vector<Vector3f> force, double h)
{
    vector<Vector3f> newState;
    for(int i=0; i<state.size();i++)
    {
        Vector3f v(state[i][0]+h*force[i][0],state[i][1]+h*force[i][1],state[i][2]+h*force[i][2]);
        newState.push_back(v);
    }
    return newState;
}
/*
//unimplemented
vector<Vector3f> Integrator::Trapezoid(vector<Vector3f> state,vector<Vector3f> force, double h)
{
    vector<Vector3f> newState;
    for(int i=0; i<state.size();i++)
    {
        Vector3f v(state[i][0]+h*force[i][0],state[i][1]+h*force[i][1],state[i][2]+h*force[i][2]);
        newState.push_back(v);
    }
    return newState;
}*/
