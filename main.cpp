#include "simple2D.h"
#include <thread>
#include <chrono>

int frame_num = 0;
int FPS = 0;

double circleang = 0;

extern int window_width;
extern int window_height;

int main(int argc, char **argv){

  start(argc, argv, 1000, 1000, "Test");

  while(true){
    rerender();
  }

}

void render(double delta){

  frame_num = frame_num + 1;

  double circlex, circley;
  circleang += (double) 0.785 * delta;

  circlex = cos(circleang) * 400;
  circley = sin(circleang) * 400;

  setColor(0.1, 0.6, 0.2);
  double p[] = {0, 0, 100, 0, 100, 100, 0, 100, -50, 50};
  polygon(5, p);

  setColor(0.5, 0.2, 0.8);
  rectangle(-100, -100, -200, -200);

  setColor(0.7, 0.2, 0.4);
  circle(circlex, circley, 50);

  setColor(0, 0, 0);

  if(frame_num % 50 == 0 || frame_num == 1){
    FPS = 1 / delta;
  }

  std::string str = std::to_string(FPS);
  str.append(" FPS");
  text( - (window_width) + 10,  (window_height) - 40, GLUT_BITMAP_HELVETICA_18, str);

  setColor(0.34, 0.67, 0.65);
  rectangle(150, 150, 250, 200);

  setColor(0, 0, 0);
  //texture();

}

void keyboardInput(unsigned char key, int x, int y){}
