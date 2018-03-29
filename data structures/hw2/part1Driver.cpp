#include <iostream>
#include "SLinkedList.h"

int main() {
  SLinkedList a;
  std::string Message = a.empty() ? "empty" : "not empty";
  std::cout << Message << '\n';
  std::cout << "adding element to a" << '\n';
  std::string myString = "harminc";
  a.addFront(myString);
  std::cout << a.front() << '\n';
  std::cout << "removing the front from a" << '\n';
  a.removeFront();

  return 0;
}
