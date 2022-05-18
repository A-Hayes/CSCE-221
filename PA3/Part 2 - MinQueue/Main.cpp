#include "MinQueue.h"

int main(){
  std::cout << std::endl << "Create new MinQueue" << std::endl;
  MinQueue mq;

  // Enqueue 10 randomly picked numbers (from 1 to 100) out of order
  std::cout << "Enqueue 10 numbers" << std::endl << std::endl;
  mq.enqueue(100);
  mq.enqueue(87);
  mq.enqueue(58);
  mq.enqueue(29);
  mq.enqueue(81);
  mq.enqueue(22);
  mq.enqueue(2);
  mq.enqueue(65);
  mq.enqueue(35);
  mq.enqueue(52);

  // Size of queue
  std::cout << "Size: " << mq.size() << std::endl << std::endl;

  // Finds smallest element
  std::cout << "Min: " << mq.min() << std::endl << std::endl;

  // Dequeues all 10 elements
  std::cout << "Dequeued Elements: " << std::endl;
  for(int i = 0; i < 10; i++){
    std::cout << mq.dequeue() << " " << std::endl;
  }

  return 0;
}
