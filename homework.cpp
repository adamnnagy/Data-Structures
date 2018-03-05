#include <iostream>
#include "set.h"

//Copy Constructor
Set::Set(const Set &obj) {
   std::cout << "Copy constructor allocating ptr." << '\n';
   set = new int;
   *set = *obj.set;
   int size = obj.size; // copy the value
}


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
  Set intersection;
  intersection.Copy(a);
  intersection.Print();
  for (size_t i = 0; i < size; i++) {
    if (*(a.Elems()+i) == set[i]) {
      intersection[i] = set[i];
    }
  }
  return intersection;
}

int* Set::Union(Set& a) {
  //create union as set
  Set uni;
  //adding one set
  for (size_t i = 0; i < size; i++) {
    uni.AddElem(*(Elems()+i));
  }
  //adding the second set
  uni.Print();
  for (size_t i = 0; i < a.Card(); i++) {
    uni.AddElem(*(a.Elems()+i));
  }
  uni.Print();
  int* intersection = this->Intersect(a);

  //works until here
  // for (size_t i = 0; i < size_t size = sizeof(intersection)/sizeof(*intersection); i++) {
  //   uni.RmvElem(*(intersection+i));
  // }
  uni.Print();
  return uni.Elems();
}

int main() {

  //init set
  Set asdf, fdsa;
  //add elements to asdf
  asdf.AddElem(3);
  asdf.AddElem(1);
  asdf.AddElem(4);

  //test Member() function
  asdf.Member(3);

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

  //equality returns true
  std::cout << fdsa.Equal(asdf) << '\n';

  //test ElemIndex() function
  std::cout << asdf.ElemIndex(20);
  std::cout << asdf.ElemIndex(12);

  //test RmvElem() function
  asdf.RmvElem(20);
  asdf.Print();



  //intersection plot
  //the print doesn't know the size of the intersection array.
  std::cout << "intersection:" << '\n';
  std::cout << "{ ";
  for (size_t i = 0; i < asdf.Card()-1; i++) {
    std::cout << asdf.Intersect(fdsa)[i] << ", ";
  }
  std::cout << " }" << '\n';


  //union plot
  //since cannot tell the size of the intersection array it cannot print it
  //The problem is that I didn't use the Set class to declare the intersection set
  //and the Union set.
  std::cout << "union:" << '\n';
  std::cout << "{ ";
  int* uni = asdf.Union(fdsa);
  for (size_t i = 0; i < asdf.Card() + fdsa.Card() - 1; i++) {
    std::cout << *(uni+i) << ", ";
  }
  std::cout << " }" << '\n';

  asdf = fdsa;

  asdf >> 13;

  asdf.Print();

  return 0;
}
