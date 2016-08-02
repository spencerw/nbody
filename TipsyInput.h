#ifndef TIPSY_INPUT_H
#define TIPSY_INPUT_H

#include "SimManager.h"
#include "Particle.h"
#include "TipsyFile.h"

class TipsyInput {
  public:
    SimManager* sim_manager;
    TipsyInput(std::string filename, SimManager* _sim_manager);
    ~TipsyInput() {}
};

#endif
