#include <string>
#include "studentRoll.h"

StudentRoll::StudentRoll() {
  head = tail = NULL;
}

void StudentRoll::insertAtTail(const Student &s) {
  Node* newNode = new Node;
  newNode->s = new Student(s);;
  newNode->next = NULL;
    if (tail == NULL) { // If list is empty
      head = tail = newNode;
    }
    else {
      tail->next = newNode;
      tail = newNode;
    }
}

std::string StudentRoll::toString() const {
  std::string result;
  Node* current = head;
  result += "[";
  if (current == NULL){
    result +="]";
    return result;
  }
  result += current->s->toString();
  while (current->next != NULL) {
    result +="," +current->next->s->toString(); 
    current = current->next;
  }
  result +="]";
  return result;
}

StudentRoll::StudentRoll(const StudentRoll &orig) {

  head = tail = NULL;
  Node* current = orig.head;
  while (current != NULL) {
    insertAtTail(*current->s);
    current = current->next;
  }
}

StudentRoll::~StudentRoll() {
  Node* current = head;
  while (current != NULL){
    Node* next = current->next;
    delete current;
    current = next;
  }
}

StudentRoll & StudentRoll::operator =(const StudentRoll &right ) {
  // The next two lines are standard, and you should keep them.
  // They avoid problems with self-assignment where you might free up 
  // memory before you copy from it.  (e.g. x = x)

  if (&right == this) 
    return (*this);
  this->~StudentRoll();
  Node* current = right.head;
    while (current != NULL) {
    insertAtTail(*current->s);
    current = current->next;
  }
  return (*this); 
  
}





