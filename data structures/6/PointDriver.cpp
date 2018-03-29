#include "point.h"
#include <iostream> //display a point

// to pass a reference ==> void display(const Point& pt)
void display(const Point& pt)
{
  std::cout << "x= " << pt.getX() << '\n';
  std::cout << "y= " << pt.getY() << '\n';
}

int minPoint(Point arrayOfPoints[], int sizeOfArray)
{
    int minimum = arrayOfPoints[0].getX() + arrayOfPoints[0].getY();
    for (int i = 1; i<sizeOfArray; i++) {
      int tmp = arrayOfPoints[i].getX() + arrayOfPoints[i].getY();
      if (tmp < minimum) minimum = tmp;
    }
    return minimum;
}

int main()
{
  Point p1, p2(5,5);

  p1.display(); //calling Point:display();
  display(p2); //general display function

  //static array of 5 points
  Point pts[5];
  pts[0] = p1;
  pts[1] = p2;
  pts[2] = Point(7,7);
  pts[3] = Point(15,15);
  pts[4] = Point(12,22);

  for (int i = 0; i < 5; i++) {
    // std::cout << "shit" << '\n';
    pts[i].display();
    std::cout << '\n';
  }
  int minimum = minPoint(pts, 5);
  std::cout << "Minimum value of points: " << minimum << '\n';

  //dynamic array of point
  int nbpts;
  do {
    std::cout << "enter an array of points between 5 and 10" << '\n';
    std::cin >> nbpts;
  } while (nbpts < 5 || nbpts > 10);
    Point* pts2;
    pts2 = new Point[nbpts];


}
