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
  Set& operator=(Set other) {
      Copy(other);
  }
    // verify if a given integer is a member of the set
  Set& operator&(int other){
      Member(other);
  }
    // verify the equality of two sets
  Set& operator==(Set other){
      Equal(other);
  }
    // verify the inequality of two sets
  Set& operator!=(Set other){
      !Equal(other);
  }
    // compute the intersection of two sets
  Set& operator*(Set other){
      Intersect(other);
  }
    // compute the union of two sets
  Set& operator+(Set other){
      Union(other);
  }
  //these would be easy if i had the intersection and union figured out
    // compute the difference of two sets
  Set& operator-(Set other){

  }
    // verify the inclusion of one set inside another
  Set& operator<=(Set other) {

  }
    // display the content of a set
  Set& operator<<(int other){
      Print();
  }
    // input the content of a set
  Set& operator>>(int other){
      this->AddElem(other);
  }

  Set(){maxCardinality = 200; set = new int[maxCardinality];}; //default constructor
  Set(int *arr){maxCardinality = 200; set = new int[maxCardinality]; set = arr;}; //default constructor
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
  virtual ~Set () { delete [] set;};
};
