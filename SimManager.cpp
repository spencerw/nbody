#include "SimManager.h"

SimManager::SimManager(int _n_particles) {
  n_particles = _n_particles;
  p = new Particle[n_particles];
  integrator = new Integrator(p, n_particles);
  step_num = 0.;
  time = 0.;
}

SimManager::~SimManager() {
  delete [] p;
  delete integrator;
}

Particle* SimManager::get_particle(int idx) {
  if (idx < 0 || idx >= n_particles) {
    std::cerr << "Particle index " << idx << " invalid" << std::endl;
    std::exit(-1);
  }

  return &p[idx];
}

void SimManager::evolve(double dt) {
  integrator->update_particles(dt);
  time += dt;
  step_num++;
}
