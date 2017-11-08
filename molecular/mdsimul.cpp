#include "mdsimul.h"

// function implementations
void material_properties(std::vector<Particle> & balls)
{
  std::mt19937 gen; // random generator: Mersenne-Twister
  gen.seed(1); // control the seed
  std::uniform_real_distribution<> dis(0.5*RAD, 1.0*RAD); // radii between R/2 and R
  
  // set radii randomly
  for(auto & body : balls){
    body.rad=dis(gen);
    body.mass=RHO*4*M_PI*body.rad*body.rad*body.rad/3;
  }
}

void initial_conditions(std::vector<Particle> & balls)
{ 
  // set up uniformly on a 2d grid

  // extract max rad
  double max_rad=-1.0e300;
  for(auto & body : balls){
    if (body.rad >= max_rad) {
      max_rad=body.rad;
    }
  }

  // put on the 2d grid
  const int NX=L/(2*RAD);
  for(int id=0; id<balls.size(); ++id){
    int ix=id%NX; int iy=id/NX;
    balls[id].Rx = max_rad + ix*max_rad;
    balls[id].Ry = 2*max_rad + iy*max_rad;
    balls[id].Rz = 0.0;
  }

  // initial velocity could be random, for now everything going up
  for(auto & body : balls){
    body.Vy = +1.2347;
  }
}
void compute_force(std::vector<Particle> & balls)
{
  for(auto & body : balls){
    // reset force
    body.Fx = body.Fy = body.Fz = 0.0;

    // add gravitational force
    body.Fy += body.mass*G; // G is already negative

    // add force with bottom wall
    double delta = body.rad - body.Ry;
    if (delta > 0) {
      body.Fy += K*delta;
    }
    //force with other walls
    delta = body.rad - body.Rx;
    if (delta > 0){
      body.Fx += K*delta;     
    }
    delta = body.Rx + body.rad - L;
    if (delta > 0){
      body.Fx -= K*delta;     
    }
    delta = body.Ry + body.rad - L;
    if (delta > 0){
      body.Fy -= K*delta;     
    }
  }
      // force with other particles
  for (int id = 0; id < balls.size();++id){
    for (int jd = id+1; jd < balls.size(); ++jd){
      double Rij[3], Nij [3];
      Rij[0]=balls[jd].Rx-balls[id].Rx;
      Rij[1]=balls[jd].Ry-balls[id].Ry;
      Rij[2]=balls[jd].Rz-balls[id].Rz;
      double rij = std::sqrt(Rij[0]*Rij[0] + Rij[1]*Rij[1] + Rij[2]*Rij[2]);
      Nij[0] = Rij[0]/rij;
      Nij[1] = Rij[1]/rij;
      Nij[2] = Rij[2]/rij;
      double delta = balls[id].rad + balls[jd].rad - rij;
      if (delta > 0){
	balls[jd].Fx += K*delta*Nij[0];
	balls[jd].Fy += K*delta*Nij[1];
	balls[jd].Fz += K*delta*Nij[2];
	balls[id].Fx -= K*delta*Nij[0];
	balls[id].Fy -= K*delta*Nij[1];
	balls[id].Fz -= K*delta*Nij[2];
	  
      }
    }
  }
}

void start_integration(std::vector<Particle> & balls)
{
  for(auto & body : balls){
    body.Vx -= 0.5*body.Fx*DT/body.mass;
    body.Vy -= 0.5*body.Fy*DT/body.mass;
    body.Vz -= 0.5*body.Fz*DT/body.mass;
  }
}

void integrate(std::vector<Particle> & balls)
{
  // use simple leap-frog
  for(auto & body : balls){
    body.Vx += body.Fx*DT/body.mass;
    body.Vy += body.Fy*DT/body.mass;
    body.Vz += body.Fz*DT/body.mass;
    body.Rx += body.Vx*DT;
    body.Ry += body.Vy*DT;
    body.Rz += body.Vz*DT;
  }
}

void print_info(const std::vector<Particle> & balls, const double & time)
{
  // here we print something useful
  // for now is just a test
  std::cout.precision(16);
  std::cout.setf(std::ios::scientific);
  
  std::cout << time
            << "\t" << balls[0].Rx
            << "\t" << balls[0].Ry 
            << "\t" << balls[0].Rz 
            << "\t" << balls[0].Vx 
            << "\t" << balls[0].Vy 
            << "\t" << balls[0].Vz 
            << "\n";
}

void init_gnuplot(){
  std::cout << "set parametric\n"
	    << "set trange [0:2*pi]\n"
	    << "set size ratio -1\n"
	    << "unset key\n"
	    << "set xrange [" << -0.2*L <<":"<< 1.2*L <<"]\n"
	    << "set yrange [" << -0.2*L <<":"<< 1.2*L <<"]\n"
	    << "set terminal gif animate\n"
	    << "set out 'dinamicamolecular.gif'\n";
  
}

void print_gnuplot(std::vector<Particle> & balls){
  std::cout << "plot ";
  for (auto & body : balls){
    std::cout << body.Rx << "+" << body.rad << "*cos(t), "
	      << body.Ry << "+" << body.rad <<"*sin(t), ";
  }
  std::cout << "0, 0\n";
}
