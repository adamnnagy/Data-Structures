#include <string>
#include <iostream>
#include "SLinkedList.h"

SLinkedList::SLinkedList() : head(NULL) { } //what is this?

SLinkedList::~ SLinkedList() // destructor
{while (!empty()) removeFront();}


bool SLinkedList::empty() const // is list empty ?
{return head == NULL;}

std::string& SLinkedList::front() const { // get front element
  try { if (empty()) throw "The list is empty"; //empty list
   return head -> elem;
 }
 catch (const char* str) {
   std::cout << "The list is empty" << '\n';
   // std::string foo = "foo";
   // return foo;
 }
}

void SLinkedList::addFront(const std::string& e) { // add to front of list
  SNode* v = new SNode; // create new node
  v -> elem = e; // save data
  v -> next = head; // previous head now follows v
  head = v; // v is now the head
}

void SLinkedList::removeFront() { // remove the item from front
  SNode* old = head; // save current head
  if (head == NULL) {
  std::cout << "The list is empty" << '\n';
  } else {
      head = old -> next; // the head will be the next of the old
      delete old; // old head gets deleted
  }
}

int main() {
  SLinkedList a;
  std::string Message = a.empty() ? "empty" : "not empty";
  std::cout << Message << '\n';
  // std::cout << a.front() << '\n';
  std::cout << "adding element to a" << '\n';
  std::string myString = "harminc";
  a.addFront(myString);
  std::cout << a.front() << '\n';
  std::cout << "removing the front from a" << '\n';
  a.removeFront();

  return 0;
}
