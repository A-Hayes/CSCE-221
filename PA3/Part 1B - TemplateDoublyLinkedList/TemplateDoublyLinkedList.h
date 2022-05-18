#include <cstdlib>
#include <iostream>
#include <stdexcept>
using namespace std;

template <typename T>
struct DListNode {
  T obj{};
  DListNode<T> *prev, *next;
  DListNode(T e) : obj(e), prev(nullptr), next(nullptr) {}
  DListNode() : prev(nullptr), next(nullptr) {}
};

template <typename T>
class DoublyLinkedList {
private:
  DListNode<T> header, trailer;
public:
  DoublyLinkedList(); // constructor
  DoublyLinkedList(const DoublyLinkedList<T>& dll); // copy constructor
  ~DoublyLinkedList(); // destructor
  DoublyLinkedList& operator=(const DoublyLinkedList<T>& dll); // assignment operator
  // return the pointer to the first node
  DListNode<T> *getFirst() const { return header.next; }
  // return the pointer to the trailer
  const DListNode<T> *getAfterLast() const { return &trailer; }
  // return if the list is empty
  bool isEmpty() const { return header.next == &trailer; }
  T first() const; // return the first object
  T last() const; // return the last object
  void insertFirst(T newobj); // insert to the first of the list
  T removeFirst(); // remove the first node
  void insertLast(T newobj); // insert to the last of the list
  T removeLast(); // remove the last node
  void insertAfter(DListNode<T> &p, T newobj);
  void insertBefore(DListNode<T> &p, T newobj);
  void clear(); // clears all nodes from the list
  T removeAfter(DListNode<T> &p);
  T removeBefore(DListNode<T> &p);
};

// output operator
template <typename T>
std::ostream& operator<<(std::ostream& out, const DoublyLinkedList<T>& dll);
// return the list length
template <typename T>
int DoublyLinkedListLength(const DoublyLinkedList<T>& dll);

/*

  END OF HEADER SECTION

*/

struct EmptyDLinkedListException : std::range_error {
  explicit EmptyDLinkedListException(char const* msg=NULL): range_error(msg) {}
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : header(), trailer() // constructor
{
  header.next = &trailer;
  trailer.prev = &header;
}

// copy constructor
template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList<T>& dll)
{
  // Initialize the list

  if(dll.header.next != &trailer){
    DListNode<T> * cur_node = new DListNode<T>(dll.getFirst()->obj);
    DListNode<T> * temp = dll.getFirst();
    header.next = cur_node;
    cur_node->prev = &header;
    trailer.prev = cur_node;
    cur_node->next = &trailer;

    temp = temp->next;

    while(temp != dll.getAfterLast()){
      cur_node->next = new DListNode<T>(temp->obj);
      trailer.prev = cur_node->next;
      cur_node->next->next = &trailer;
      cur_node = cur_node->next;
      temp = temp->next;
    }
  }
}

// assignment operator
template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList& dll)
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
      DListNode<T>* newNode = new DListNode<T>((dll.getFirst())->obj);
      header.next = newNode;
      trailer.prev = newNode;
      return *this;
    }

    // main copying, node-by-node from dll
    DListNode<T> * cur_node = new DListNode<T>(dll.getFirst()->obj);
    DListNode<T> * temp = dll.getFirst();
    header.next = cur_node;
    cur_node->prev = &header;
    trailer.prev = cur_node;
    cur_node->next = &trailer;

    temp = temp->next;

    while(temp != dll.getAfterLast()){
      cur_node->next = new DListNode<T>(temp->obj);
      trailer.prev = cur_node->next;
      cur_node->next->next = &trailer;
      cur_node = cur_node->next;
      temp = temp->next;
    }
  }
  return *this;
}

// insert the new object as the first one
template <typename T>
void DoublyLinkedList<T>::insertFirst(T newobj)
{
    DListNode<T>* newNode = new DListNode<T>(newobj);
    newNode->prev = &header;
    newNode->next = header.next;
    header.next->prev = newNode;
    header.next = newNode;
    return;
}

// insert the new object as the last one
template <typename T>
void DoublyLinkedList<T>::insertLast(T newobj)
{
  DListNode<T>* newNode = new DListNode<T>(newobj);
  newNode->next = &trailer;
  newNode->prev = trailer.prev;
  trailer.prev->next = newNode;
  trailer.prev = newNode;
  return;
}

// remove the first object from the list
// Returns the value of the deleted node
// Or 0 as default if list is empty
template <typename T>
T DoublyLinkedList<T>::removeFirst()
{
    if (this == nullptr){
      return 0;
    }
    T delObj = header.next->obj;
    if(header.next == &trailer){
      return 0;
    } else {
      DListNode<T>* temp = header.next;
      header.next = temp->next;
      temp->next->prev = &header;
      temp = nullptr;
    }
    return delObj;
}

// remove the last object from the list
// Returns the value of the deleted node
// Or 0 as default if list is empty
template <typename T>
T DoublyLinkedList<T>::removeLast()
{
  if (this == nullptr){
    return 0;
  }
  T delObj = trailer.prev->obj;
  if(trailer.prev == &header){
    return 0;
  } else {
    DListNode<T>* temp = trailer.prev;
    trailer.prev = temp->prev;
    temp->prev->next = &trailer;
    temp = nullptr;
  }
  return delObj;
}

// destructor
template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    this->clear();
}

// return the first object
template <typename T>
T DoublyLinkedList<T>::first() const
{
    return header.obj;
}

// return the last object
template <typename T>
T DoublyLinkedList<T>::last() const
{
    return trailer.obj;
}

// insert the new object after the node p
template <typename T>
void DoublyLinkedList<T>::insertAfter(DListNode<T> &p, T newobj)
{
  DListNode<T>* newNode = new DListNode<T>(newobj);
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
template <typename T>
void DoublyLinkedList<T>::insertBefore(DListNode<T> &p, T newobj)
{
  DListNode<T>* newNode = new DListNode<T>(newobj);
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
template <typename T>
T DoublyLinkedList<T>::removeAfter(DListNode<T> &p)
{
    if (p.next == nullptr || p.next->next == nullptr) {
      throw range_error("Cannot delete trailer or after trailer");
    } else {
      DListNode<T>* temp = p.next;
      T delObj = temp->obj;
      temp->next->prev = &p;
      p.next = temp->next;
      temp = nullptr;
      return delObj;
    }
}

// remove the node before the node p
template <typename T>
T DoublyLinkedList<T>::removeBefore(DListNode<T> &p)
{
    if (p.prev == nullptr || p.prev->prev == nullptr) {
      throw range_error("Cannot delete header or before header");
    } else {
      DListNode<T>* temp = p.prev;
      T delObj = temp->obj;
      temp->prev->next = &p;
      p.prev = temp->prev;
      temp = nullptr;
      return delObj;
    }
}

// clears all nodes from list
template <typename T>
void DoublyLinkedList<T>::clear(){
  DListNode<T>* current = this->getFirst();
    while (current != nullptr) {
        DListNode<T>* deleteNode = current;
        current = current->next;
        delete deleteNode;
    }
}

// return the list length
template <typename T>
int DoublyLinkedListLength(const DoublyLinkedList<T>& dll)
{
    int count;
    if(dll.getFirst()->next == dll.getAfterLast()){
      return 0;
    }
    DListNode<T>* temp = dll.getFirst();
    while(temp != dll.getAfterLast()){
      count++;
      temp = temp->next;
    }
    return count;
}

// output operator
template <typename T>
ostream& operator<<(ostream& out, const DoublyLinkedList<T>& dll)
{
    DListNode<T>* temp = dll.getFirst();
    while(temp->next != nullptr){
      out << temp->obj << " " ;
      temp = temp->next;
    }
    return out;
}
