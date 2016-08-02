#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include "Particle.h"
#include "Tree.h"

class Integrator{
  public:
    Particle* p;
    int n_particles;

    Integrator(Particle* _p, int _n_particles);
    ~Integrator() {}

    void update_particles(Tree* tree, double dt);
};

#endif
