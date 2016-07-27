#ifndef PARAM_MANAGER_H
#define PARAM_MANAGER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

class ParamManager {
  public:
    int n_particles;
    int n_steps;

    ParamManager();
    ~ParamManager() {}

    void process_param_file(const char* filename);

    void print_state();
};

#endif
