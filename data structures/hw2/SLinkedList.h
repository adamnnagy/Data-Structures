#include <cstdlib>
#include <string>



class SNode {
private:
  std::string elem; // data element - string here
  SNode* next; // the reference to a pointer of the same type

  friend class SLinkedList;
};

class SLinkedList { // a linked list of strings
public:
  SLinkedList(); // empty list constructor
  ~SLinkedList(); // destructor
  bool empty() const; // is list empty ?
  std::string& front() const; // get front element
  void addFront(const std::string& e); // add to front of list
  void removeFront(); // remove front item list
protected:
  SNode* head; // pointer to the head of list
};
