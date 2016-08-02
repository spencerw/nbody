#include "ParamManager.h"
#include "SimManager.h"
#include "Output.h"
#include "TipsyInput.h"
#include "Tree.h"
#include "Physics.h"

int main() {
  std::cout << "Program started" << std::endl;

  ParamManager *param_manager = new ParamManager();
  param_manager->process_param_file("run.param");
  param_manager->print_state();

  Physics* physics = new Physics(param_manager->epsilon);
  SimManager *sim_manager = new SimManager();
  TipsyInput *tipsy_input = new TipsyInput("icfile.bin", sim_manager);
  Output *output = new Output("run", sim_manager);

  std::cout << "Initalization finished...starting simulation loop" << std::endl;

  // Simulation loop
  int i;
  Tree* tree;
  double dt = 0.1;
  for (i = 0; i < param_manager->n_steps; i++) {
    tree = new Tree(sim_manager->p, sim_manager->get_n_particles(), param_manager->theta, physics);
    sim_manager->evolve(tree, dt);
    output->output_step_console();
    output->output_step_file();
    delete tree;
    std::cout << "Step " << i << " finished" << std::endl;
  }

  // Cleanup
  delete output;
  delete tipsy_input;
  delete sim_manager;
  delete physics;
  delete param_manager;

  std::cout << "Program ended" << std::endl;
  return 0;
}
