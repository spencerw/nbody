#include "SimManager.h"

SimManager::SimManager() {
  n_particles = -1;
  step_num = 0.;
  time = 0.;
}

SimManager::~SimManager() {
  delete [] p;
  delete integrator;
}

void SimManager::evolve(Tree* tree, double dt) {
  if (n_particles == -1) {
    std::cerr << "Particles not initalized" << std::endl;
  }

  integrator->update_particles(tree, dt);
  time += dt;
  step_num++;
}

void SimManager::allocate_particles(int _n_particles) {
  n_particles = _n_particles;
  p = new Particle[n_particles];
  integrator = new Integrator(p, n_particles);
}
