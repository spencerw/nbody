#include "ParamManager.h"
#include "SimManager.h"
#include "Output.h"

int main() {
  std::cout << "Program started" << std::endl;

  ParamManager *param_manager = new ParamManager();
  param_manager->process_param_file("run.param");
  param_manager->print_state();

  SimManager *sim_manager = new SimManager(&param_manager->n_particles);
  Output *output = new Output("run", sim_manager);

  // Initalize particle positions
  // Need to code a better way to to this
  sim_manager->get_particle(0)->pos(0) = 1.0;
  sim_manager->get_particle(1)->pos(1) = 1.0;

  // Simulation loop
  int i;
  double dt = 0.1;
  for (i = 0; i < param_manager->n_steps; i++) {
    sim_manager->evolve(dt);
    output->output_step_console();
    output->output_step_file();
  }

  // Cleanup
  delete output;
  delete sim_manager;
  delete param_manager;

  std::cout << "Program ended" << std::endl;
  return 0;
}
