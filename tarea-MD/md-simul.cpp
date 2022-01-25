#include "md-simul.h"

void initial_conditions(Particle & body)
{
  body.Ry = 1.6598;
  body.Vx = 0.23698;

  body.rad = 0.235;
  body.mass = 0.29698;
}

void compute_force_and_energy(Particle & body)
{
  // reset force
  body.Fx = body.Fy = body.Fz = body.Ut = body.Ki = 0.0;

  // gravitational force
  body.Fy += body.mass*G;
  body.Ut += -body.mass*G*body.Ry;  

  // floor
  double delta = body.rad - body.Ry;
  if (delta > 0) {
    body.Fy += K*delta;
    body.Ut += K*delta*delta/2;
  }

  // Right wall
  delta = body.Rx + body.rad - LR;
  if (delta > 0) {
    body.Fx -= K*delta;
    body.Ut += K*delta*delta/2;
  }

  // Left wall
  delta = LL - body.Rx + body.rad;
  if (delta > 0) {
    body.Fx += K*delta;
    body.Ut += K*delta*delta/2;
  }

  //kinetic energy
  body.Ki += (body.Vx*body.Vx + body.Vy*body.Vy + body.Vz*body.Vz)*body.mass/2;
}

void print(Particle & body, double time, double E0)
{
  std::cout << time << "  "
            << body.Rx << "  "
            << body.Ry << "  "
            << body.Rz << "  "
            << body.Vx << "  "
            << body.Vy << "  "
            << body.Vz << "  "
            << body.Ut << "  "
            << body.Ki << " "
            << (body.Ut + body.Ki - E0)/E0 << " "
            << "\n";
}
