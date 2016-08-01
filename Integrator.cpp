#include "Integrator.h"

Integrator::Integrator(Particle* _particles, int _n_particles) {
  particles = _particles;
  n_particles = _n_particles;
  epsilon = 0.01;
}

void Integrator::update_particles(double dt) {
  int i, j;
  Particle *pi, *pj;

  // Force calculations
  Vector3D<double> rij, dv_over_m;
  double r;
  for (i = 0; i < n_particles; i++) {
    for (j = i+1; j < n_particles; j++) {
      pi = &particles[i];
      pj = &particles[j];

      rij = pi->pos - pj->pos;
      r = rij.length();
      dv_over_m = rij*dt/(r*r*r + epsilon);
      pi->vel -= dv_over_m*pj->mass;
      pj->vel += dv_over_m*pi->mass;
    }
  } 

  // Update positions
  for (i = 0; i < n_particles; i++) {
    pi = &particles[i];
    pi->pos += pi->vel*dt;
  }
}
