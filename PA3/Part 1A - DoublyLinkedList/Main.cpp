#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;
int main () {
  // Construct a linked list with header & trailer
  cout << "Constructors & Basic Insert/Delete(Front/Back)" << endl << endl;

  cout << "Create a new list" << endl;
  DoublyLinkedList dll;
  cout << "list: " << dll << endl << "dll size: " << DoublyLinkedListLength(dll) << endl << endl;

  // Insert 10 nodes at back with value 10,20,30,..,100
  cout << "Insert 10 nodes at back with value 10,20,30,..,100" << endl;
  for (int i=10;i<=100;i+=10) {
    dll.insertLast(i);
  }
  cout << "list: " << dll << endl << "dll size: " << DoublyLinkedListLength(dll) << endl << endl;

  // Insert 10 nodes at front with value 10,20,30,..,100
  cout << "Insert 10 nodes at front with value 10,20,30,..,100" << endl;
  for (int i=10;i<=100;i+=10) {
    dll.insertFirst(i);
  }
  cout << "list: " << dll << endl << "dll size: " << DoublyLinkedListLength(dll) << endl << endl;

  // Copy to a new list
  cout << "Copy to a new list" << endl;
  DoublyLinkedList dll2(dll);
  cout << "list2: " << dll2 << endl << "dll2 size: " << DoublyLinkedListLength(dll2) << endl << endl;

  // Assign to another new list
  cout << "Assign to another new list" << endl;
  DoublyLinkedList dll3;
  cout << "dll3: " << dll3 << endl;
  cout << "dll: " << dll << endl;
  dll3=dll;
  cout << "dll3: " << dll3 << endl << "dll3 size: " << DoublyLinkedListLength(dll3) << endl << endl;

  // Delete the last 10 nodes
  cout << "Delete the last 10 nodes" << endl;
  for (int i=0;i<10;i++) {
    dll.removeLast();
  }
  cout << "list: " << dll << endl << "dll size: " << DoublyLinkedListLength(dll) << endl << endl;

  // Delete the first 10 nodes
  cout << "Delete the first 10 nodes" << endl;
  for (int i=0;i<10;i++) {
    dll.removeFirst();
  }
  cout << "list: " << dll << endl << "dll size: " << DoublyLinkedListLength(dll) << endl << endl;

  // Check the other two lists
  cout << "Make sure the other two lists are not affected." << endl;
  cout << "list2: " << dll2 << endl;
  cout << "list3: " << dll3 << endl << endl;

  // more testing...

  // Fill dll with 10 values
  for (int i=10;i<=100;i+=10) {
    dll.insertFirst(i);
  }

  // add tests for insertAfter, insertBefore

  cout << "Specific Insert(Before/After)" << endl << endl;

  // Insert after fifth

  cout << "Insert after fifth" << endl;
  dll.insertAfter(*dll.getFirst()->next->next->next->next, 1);
  cout << "list: " << dll << endl << "dll size: " << DoublyLinkedListLength(dll) << endl << endl;

  // Insert after front

  cout << "Insert after front" << endl;
  dll.insertAfter(*dll.getFirst(), 2);
  cout << "list: " << dll << endl << "dll size: " << DoublyLinkedListLength(dll) << endl << endl;

  // Insert before fifth

  cout << "Insert before fifth" << endl;
  dll.insertBefore(*dll.getFirst()->next->next->next->next, 1);
  cout << "list: " << dll << endl << "dll size: " << DoublyLinkedListLength(dll) << endl << endl;

  // Insert before front

  cout << "Insert before front" << endl;
  dll.insertBefore(*dll.getFirst(), 2);
  cout << "list: " << dll << endl << "dll size: " << DoublyLinkedListLength(dll) << endl << endl;


  // add tests for removeAfter, removeBefore

  cout << "Specific Remove(Before/After)" << endl << endl;

  // Remove after fifth

  cout << "Remove after fifth" << endl;
  cout << dll.removeAfter(*dll.getFirst()->next->next->next->next) << endl;
  cout << "list: " << &dll << endl << "dll size: " << DoublyLinkedListLength(dll) << endl << endl;

  // Insert after front

  cout << "Remove after front" << endl;
  cout << dll.removeAfter(*dll.getFirst()) << endl;
  cout << "list: " << dll << endl << "dll size: " << DoublyLinkedListLength(dll) << endl << endl;

  // Insert before fifth

  cout << "Remove before fifth" << endl;
  cout << dll.removeBefore(*dll.getFirst()->next->next->next->next) << endl;
  cout << "list: " << dll << endl << "dll size: " << DoublyLinkedListLength(dll) << endl << endl;

  // Insert before front

  cout << "Remove before trailer" << endl;
  cout << dll.removeBefore(*dll.getAfterLast()->prev) << endl;
  cout << "list: " << dll << endl << "dll size: " << DoublyLinkedListLength(dll) << endl;




  return 0;
}
