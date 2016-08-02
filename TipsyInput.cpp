#include "TipsyInput.h"

template <typename TPos, typename TVel>
void load_particle(Tipsy::TipsyReader &r, Particle *p) {
  Tipsy::dark_particle_t<TPos, TVel> dp;
  if (!r.getNextDarkParticle_t(dp)) {
    std::cerr << "Failed to read dark particle" << std::endl;
    std::exit(-1);
  }
  p->mass = dp.mass;
  p->pos = dp.pos;
  p->vel = dp.vel;
}


// Can only read dark matter particles for now!
// This will fail if the snapshot has other types of particles
TipsyInput::TipsyInput(std::string filename, SimManager* _sim_manager) {
  bool bDoublePos = 0;
  bool bDoubleVel = 0;

  sim_manager = _sim_manager;
  Tipsy::TipsyReader r(filename, 0, 0);
  Tipsy::header tipsy_header = r.getHeader();
  int num_particles = tipsy_header.nbodies;
  std::cout << "Read TIPSY file with " << num_particles << " particles" << std::endl;

  sim_manager->allocate_particles(num_particles);

  int i;
  for (i = 0; i < num_particles; i++) {
    if (!bDoublePos) {
      load_particle<float,float>(r, &sim_manager->p[i]);
    } else if (!bDoubleVel)
      load_particle<double,float>(r, &sim_manager->p[i]);
    else {
      load_particle<double,double>(r, &sim_manager->p[i]);
    }
  }
}
