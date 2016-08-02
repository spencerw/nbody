#include "Physics.h"

Physics::Physics(double _epsilon) {
  epsilon = _epsilon;
}

Vector3D<double> Physics::grav_force(Vector3D<double> pos1, double mass1, Vector3D<double> pos2, double mass2) {
  Vector3D<double> rij = pos2 - pos1;
  double r = rij.length();
  return mass1*mass2*rij/(r*r*r + epsilon);
}
