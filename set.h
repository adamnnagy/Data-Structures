class Set {
private:
  int maxCardinality;
  int size;
  int *set;
public:
  int ElemIndex(int e);
  int MaxCard() {return maxCardinality;}; // The maximal cardinality of the set
  int* Elems() {return set;}; // An integer array containing all the elements of the set
  int Card() const {return size;}; // The effective number of elements in the set
  Set(){maxCardinality = 200; set = new int[maxCardinality];}; //default constructor
  Set(const int num) {maxCardinality = num; set = new int[maxCardinality];}; //One constructor with one argument: the maximal cardinality of the set
  void AddElem(const int e); // Add a new element to the set
  void RmvElem(int e); //  remove one element from the list (by shifting the other elements)
  bool Member(int e); // Verify if a given element is member of the set
  void Copy(Set& copyFrom); // copy one set in another
  bool Equal(Set& a); //verify the equality of two sets
  int* Intersect(Set& a); //compute the intersection of two sets
  int* Union(Set& a); //compute the union of two sets
  void Print(); //display the set, use the mathematics notation

  virtual ~Set () { delete [] set;}; //One destructor
};
