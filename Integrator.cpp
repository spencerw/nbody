#include "Integrator.h"

Integrator::Integrator(Particle* _p, int _n_particles) {
  p = _p;
  n_particles = _n_particles;
}

void Integrator::update_particles(Tree* tree, double dt) {
  std::cout << "Integrating step..." << std::endl;
  int i;

  // Update velocities
  for (i = 0; i < n_particles; i++) {
    std::cout << "Update velocity of particle " << i << std::endl;
    Vector3D<double> force = tree->force_on(&p[i]);
    p[i].vel += force/p[i].mass*dt;
  } 

  // Update positions
  for (i = 0; i < n_particles; i++) {
    std::cout << "Update position of particle " << i << std::endl;
    p[i].pos += p[i].vel*dt;
  }
}
