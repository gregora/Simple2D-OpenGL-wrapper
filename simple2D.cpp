#include "simple2D.h"

int window_width;
int window_height;

void setColor(double r, double g, double b){
  glColor3f(r, g, b);
}

void line(double x1, double y1, double x2, double y2, double width){

  glLineWidth(width);
  glBegin(GL_LINES);
    glVertex3f(x1 / window_width, y1 / window_height, 0);
    glVertex3f(x2 / window_width, y2 / window_height, 0);
  glEnd();

}

void triangle(double x1, double y1, double x2, double y2, double x3, double y3){

  glBegin(GL_TRIANGLES);


          glVertex3f(x1 / window_width, y1 / window_height, 0);
          glVertex3f(x2 / window_width, y2 / window_height, 0);
          glVertex3f(x3 / window_width, y3 / window_height, 0);


  glEnd();

}

void rectangle(double x1, double y1, double x2, double y2){

  glBegin(GL_POLYGON);

    glVertex3f(x1 / window_width, y1 / window_height, 0.0);
    glVertex3f(x2 / window_width, y1 / window_height, 0.0);
    glVertex3f(x2 / window_width, y2 / window_height, 0.0);
    glVertex3f(x1 / window_width, y2 / window_height, 0.0);

  glEnd();

}

void polygon(int vertices_num, double coords[]){

  glBegin(GL_POLYGON);

  for(int i = 0; i < 2*vertices_num; i+=2){
    glVertex3f(coords[i] / window_width, coords[i + 1] / window_height, 0.0);
  }

  glEnd();

}

void circle(double x, double y, double r){

  int segnum = (int) sqrt(r)*4;
  double step = 2*3.14159 / segnum;

  for(int i = 0; i < segnum; i++){
    //draw a triangle
    triangle(x, y, x + cos(step * i)*r, y + sin(step * i)*r, x + cos(step * (i + 1))*r, y + sin(step * (i + 1))*r);
  }

}

void rerender(int v){

  glutPostRedisplay();
  glutTimerFunc(0, rerender, 0);

}

void onResize(int w, int h){

  window_width = (double) w;
  window_height = (double) h;

  glViewport(0,0,w,h);

}

void renderAll(){

  // clear the canvas
  glClearColor(0, 0, 0, 0);
  glClear(GL_COLOR_BUFFER_BIT);

  render();

  // flush
  glFlush();

}

int start(int argc, char **argv, int width, int height, std::string title){

    window_width = width;
    window_height = height;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(width, height);
    glutInitWindowPosition(200, 200);

    glutCreateWindow(title.c_str());

    glutKeyboardFunc(keyboardInput);

    glutDisplayFunc(renderAll);
    glutReshapeFunc(onResize);


    glutTimerFunc(0, rerender, 0);
    glutMainLoop();

    return 0;

}
