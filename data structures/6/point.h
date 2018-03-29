#ifndef _H_POINT_ // if not defined
#define _H_POINT_ // if not defined, define it
#include <iostream>
//File: point.h

class Point {
private:
  int x;
  int y;
public:
  Point(){x = 0; y = 0; std::cout << "no argument" << '\n';}
  Point(int xx, int yy);

  //get
  int getX()const{return x;}
  int getY()const{return y;}

  //set
  void setX(int xx) {x = xx;}
  void setY(int yy) {y = yy;}

  //display
  void display(); // this is member of the class, we are going to define it later

  //destructor
  ~Point(){std::cout << "destructor: " << x <<" "<< y << '\n';}

};

#endif
