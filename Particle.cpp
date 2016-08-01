#include "Particle.h"

Particle::Particle() {
  pos = Vector3D<double>(0.0);
  vel = Vector3D<double>(0.0);
  mass = 1.;

  pos[0] = 0.0;
  pos[1] = 0.0;
  pos[2] = 0.0;

  vel[0] = 0.0;
  vel[1] = 0.0;
  vel[2] = 0.0;
}
