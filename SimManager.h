#ifndef SIM_MANAGER_H
#define SIM_MANAGER_H

#include "Integrator.h"
#include "Particle.h"
#include "Tree.h"

class SimManager {
  private:
    int n_particles;
    int step_num;
    double time;
    Integrator* integrator;

  public:
    Particle* p;
    SimManager();
    ~SimManager();
    void evolve(Tree* tree, double dt);
    int get_n_particles() { return n_particles; }
    int get_step_num() { return step_num; }
    double get_time() { return time; }
    void allocate_particles(int _n_particles);
};

#endif
