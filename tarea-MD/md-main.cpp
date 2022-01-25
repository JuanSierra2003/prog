#include "md-simul.h" // this has all functions declarations

int main(void)
{
  Particle ball;

  // start system
  initial_conditions(ball);
  compute_force_and_energy(ball);
  start_integration(ball, DT);
  double E0 = (ball.Vx*ball.Vx + ball.Vy*ball.Vy + ball.Vz*ball.Vz)*ball.mass/2 - ball.mass*G*ball .Ry;
  print(ball, 0.0, E0);

  // evolve
  for(int istep = 0; istep < NSTEPS; ++istep) {
    time_integration(ball, DT);
    compute_force_and_energy(ball);
    print(ball, istep*DT, E0);
  }
  
  return 0;
}
