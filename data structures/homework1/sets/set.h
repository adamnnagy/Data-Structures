#include <iostream>

class Set {
private:
  int maxCardinality;
  int size;
  int *set;
public:
  //constructors

  //default constructor
  Set(){maxCardinality = 20; set = new int[maxCardinality]; size = 0;};
  //default constructor
  Set(int *arr){maxCardinality = 20; set = new int[maxCardinality]; *set = *arr; size = 0;};
  //One constructor with one argument: the maximal cardinality of the set
  Set(const int num) {maxCardinality = num; set = new int[maxCardinality]; size = 0;};

  //getters
  int ElemIndex(int e);
  int MaxCard() const {return maxCardinality;}; // The maximal cardinality of the set
  int* Elems() const {return set;}; // An integer array containing all the elements of the set
  int Card() const {return size;}; // The effective number of elements in the set
  bool Member(int e); // Verify if a given element is member of the set

  //setter
  void AddElem(const int e); // Add a new element to the set
  void RmvElem(int e); //  remove one element from the list (by shifting the other elements)

//operator overloading

  //copy Constructor
  Set(const Set &obj);
  //Assignment Operator
  void operator=(Set &obj) {Copy(obj);}
    // verify if a given integer is a member of the set
  bool operator&(int obj){return Member(obj);}
    // verify the equality of two sets
  bool operator==(Set &obj){return Equal(obj);}
    // verify the inequality of two sets
  bool operator!=(Set &obj){return !Equal(obj);}
    // compute the intersection of two sets
  void operator*(Set &obj){Intersect(obj);}
    // compute the union of two sets
  void operator+(Set &obj){Union(obj);}
  //these would be easy if i had the intersection and union figured out
    // compute the difference of two sets
  void operator-(Set &obj){Difference(obj);}
    // verify the inclusion of one set inside another
  bool operator<=(Set &obj) {return Included(obj);}
    // display the content of a set
  friend std::ostream& operator<< (std::ostream& os, Set &a){a.Print();}
    // input the content of a set
  friend std::istream& operator>> (std::istream& input, Set &a){int e;input >> e;a.AddElem(e);}

   // copy one set in another
  void Copy(const Set &copyFrom);
  //verify the equality of two sets
  bool Equal(Set &a);

  //compute the intersection of two sets
  void Intersect(Set &a);
  //compute the union of two sets
  void Union(Set &a);
  //difference:
  void Difference(Set &a);
  //inclusion
  bool Included(Set &a);

  //display set
  void Print(); //display the set, use the mathematics notation

  //destructor
  virtual ~Set () {delete [] set;};
};
