#include "ParamManager.h"
#include "SimManager.h"
#include "Output.h"
#include "TipsyInput.h"

int main() {
  std::cout << "Program started" << std::endl;

  ParamManager *param_manager = new ParamManager();
  param_manager->process_param_file("run.param");
  param_manager->print_state();

  SimManager *sim_manager = new SimManager();
  TipsyInput *tipsy_input = new TipsyInput("icfile.bin", sim_manager);
  Output *output = new Output("run", sim_manager);

  // Simulation loop
  int i;
  double dt = 1.0;
  for (i = 0; i < param_manager->n_steps; i++) {
    sim_manager->evolve(dt);
    output->output_step_console();
    output->output_step_file();
  }

  // Cleanup
  delete output;
  delete tipsy_input;
  delete sim_manager;
  delete param_manager;

  std::cout << "Program ended" << std::endl;
  return 0;
}
