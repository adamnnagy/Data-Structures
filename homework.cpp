#include <iostream>
#include "set.h"

bool Set::Member(int e) {
  for (size_t i = 0; i < size; i++) {
    if (e == set[i]) {
      return true;
    } else {
      return false;
    }
  }
}

void Set::Add(const int e){
  int i = 0;
  while (e < set[i]) {
    i++;
  }
  set[i] = e;
  size++;

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

void Set::Copy(Set& copyFrom) { //copy a to b
  size = copyFrom.Card();
  maxCardinality = copyFrom.MaxCard();
  for (size_t i = 0; i < copyFrom.Card(); i++) {
    set[i] = *(copyFrom.Elems()+i);
  }
}

bool Set::Equal(Set& a, Set& b) {

}

int* Set::Intersect(Set& a, Set& b) {

}

int* Set::Union(Set& a, Set& b) {

}




int main() {
  Set asdf;
  asdf.AddElem(3);
  asdf.AddElem(1);
  asdf.AddElem(4);
  Set fdsa;
  fdsa.AddElem(9);
  fdsa.AddElem(8);
  fdsa.AddElem(7);
  asdf.Print();
  fdsa.Print();

//test copyFrom

  std::cout << asdf.Elems() << '\n';

  asdf.Copy(fdsa);

  asdf.Print();


  std::cout << "maxcard " << asdf.MaxCard() << '\n';
  std::cout << "card " << asdf.Card() << '\n';
}
