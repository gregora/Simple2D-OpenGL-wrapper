#include "simple2D.h"

int main(int argc, char **argv){

  start(argc, argv, 1000, 1000, "Test");

}

double circlex = 0;
double circley = 0;

void render(double delta){

  circlex += 100 * delta;

  setColor(0.1, 0.6, 0.2);
  double p[] = {0, 0, 100, 0, 100, 100, 0, 100, -50, 50};
  polygon(5, p);

  setColor(0.5, 0.2, 0.8);
  rectangle(-100, -100, -200, -200);

  setColor(0.7, 0.2, 0.4);
  circle(circlex, circley, 50);

}

void keyboardInput(unsigned char key, int x, int y){}
