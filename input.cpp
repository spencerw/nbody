#include "input.h"

const char* Input::param_names[] = {"a", "b", "c", "d"};

Input::Input() {
  std::cout << "Input constructor called" << std::endl;
  a = 0;
  b = 0;
  c = 0;
  d = 0;
}

void Input::process_param_file(const char* filename) {
  std::ifstream infile(filename);
  
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

    if (par_name == "a") {
      a = atoi(val.c_str());
    } else if (par_name == "b") {
      b = atoi(val.c_str());
    } else if (par_name == "c") {
      c = atoi(val.c_str());
    } else if (par_name == "d") {
      d = atoi(val.c_str());
    } else {
      std::cerr << "Invalid parameter: " << par_name;
      std::exit(-1);
    }
  }
}

void Input::print_state() {
  std::cout << "a = " << a << std::endl;
  std::cout << "b = " << b << std::endl;
  std::cout << "c = " << c << std::endl;
  std::cout << "d = " << d << std::endl;
}
