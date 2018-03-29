#include <iostream>
#include "set.h"

bool Set::Member(int e){
  for (size_t i = 0; i < size; i++) {
    if (e == set[i]) {
      return true;
    } else {
      return false;
    }
  }
}

int Set::ElemIndex(const int e) {
  if (Member(e)) {
    for (size_t i = 0; i < size; i++) {
      if (e == set[i]) {
        return i;
      }
    }
  } else {
    std::cout << "Element is not in the set." << '\n';
  }
}

void Set::RmvElem(const int e) {
  for (size_t i = ElemIndex(e); i < size; i++) {
    set[i] = set[i+1];
  }
  size--;
}

void Set::Print() {
  std::cout << "{ ";
  for (size_t i = 0; i < size; i++) {
    std::cout << set[i] << ", ";
  }
  std::cout << " }" << '\n';
}

void Set::Copy(const Set a, Set& b) { //copy a to b
  for (size_t i = 0; i < a.size; i++) {
    b[i] = a[i];
  }
  b.size = a.size;
  a.MaxCard() = b.maxCardinality;


}

int main() {
  Set asdf;
  Set fdsa;
  asdf.AddElem(3);
  asdf.Print();
  asdf.AddElem(1);
  asdf.Print();
  asdf.AddElem(4);
  asdf.Print();
  asdf.RmvElem(3);
  asdf.Print();
  std::cout << "maxcard " << asdf.MaxCard() << '\n';
  std::cout << "card " << asdf.Card() << '\n';
}
