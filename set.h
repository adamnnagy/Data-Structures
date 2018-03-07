#include <iostream>

class Set {
private:
  int maxCardinality;
  int size;
  int *set;
public:
  //getters
  int ElemIndex(int e);
  int MaxCard() {return maxCardinality;}; // The maximal cardinality of the set
  int* Elems() {return set;}; // An integer array containing all the elements of the set
  int Card() const {return size;}; // The effective number of elements in the set

  //copy Constructor
  Set(const Set &obj);

  //Assignment Operator
  Set& operator=(Set &obj) {
      Copy(obj);
  }
    // verify if a given integer is a member of the set
  Set& operator&(int &obj){
      Member(obj);
  }
    // verify the equality of two sets
  Set& operator==(Set &obj){
      Equal(obj);
  }
    // verify the inequality of two sets
  Set& operator!=(Set &obj){
      !Equal(obj);
  }
    // compute the intersection of two sets
  Set& operator*(Set &obj){
      Intersect(obj);
  }
    // compute the union of two sets
  Set& operator+(Set &obj){
      Union(obj);
  }
  //these would be easy if i had the intersection and union figured out
    // compute the difference of two sets
  Set& operator-(Set &obj){

  }
    // verify the inclusion of one set inside another
  Set& operator<=(Set &obj) {
    // return Intersect(other).Equal();
  }
    // display the content of a set
  friend std::ostream& operator<< (std::ostream& os, Set &a){
      a.Print();
  }
    // input the content of a set
  friend std::istream& operator>> (std::istream& input, Set &a){
    int e;
    input >> e;
    a.AddElem(e);
    // return is;
  }

  //constructors
  Set(){maxCardinality = 200; set = new int[maxCardinality]; size = 0;}; //default constructor
  Set(int *arr){maxCardinality = 200; set = new int[maxCardinality]; *set = *arr;}; //default constructor
  Set(const int num) {maxCardinality = num; set = new int[maxCardinality];}; //One constructor with one argument: the maximal cardinality of the set

  //setters
  void AddElem(const int e); // Add a new element to the set
  void RmvElem(int e); //  remove one element from the list (by shifting the other elements)
  bool Member(int e); // Verify if a given element is member of the set

  void Copy(Set& copyFrom); // copy one set in another
  bool Equal(Set& a); //verify the equality of two sets

  int* Intersect(Set& a); //compute the intersection of two sets
  int* Union(Set& a); //compute the union of two sets

  //display set
  void Print(); //display the set, use the mathematics notation

  //destructor
  virtual ~Set () {delete [] set;};
};
