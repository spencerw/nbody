#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <stdint.h>
#include "SFC.h"
#include <vector>

class Particle {
  public:
    Vector3D<double> pos;
    Vector3D<double> vel;
    double mass;

    Particle();
    ~Particle() {}
};

#endif
