#include "point.h"
#include <iostream> // using namespace std
//definition of the constructor

using namespace std;
Point::Point(int x, int yy)
{
  this -> x = x; //we are using pointers. the attribute receives the input
          y = yy;
}

void Point::display()
{
  std::cout << "x= " << x << '\n';
  std::cout << "y= " << y << '\n';
}
