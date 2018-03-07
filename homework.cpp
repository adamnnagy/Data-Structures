#include <iostream>
#include "set.h"

//Copy Constructor
Set::Set(const Set &obj) {
   std::cout << "Copy constructor is called." << '\n';
   maxCardinality = obj.maxCardinality;
   size = obj.size;
   set = obj.set;
   for (size_t i = 0; i < obj.size; i++) {
     set[i] = obj.set[i];
     std::cout << obj.set[i] << ", " << set[i] << '\n';
   }
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
  //check if maxCardinality is reached
  if (size + 1 == maxCardinality) {
    std::cout << "you have reached the maximum elements in the Set." << '\n';
    return;
  }

  //sorting the array, checking if e > than the last element
  if(e > set[size - 1]) {
    //if yes, add it as the last elements
    set[size] = e;
    //increase the size
    size++;
  } else {
    //otherwise, start looping down the array until i reach the element that i is smaller than
    int i = size - 1;
    //increase size here
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
  delete [] set;
  int* set = new int[maxCardinality];
  set = copyFrom.Elems();
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
  //if equal then return one of the sets
  if (Equal(a)) {
    return a.Elems();
  //if not equal
  } else {
  //initialize set intersection
  Set intersection;
  for (size_t i = 0; i < a.Card(); i++) {
    std::cout << "member? y/n " << Member(*(a.Elems()+i)) << '\n';
    if (Member(a.Elems()[i])) {
      intersection.AddElem(*(a.Elems()+i));
    }
  }
  //intersection.Print();
  // std::cout << "the intersection is: " << intersection.Print() << '\n';
  return intersection.Elems();
}
}

int* Set::Union(Set& a) {
  //create union as set
  Set uni;
  //adding one set
  for (size_t i = 0; i < size; i++) {
    uni.AddElem(*(Elems()+i));
  }
  //adding the second set
  //uni.Print();
  for (size_t i = 0; i < a.Card(); i++) {
    uni.AddElem(*(a.Elems()+i));
  }
  //uni.Print();
  int* intersection = this->Intersect(a);

  //works until here
  // for (size_t i = 0; i < size_t size = sizeof(intersection)/sizeof(*intersection); i++) {
  //   uni.RmvElem(*(intersection+i));
  // }
  //uni.Print();
  return uni.Elems();
}

int main() {

  //init set
  Set asdf, fdsa;
  //add elements to asdf
  asdf.AddElem(3);
  asdf.AddElem(1);
  asdf.AddElem(4);

  //testing copy constructor
  std::cout << "testing copy constructor: " << '\n';
  Set ccd(asdf);
  ccd.Print();

  //testing cardinality
  std::cout << "asdf cardinality: " << asdf.Card() << '\n';

  //test Member() function
  std::cout << '\n';
  asdf.Member(3);


  //add elements
  fdsa.AddElem(9);
  fdsa.AddElem(8);
  fdsa.AddElem(7);
  fdsa.AddElem(20);
  fdsa.AddElem(0);
  std::cout << "add element to the second set: " << '\n';
  std::cin >> fdsa;

  // std::cout << "fdsa cardinality: " << fdsa.Card() << '\n';
  // print the two sets
  asdf.Print();
  fdsa.Print();

  // std::cout << "asdf: " << asdf << '\n';
  //test copy constructor
  Set foo = asdf;
  foo.Print();

  std::cout << "foo print " << foo << '\n';

  bool isMember;
  std::cout << "members of the set: ";
  // for (size_t i = 0; i < asdf.Card(); i++) {
  //   //isMember = *(asdf.Elems()+i) & *(fdsa.Elems()+i);
  //   isMember = asdf.Elems()[i] & fdsa.Elems()[i];
  //
  //   std::cout << isMember << ", ";
  // }
  std::cout << '\n';
  //test Equal() function
  std::cout << fdsa.Equal(asdf) << '\n';

  //test Copy() function
  asdf.Copy(fdsa);
  asdf.Print();

  //equality returns true
  std::cout << "are the two sets equal? " << fdsa.Equal(asdf) << '\n';

  //test ElemIndex() function
  std::cout << asdf.ElemIndex(20) << '\n';
  std::cout << asdf.ElemIndex(12) << '\n';

  //test RmvElem() function
  asdf.RmvElem(20);
  std::cout << "element '20' removed from the set: " << '\n';
  asdf.Print();



  // asdf = fdsa;
  //intersection plot
  //the print doesn't know the size of the intersection array.
  std::cout << "intersection:" << '\n';
  std::cout << "{ ";
  int* intersection = asdf.Intersect(fdsa);
  std::cout << "asdf card: " << asdf.Card() << '\n';
  // for (size_t i = 0; i < asdf.Card(); i++) {
  //   std::cout << intersection[i] << ", ";
  // }
  std::cout << " }" << '\n';


  //union plot
  //since cannot tell the size of the intersection array it cannot print it
  //The problem is that I didn't use the Set class to declare the intersection set
  //and the Union set.
  std::cout << "union:" << '\n';
  std::cout << "{ ";
  //int* uni = asdf.Union(fdsa);
  // for (size_t i = 0; i < asdf.Card() + fdsa.Card(); i++) {
  //   std::cout << *(uni+i) << ", ";
  // }
  std::cout << " }" << '\n';

  // asdf = fdsa;

  //asdf >> 13;

  // asdf.Print();

  return 0;
}
