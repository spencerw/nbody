#ifndef PHYSICS_H
#define PHYSICS_H

#include "Particle.h"

class Physics {
  public:
    double epsilon;
    Physics(double _epsilon);
    ~Physics() {}
    Vector3D<double> grav_force(Vector3D<double> pos1, double mass1, Vector3D<double> pos2, double mass2);
};

#endif
