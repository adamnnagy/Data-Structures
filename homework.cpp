#include <iostream>
#include "set.h"

//testing if an element is a member of the set

bool Set::Member(int e) {
  for (size_t i = 0; i < size; i++) {
    if (e == set[i]) {
      return true;
    } else {
      return false;
    }
  }
}

//adding an element and sorting the array

void Set::AddElem(const int e){
  if (size + 1 == maxCardinality) {
    std::cout << "you have reached the maximum elements in the Set." << '\n';
    return;
  }
  if(e > set[size - 1]) {
    set[size] = e;
    size++;
  } else {
    int i = size - 1;
    size++;
    while (e < set[i]) {
      set[i + 1] = set[i];
      if (i < 1) {
        set[0] = e;
        break;
      }
      i--;
    }
    set[i] = e;
  }
}

//returns the index of an element if it's the member of the set

int Set::ElemIndex(const int e) {
    for (size_t i = 0; i < size; i++) {
      if (e == set[i]) {
        return i;
      }
    }
    std::cout << "Element is not in the set." << '\n';
    return 0;
}


//removes an element from the set

void Set::RmvElem(const int e) {
  for (size_t i = ElemIndex(e); i < size; i++) {
    set[i] = set[i+1];
  }
  size--;
}

//prints the set

void Set::Print() {
  std::cout << "{ ";
  for (size_t i = 0; i < size - 1; i++) {
    std::cout << set[i] << ", ";
  }
  std::cout << set[size-1] << " }" << '\n';
}

//copies the set

void Set::Copy(Set& copyFrom) { //copy a to b
  size = copyFrom.Card();
  maxCardinality = copyFrom.MaxCard();
  for (size_t i = 0; i < copyFrom.Card(); i++) {
    set[i] = *(copyFrom.Elems()+i);
  }
}

bool Set::Equal(Set& a) {
  if (a.Card() != this->Card()) {
    return false;
  } else {
    for (size_t i = 0; i < size; i++) {
      if (*(set+i) != *(a.Elems()+i)) {
        return false;
      }
    }
    return true;
  }
}

int* Set::Intersect(Set& a) {
  int *intersection;
  intersection = new int[(a.Card() > size) ? size : a.Card()];
  for (size_t i = 0; i < size; i++) {
    if (*(a.Elems()+i) == set[i]) {
      intersection[i] = set[i];
    }
  }
}

int* Set::Union(Set& a) {
  int *uni;
  uni = new int[(a.Card() > size) ? a.Card() : size];
}




int main() {

  //init set
  Set asdf;
  //add elements to asdf
  asdf.AddElem(3);
  asdf.AddElem(1);
  asdf.AddElem(4);

  //test Member() function
  asdf.Member(3);

  //init set fdsa
  Set fdsa;
  //add elements
  fdsa.AddElem(9);
  fdsa.AddElem(8);
  fdsa.AddElem(7);
  fdsa.AddElem(20);
  fdsa.AddElem(0);

  //print the two sets
  asdf.Print();
  fdsa.Print();

  //test Equal() function
  std::cout << fdsa.Equal(asdf) << '\n';

  //test Copy() function
  asdf.Copy(fdsa);
  asdf.Print();
  std::cout << fdsa.Equal(asdf) << '\n';

  //test ElemIndex() function
  std::cout << asdf.ElemIndex(20);
  std::cout << asdf.ElemIndex(12);

  //test RmvElem() function
  asdf.RmvElem(20);
  asdf.Print();


  std::cout << "intersection:" << '\n';
  for (size_t i = 0; i < asdf.Card(); i++) {
    std::cout << asdf.Intersect(fdsa)[i] << '\n';
  }
}
