#ifndef PARAM_MANAGER_H
#define PARAM_MANAGER_H

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

class ParamManager {
  public:
    int n_steps;
    double theta;
    double epsilon;

    ParamManager();
    ~ParamManager() {}

    void process_param_file(std::string filename);

    void print_state();
};

#endif
