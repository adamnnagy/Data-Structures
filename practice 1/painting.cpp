#include <iostream>
#include "stdio.h"

using namespace std;




class PaintJob {
private:
  const int squareFeet = 110;
  const int hours = 8;
  const int costperHour = 25;

  int nbRooms;
  double pp;
  int wallSpace;
public:
  PaintJob();


  int getNbRooms();
  void inputPaintPrice(double& pp);
  int getWallSpace(int sp);
  void display();
  //set

}

void main() {




}

int PaintJob::getNbRooms() {
  std::cout << "Please input the number of rooms 2b painted!" << '\n';
  int nbRooms;
  while (nbRooms < 1) {
    std::cin >> nbRooms;
  }
  int i = 0;
  while (i < nbRooms) {
    getWallSpace(int sp);
  }
}

void PaintJob::inputPaintPrice(double& pp) {
  std::cout << "input the price of the paint" << '\n';
  while (pp < 10) {
    std::cin >> pp;
  }

}

int PaintJob::getWallSpace(int sp){
  std::cout << "input the wallspace per room" << '\n';
  std::cin >> sp;
  return sp;
}

void PaintJob::display()
{
 std::cout << "" << '\n';
}
