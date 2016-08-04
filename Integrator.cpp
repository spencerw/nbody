#include "Integrator.h"

Integrator::Integrator(Particle* _p, int _n_particles) {
  p = _p;
  n_particles = _n_particles;
}

void Integrator::update_particles(int step_num, Tree* tree, double dt) {
  std::cout << "Integrating step " << step_num << std::endl;
  int i;
 
  if (step_num == 0) {
  #pragma omp parallel for
    for (i = 0; i < n_particles; i++) {
      Vector3D<double> a = tree->force_on(&p[i])/p[i].mass;
      p[i].vel += a*dt*0.5;
      p[i].pos += p[i].vel*dt;
    }
  }
  else {
    #pragma omp parallel for
    for (i = 0; i < n_particles; i++) {
      Vector3D<double> a = tree->force_on(&p[i])/p[i].mass;
      p[i].pos += p[i].vel*dt;
      p[i].vel += a*dt;
    }
  }

}
