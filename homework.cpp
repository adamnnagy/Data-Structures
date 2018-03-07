#include <iostream>
#include "set.h"

//Copy Constructor
Set::Set(const Set &obj) {
   std::cout << "Copy constructor is called." << '\n';
   maxCardinality = obj.maxCardinality;
   size = obj.size;
   set = new int[maxCardinality];
   for (size_t i = 0; i < size; i++) {
     set[i] = obj.set[i];
   }
}

//copies the set
void Set::Copy(const Set &copyFrom) { //copy a to b
  size = copyFrom.Card();
  maxCardinality = copyFrom.MaxCard();
  set = copyFrom.Elems();
  for (size_t i = 0; i < size; i++) {
    set[i] = copyFrom.Elems()[i];
  }
}

//testing if an element is a member of the set
bool Set::Member(int e) {
  // std::cout << "Checking " << e << '\n';
  for (size_t i = 0; i < size; i++) {
    // std::cout << "Current element " << set[i]<< " vs "<< e<<'\n';
    if (e == set[i]) {
      return true;
    }
  }
  return false;
}

//adding an element to set
void Set::AddElem(const int e){
  //check if element is already member of the set
  if (Member(e)) {
    return;
  }
  //check if maxCardinality is reached
  if (size + 1 == maxCardinality) {
    std::cout << "you have reached the maximum elements in the Set." << '\n';
    return;
  }
  //add element to the last place:
  set[size] = e;
  size++;
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
  if(size == 0){
    std::cout << "The set is empty" << '\n';
    return;
  }

  std::cout << "{ ";
  for (size_t i = 0; i < size; i++) {
    std::cout << set[i] << ", ";
  }
  std::cout << " }" << '\n';
}

//checking the equality of the two sets
bool Set::Equal(Set &obj) {
  if (obj.Card() != this->Card()) {
    return false;
  } else {
    for (size_t i = 0; i < size; i++) {
      if (*(set+i) != *(obj.Elems()+i)) {
        return false;
      }
    }
    return true;
  }
}

//intersection
void Set::Intersect(Set &a) {
  //if equal then return one of the sets
  if (Equal(a)) {
    std::cout << "the intersection of the two sets: " << a << '\n';
    return;
  //if not equal
  } else {
  //initialize set intersection
    Set tmp;
    bool isMember;

    int bound;
    bound = size > a.Card() ? size : a.Card();

    for (size_t i = 0; i < bound; i++) {

      if (a.Member(set[i])) {
        tmp.AddElem(set[i]);
      }
    }
    if(!(Member(0)&&a.Member(0))) {tmp.RmvElem(0);}
    tmp.Print();
  }
}

//union
void Set::Union(Set &a) {
  //create union as set
  Set uni;
  //adding one set
  for (size_t i = 0; i < size; i++) {
    uni.AddElem(*(Elems()+i));
  }
  //adding the second set
  for (size_t i = 0; i < a.Card(); i++) {
    uni.AddElem(*(a.Elems()+i));
  }

  uni.Print();
}

//difference:
void Set::Difference(Set &a){
  if(Equal(a)) {std::cout << "The sets are equal" << '\n';}
  Set tmp;
  for (size_t i = 0; i < maxCardinality; i++) {
    if (!(a.Member(set[i]))) {
      tmp.AddElem(set[i]);
    }
  }
  for (size_t i = 0; i < maxCardinality; i++) {
    if (!(Member(a.Elems()[i]))) {
      tmp.AddElem(a.Elems()[i]);
    }
  }
  if(Member(0)&&a.Member(0)) {tmp.RmvElem(0);}
  tmp.Print();
}
//inclusion
bool Set::Included(Set &a) {
  //if the size of the set is bigger then the other, it's not included
  if (size > a.Card()) {std::cout << "not included." << '\n';return false;}
  //check for every element of the set
  for (size_t i = 0; i < size; i++) {
    if (!(a.Member(set[i]))) {std::cout << "not included." << '\n';return false;}
  }
  std::cout << "included!" << '\n';
  return true;
}

int main() {
  //init set
  Set set1, set2;
  //add elements to set1 with AddElem()
  set1.AddElem(3);
  set1.AddElem(5);
  set1.AddElem(4);
  set1.AddElem(9);
  set1.AddElem(0);
  set1.AddElem(5);
  set1.AddElem(8);

  //print set 1
  std::cout << "printing set 1: " << '\n';
  set1.Print();

  //test RmvElem() function
  set1.RmvElem(8);
  std::cout << "element '8' removed from the set: " << '\n';
  set1.Print();

  //testing maxCard()
  std::cout << "Set 1 maxCardinality: " << set1.MaxCard() << '\n';

  //testing Card()
  std::cout << "Set 1 cardinality: " << set1.Card() << '\n';

  //printing from Elems()
  std::cout << "set 1 Elements: " << '\n';
  for (size_t i = 0; i < set1.Card(); i++) {
    std::cout << set1.Elems()[i] << " ";
  }
  std::cout << '\n';

  //test Member() function
  int num = 3;
  bool isMember = set1&num;
  std::cout << "Testing Member function: " << '\n';
  std::cout << "member with function" << set1.Member(3) << '\n';
  std::cout << "member with operator " << isMember << '\n';

  //test Equal() function
  std::cout << "Testing Equal() function: " << set1.Equal(set1) << '\n';

  //testing copy constructor
  std::cout << "Testing copy constructor: " << '\n';
  Set ccd(set1);
  ccd.Print();
  std::cout << "Testing Equal() function on copied set: " << set1.Equal(ccd) << '\n';

  //test copy constructor
  std::cout << "Testing copy constructor 2: " << '\n';
  std::cout << "Set 1: " << set1 << '\n';
  Set foo = set1;
  std::cout << "foo print after copy from set1" << foo << '\n';
  std::cout << "Testing Equal() function on copied set: " << set1.Equal(foo) << '\n';
  bool isEqual;
  isEqual = (set1==set2);
  std::cout << "testing unequal (!=) operator " << (set1!=set2) << '\n';
  std::cout << "Testing Equal() function on copied set: " << isEqual << '\n';

  //add elements to set 2
  set2.AddElem(9);
  set2.AddElem(8);
  set2.AddElem(10);
  set2.AddElem(20);
  set2.AddElem(0);
  std::cout << "Add a custom element to the second set: ";
  std::cin >> set2;
  std::cout << '\n';

  // print the two sets
  std::cout << "Printing two sets: " << '\n';
  //print function
  set1.Print();
  //operator
  std::cout << set2 << '\n';

  //intersection
  std::cout << "Intersection of the two sets: " << '\n';
  set1.Intersect(set2);
  set1*set2;

  //union
  std::cout << "Union of the two sets: " << '\n';
  set1.Union(set2);
  set1+set2;

  //inclusion of one set to the other
  std::cout << "Inclusion of one set to other: " << '\n';
  set1.Included(set2);
  foo = set1;
  set1<=foo;


  //difference of two sets
  std::cout << "Difference of two sets: " << '\n';
  set1.Difference(set2);
  set1-set2;


  std::cout << "\n" << "end of program";
  return 0;
}
