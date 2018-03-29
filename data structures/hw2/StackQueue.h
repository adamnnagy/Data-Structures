#include "SLinkedList.h"

class StackQueue : public SLinkedList {
public:
  StackQueue(); // constructor
  int size() const; //get size of the stack
  const Elem& top() const throw(EmptyException); // simply use front()
  //for push we have addFront(const std::string& e) already -- inherit
  void push(const std::string& e);
  void pop() throw (EmptyException);
private:
  SLinkedList S;
  int size;
};
