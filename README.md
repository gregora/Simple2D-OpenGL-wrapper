# Simple2D OpenGL wrapper

## Dependencies
* Glut
  * To install on Linux `sudo apt-get install mesa-utils` and `sudo apt-get install freeglut3-dev`
  * To install on Windows `http://freeglut.sourceforge.net/`

## Compile
* Linux `g++ main.cpp simple2D.cpp -o main.out -lGL -lGLU -lglut`
Or you can run `./run.sh`, and it will compile and run the program
* Windows `g++ main.cpp simple2D.cpp -o main.exe -lGL -lGLU -lglut`

## How to use with your own project
To use this wrapper in your own project, you need to download `simple2D.cpp` and `simple2D.h` files. Once you have done that, create your own file (for example `example.cpp`) and include `simple2D.h` header file. When creating your main function, you need to do it like this:  `int main(int argc, char **argv)`. You will need to pass these arguments forward.

Then, inside main function, you need to create a start function like this: `start(argc, argv, 1000, 1000, "Test");`. This will create a window, with a width of 1000 pixels, height of 1000 pixels and with title "Test". But you can't render anything yet. To do that, you need to define a void render() function. Inside this function, you can now call all the functions listed below. But that is not all, you will also need to add function `void keyboardInput(unsigned char key, int x, int y){}`, that will handle keyboard inputs.

## Functions for rendering
Inside your `void render(double delta)` this functions accepts a double delta (time in seconds between two frames). Inside render function you can call these functions:
* `setColor(double red, double green, double blue)` - A function that changes fill color. It accepts three arguments, doubles with values from 0 to 1, that define fill color
* `setBackgroundColor(double red, double, green, double blue)` - Set background
* `line(double x1, double y1, double x2, double y2, double width)`
* `triangle(double x1, double y1, double x2, double y2, double x3, double y3)`
* `rectangle(double x1, double y1, double x2, double y2)`
* `polygon(int number_of_vertices, double[] coordinates)` - This functions draws a polygon, with a given number of vertices and give coordinates (`double coordinates[] = {x1, y1, x2, y2, ..., xn, yn}`)
* `circle(double x, double y, double r)`
* `text(double x, double y, void* font, std::string txt)` - Render text
