#ifndef SIM_MANAGER_H
#define SIM_MANAGER_H

#include "Integrator.h"
#include "Particle.h"

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
    void evolve(double dt);
    int get_n_particles() { return n_particles; }
    int get_step_num() { return step_num; }
    double get_time() { return time; }
    Particle* get_particle(int idx);
    void allocate_particles(int _n_particles);
};

#endif
