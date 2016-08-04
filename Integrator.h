#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include <omp.h>
#include "Particle.h"
#include "Tree.h"

class Integrator{
  public:
    Particle* p;
    int n_particles;

    Integrator(Particle* _p, int _n_particles);
    ~Integrator() {}

    void update_particles(int step_num, Tree* tree, double dt);
};

#endif
