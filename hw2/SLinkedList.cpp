#include <string>
#include <iostream>
#include "SLinkedList.h"

SLinkedList::SLinkedList() // constructor
 {head = NULL;} //what is this?

SLinkedList::~ SLinkedList() // destructor
{while (!empty()) removeFront();}


bool SLinkedList::empty() const // is list empty ?
{return head == NULL;}

const std::string& SLinkedList::front() const // get front element
{try {
  if (empty()) {
  throw "the list is empty";
}
}
catch (const char* msg) {
  std::cout << msg << '\n';
  return 0;
}
  return head -> elem;
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