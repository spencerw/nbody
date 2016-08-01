#include "Output.h"

Output::Output(std::string _out_filename, SimManager* _sim_manager) {
  out_filename = _out_filename;
  sim_manager = _sim_manager;
  num_output_files = 0;
}

void Output::output_step_console() {
  std::cout << "Step: " << sim_manager->get_step_num() << " Time: " << sim_manager->get_time() << std::endl;
}

void Output::output_step_file() {
  std::fstream outfile;
  std::stringstream filename;
  filename << out_filename << num_output_files << ".out";
  outfile.open(filename.str().c_str(), std::fstream::out);

  
  const char separator = ' ';
  int label_width = 15;
  outfile << std::setprecision(10);
  outfile << "Step: " << sim_manager->get_step_num() << " Time: " << sim_manager->get_time() << std::endl;
  outfile << std::left << std::setw(label_width) << std::setfill(separator) << "PID";
  outfile << std::left << std::setw(label_width) << std::setfill(separator) << "Mass";
  outfile << std::left << std::setw(label_width) << std::setfill(separator) << "xPos";
  outfile << std::left << std::setw(label_width) << std::setfill(separator) << "yPos";
  outfile << std::left << std::setw(label_width) << std::setfill(separator) << "zPos";
  outfile << std::left << std::setw(label_width) << std::setfill(separator) << "xVel";
  outfile << std::left << std::setw(label_width) << std::setfill(separator) << "yVel";
  outfile << std::left << std::setw(label_width) << std::setfill(separator) << "zVel";
  outfile << std::endl;
  int i;
  Particle* p;
  for (i = 0; i < sim_manager->get_n_particles(); i++) {
    p = sim_manager->get_particle(i);
    //outfile << std::left << std::setw(label_width) << std::setfill(separator) << i;
    //outfile << std::left << std::setw(label_width) << std::setfill(separator) << p->mass;
    //outfile << std::left << std::setw(label_width) << std::setfill(separator) << p->pos(0);
    //outfile << std::left << std::setw(label_width) << std::setfill(separator) << p->pos(1);
    //outfile << std::left << std::setw(label_width) << std::setfill(separator) << p->pos(2);
    //outfile << std::left << std::setw(label_width) << std::setfill(separator) << p->vel(0);
    //outfile << std::left << std::setw(label_width) << std::setfill(separator) << p->vel(1);
    //outfile << std::left << std::setw(label_width) << std::setfill(separator) << p->vel(2);
    outfile << std::endl;
  }
  
  outfile.close();
  num_output_files++;
}
