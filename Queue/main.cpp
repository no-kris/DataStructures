#include <iostream>
#include "Queue.h"


int main(int argc, char** argv)
{

  Queue* myQueue = new Queue(1);
  
  myQueue->printQueue();
  
  std::cout << "Enqueueing new items to queue\n";
  myQueue->enqueue(2);
  myQueue->enqueue(4);
  myQueue->enqueue(7);
  myQueue->enqueue(9);
  myQueue->printQueue();
  
  std::cout << "Dequeueing new items to queue\n";
  myQueue->dequeue();
  myQueue->dequeue();
  myQueue->printQueue();
  
  myQueue->getLength();
  
  return 0;
}

