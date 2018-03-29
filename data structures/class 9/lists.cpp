#include <iostream>

class SNode {

}

class SLList {
private:

public:
  void SLList::display();
  void SLList::add(int val);
  void SLList::append(int val);
  void SLList::removeLast();
}

void main() {

}

void SLList::append(int val) {
  if (head == NULL) add(val); //this calls the add function when the list is empty
  SNode* curr = head;
  while (curr->next != NULL) curr = curr->next;

  SNode* temp = new SNode(val);
  curr->next = temp;
}

void SLList::display() {
  if (head == NULL) {
    std::cout << "the list is empty" << '\n';
  }
  SNode *curr = head;
  while (curr!=NULL && curr -> data != val) { //if the node contains
    std::cout << curr->data<< '\n';
    curr = curr->next;
  }
  std::cout << '\n';
}

void SLList::add(int val) {
  SNode *temp = new SNode(val);
}

void SLList::removeLast(){
    if (head == NULL) {
      return 9999;
    }
    SNode* curr = head;
    SNode* prev = head;

    while (curr->next != NULL) {
      prev = curr;
      curr= curr->next;
    }

    prev->next = NULL;
    delete curr;
    return temp;
}

void SLList::insert(int val, int pos) {
  if (pos <= 0) add(val);
  SNode* curr = head;
  int n = 0;
  while(curr!=NULL && n < pos) {
    curr = curr -> enxt;
    n++;
  }
  if (curr == NULL) append(val);
  else {
    SNode* tmp = new SNode(val);
    tmp -> next = curr -> next;
    curr -> next = tmp;
  }

}
