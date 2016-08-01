#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include "Particle.h"

class Integrator{
  public:
    Particle* particles;
    int n_particles;
    double epsilon;

    Integrator(Particle* _particles, int _n_particles);
    ~Integrator() {}

    void update_particles(double dt);
};

#endif
