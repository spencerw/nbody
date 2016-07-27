#ifndef OUTPUT_H
#define OUTPUT_H

#include "SimManager.h"

class Output {
  public:
    int num_output_files;
    std::string out_filename;
    SimManager* sim_manager;

    Output(std::string _out_filename, SimManager* _sim_manager);
    ~Output() {}

    void output_step_console();
    void output_step_file();
};

#endif
