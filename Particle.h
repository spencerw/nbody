#ifndef PARTICLE_H
#define PARTICLE_H

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <boost/numeric/ublas/vector.hpp>
#include <boost/numeric/ublas/io.hpp>

using namespace boost::numeric::ublas;

class Particle {
  public:
    vector<double> pos;
    vector<double> vel;
    double mass;

    Particle();
    ~Particle() {}
};

#endif
