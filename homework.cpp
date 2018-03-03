#include <iostream>

class Set {
private:
  int maxCardinality;

public:
  int MaxCard(); // The maximal cardinality of the set
Elems(); // An integer array containing all the elements of the set
Card(); // The effective number of element in the set
Set(); //default constructor
Set (maxCardinality); //One constructor with one argument: the maximal cardinality of the set
virtual ~Set (); //One destructor
AddElem(e); // Add a new element to the set
void RmvElem(); remove one element from the list (by shifting the other elements)
Member(e); // Verify if a given element is member of the set
Copy(); copy one set in another
Equal(); verify the equality of two sets
Intersect(); compute the intersection of two sets
Union(); compute the union of two sets
Print(); display the set, use the mathematics notation
};
