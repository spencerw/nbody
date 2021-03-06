#include "ParamManager.h"

ParamManager::ParamManager() {
  n_steps = 100;
  theta = 0.5;
  epsilon = 0.001;
}

void ParamManager::process_param_file(std::string filename) {
  std::ifstream infile(filename.c_str());
  
  if (!infile) {
    std::cerr << "Can't open file " << filename << std::endl;
    std::exit(-1);
  }

  std::string line;
  while(getline(infile, line)) {
    // Remove whitespace at beginning of line
    line = line.substr(line.find_first_not_of(" \t"));

    // Ignore comments
    if (line.at(0) == '#') continue;

    // Check for valid parameters
    std::string par_name, val;
    par_name = line.substr(0, line.find_first_of(" "));
    val = line.substr(line.find_first_of(" "));

    if (par_name == "nSteps") {
      n_steps = atoi(val.c_str());
    } else if (par_name == "theta") {
      theta = atof(val.c_str());
    } else if (par_name == "dt") {
      dt = atof(val.c_str());
    } else if (par_name == "epsilon") {
      epsilon = atof(val.c_str());
    } else {
      std::cerr << "Invalid parameter: " << par_name;
      std::exit(-1);
    }
  }
}

void ParamManager::print_state() {
  std::cout << "nSteps = " << n_steps << std::endl;
  std::cout << "dt = " << dt << std::endl;
  std::cout << "theta = " << theta << std::endl;
  std::cout << "epsilon = " << epsilon << std::endl;
}
