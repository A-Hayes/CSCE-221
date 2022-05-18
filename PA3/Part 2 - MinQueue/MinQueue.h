#include "DoublyLinkedList.h"

struct QueueEmptyException : std::range_error {
  explicit QueueEmptyException(char const* msg=NULL): range_error(msg) {}
};

class MinQueue {
private:
  DoublyLinkedList ll;
  int queueSize = 0;
public:
  MinQueue() : ll() {} // constructor
  ~MinQueue() { ll.~DoublyLinkedList(); } //destructor
  bool isEmpty( ) const {  return ll.isEmpty();  }
  int first( ) throw(QueueEmptyException);
  void enqueue(int x) { ll.insertLast(x); queueSize++; }
  int dequeue( ) throw(QueueEmptyException);
  int size();
  int min();
};
