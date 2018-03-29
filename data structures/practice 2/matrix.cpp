#include <iostream>
using namespace std;

class Matrix
{
private:
  int **matrix;
  int sizeOf;
public:
  //constructor
  Matrix(){sizeOf = 0; std::cout << "no argument" << '\n';}
  Matrix(int n);
  void display();

  ~Matrix(){std::cout << "destructor" << '\n';};
};


int main(){

  std::cout << "hey" << '\n';

  Matrix myMatrix(2);
  myMatrix.display();
  myMatrix.display();

}


Matrix::Matrix(int n)
{
  //declaration
  //declaration
  // this -> sizeOf = n;
  sizeOf = n;
  matrix = new int*[sizeOf];

  for (int i = 0; i < n; ++i) {
    matrix[i] = new int[sizeOf];
  }

  //user input
  for (size_t i = 0; i < n; i++) {
    for (size_t j = 0; j < n; j++) {
      std::cout << "row " << i << " column " << j << ":";
      std::cin >> matrix[i][j];
    }
    std::cout << '\n';
  }
}

void Matrix::display()
{
  for (size_t i = 0; i < sizeOf; i++) {
    for (size_t j = 0; j < sizeOf; j++) {
      std::cout << " " << matrix[i][j] << " ";
    }
    std::cout << '\n';
  }
}
