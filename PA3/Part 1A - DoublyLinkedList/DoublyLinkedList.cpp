#include "DoublyLinkedList.h"
#include <stdexcept>
using namespace std;

// extend range_error from <stdexcept>
struct EmptyDLinkedListException : std::range_error {
  explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg) {}
};

// copy constructor
DoublyLinkedList::DoublyLinkedList(const DoublyLinkedList& dll)
{
  // Initialize the list

  if(dll.header.next != &trailer){
    DListNode * cur_node = new DListNode(dll.getFirst()->obj);
    DListNode * temp = dll.getFirst();
    header.next = cur_node;
    cur_node->prev = &header;
    trailer.prev = cur_node;
    cur_node->next = &trailer;

    temp = temp->next;

    while(temp != dll.getAfterLast()){
      cur_node->next = new DListNode(temp->obj);
      trailer.prev = cur_node->next;
      cur_node->next->next = &trailer;
      cur_node = cur_node->next;
      temp = temp->next;
    }
  }
}

// assignment operator
DoublyLinkedList& DoublyLinkedList::operator=(const DoublyLinkedList& dll)
{
  if(this != &dll){
    // Delete the whole list
    if(header.next == trailer.prev){
      this->clear();
    }

    // if the input list is empty, the current one has been cleared already
    if(dll.isEmpty()){
      return *this;
    }

    // if input list is only 1 node, simplifies things greatly
    if(dll.header.next == dll.trailer.prev){
      DListNode* newNode = new DListNode((dll.getFirst())->obj);
      header.next = newNode;
      trailer.prev = newNode;
      return *this;
    }

    // main copying, node-by-node from dll
    DListNode * cur_node = new DListNode(dll.getFirst()->obj);
    DListNode * temp = dll.getFirst();
    header.next = cur_node;
    cur_node->prev = &header;
    trailer.prev = cur_node;
    cur_node->next = &trailer;

    temp = temp->next;

    while(temp != dll.getAfterLast()){
      cur_node->next = new DListNode(temp->obj);
      trailer.prev = cur_node->next;
      cur_node->next->next = &trailer;
      cur_node = cur_node->next;
      temp = temp->next;
    }
  }
  return *this;
}

// insert the new object as the first one
void DoublyLinkedList::insertFirst(int newobj)
{
    DListNode* newNode = new DListNode(newobj);
    newNode->prev = &header;
    newNode->next = header.next;
    header.next->prev = newNode;
    header.next = newNode;
    return;
}

// insert the new object as the last one
void DoublyLinkedList::insertLast(int newobj)
{
  DListNode* newNode = new DListNode(newobj);
  newNode->next = &trailer;
  newNode->prev = trailer.prev;
  trailer.prev->next = newNode;
  trailer.prev = newNode;
  return;
}

// remove the first object from the list
// Returns the value of the deleted node
// Or 0 as default if list is empty
int DoublyLinkedList::removeFirst()
{
    if (this == nullptr){
      return 0;
    }
    int delObj = header.next->obj;
    if(header.next == &trailer){
      return 0;
    } else {
      DListNode* temp = header.next;
      header.next = temp->next;
      temp->next->prev = &header;
      temp = nullptr;
    }
    return delObj;
}

// remove the last object from the list
// Returns the value of the deleted node
// Or 0 as default if list is empty
int DoublyLinkedList::removeLast()
{
  if (this == nullptr){
    return 0;
  }
  int delObj = trailer.prev->obj;
  if(trailer.prev == &header){
    return 0;
  } else {
    DListNode* temp = trailer.prev;
    trailer.prev = temp->prev;
    temp->prev->next = &trailer;
    temp = nullptr;
  }
  return delObj;
}

// destructor
DoublyLinkedList::~DoublyLinkedList()
{
    this->clear();
}

// return the first object
int DoublyLinkedList::first() const
{
    return header.obj;
}

// return the last object
int DoublyLinkedList::last() const
{
    return trailer.obj;
}

// insert the new object after the node p
void DoublyLinkedList::insertAfter(DListNode &p, int newobj)
{
  DListNode* newNode = new DListNode(newobj);
  if(p.next->next == nullptr){
    throw range_error("Cannot insert after trailer");
  } else {
    newNode->prev = &p;
    newNode->next = p.next;
    p.next->prev = newNode;
    p.next = newNode;
  }
  return;
}

// insert the new object before the node p
void DoublyLinkedList::insertBefore(DListNode &p, int newobj)
{
  DListNode* newNode = new DListNode(newobj);
  if(p.prev == nullptr){
    throw range_error("Cannot insert before header");
  } else {
    newNode->next = &p;
    newNode->prev = p.prev;
    p.prev->next = newNode;
    p.prev = newNode;
  }
  return;
}

// remove the node after the node p
int DoublyLinkedList::removeAfter(DListNode &p)
{
    if (p.next == nullptr || p.next->next == nullptr) {
      throw range_error("Cannot delete trailer or after trailer");
    } else {
      DListNode* temp = p.next;
      int delObj = temp->obj;
      temp->next->prev = &p;
      p.next = temp->next;
      temp = nullptr;
      return delObj;
    }
}

// remove the node before the node p
int DoublyLinkedList::removeBefore(DListNode &p)
{
    if (p.prev == nullptr || p.prev->prev == nullptr) {
      throw range_error("Cannot delete header or before header");
    } else {
      DListNode* temp = p.prev;
      int delObj = temp->obj;
      temp->prev->next = &p;
      p.prev = temp->prev;
      temp = nullptr;
      return delObj;
    }
}

// clears all nodes from list
void DoublyLinkedList::clear(){
  DListNode* current = this->getFirst();
    while (current != nullptr) {
        DListNode* deleteNode = current;
        current = current->next;
        delete deleteNode;
    }
}

// return the list length
int DoublyLinkedListLength(const DoublyLinkedList& dll)
{
    int count;
    if(dll.getFirst()->next == dll.getAfterLast()){
      return 0;
    }
    DListNode* temp = dll.getFirst();
    while(temp != dll.getAfterLast()){
      count++;
      temp = temp->next;
    }
    return count;
}

// output operator
ostream& operator<<(ostream& out, const DoublyLinkedList& dll)
{
    DListNode* temp = dll.getFirst();
    while(temp->next != nullptr){
      out << temp->obj << " " ;
      temp = temp->next;
    }
    return out;
}
