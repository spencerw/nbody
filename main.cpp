#include <iostream>
#include "input.h"

int main() {
  std::cout << "Program started" << std::endl;

  Input input;
  input.process_param_file("run.param");
  input.print_state();

  std::cout << "Program ended" << std::endl;
  return 0;
}
