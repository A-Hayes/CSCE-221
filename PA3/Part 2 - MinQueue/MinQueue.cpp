#include "MinQueue.h"
#include <limits>

int MinQueue::first( ) throw(QueueEmptyException)
{
  if ( isEmpty() ){
    throw QueueEmptyException("Access to an empty queue");
  }
  return ll.first();
}

int MinQueue::dequeue() throw(QueueEmptyException)
{
  if ( ll.isEmpty() ){
    throw QueueEmptyException("Access to an empty queue");
  }
  queueSize--;
  return ll.removeFirst();
}

int MinQueue::min()
{
  DListNode* temp = ll.getFirst();
  int min = temp->obj;
  temp = temp->next;
  while (temp != ll.getAfterLast()) {
    if(temp->obj < min){
      min = temp->obj;
    }
    temp = temp->next;
  }
  return min;
}

int MinQueue::size()
{
  return queueSize;
}
