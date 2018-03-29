#include <iostream>


int myFunction (int& a) {
  a++;
  std::cout << a << '\n';
  return a;
}

int main() {
  int myVar = 8;
  int* myVar2;
  myVar2 = new int;

  std::cout << "asdf" << myVar << '\n';
  std::cout << "asdf" << &myVar << '\n';
  std::cout << "asdf" << myVar2 << '\n';
  std::cout << "asdf" << &myVar2 << '\n';

  std::cout << "amazing" << '\n';

  std::cout << myFunction(myVar) << '\n';
  std::cout << myVar << '\n';

  int a[5];
  a[0] = 1;
  std::cout << a[0] << '\n';

  //std::cout << "asdf" << a.at(0) << '\n';


}
