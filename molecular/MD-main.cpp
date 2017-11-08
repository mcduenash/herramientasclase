#include <vector>
#include "mdsimul.h"

int main(int argc, char **argv)
{
  std::vector<Particle> balls(N); // N=Number of particles

  // t=0
  material_properties(balls);
  initial_conditions(balls);
  
  compute_force(balls);
  start_integration(balls);
  init_gnuplot();
  print_gnuplot(balls);

  // evolve
  for(int istep=1; istep<NSTEPS; ++istep){
    compute_force(balls);
    integrate(balls);
    print_gnuplot(balls); // time = istep*DT
  }
  
  return 0;
}

