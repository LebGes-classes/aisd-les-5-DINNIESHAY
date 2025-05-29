#include <iostream>

#include "PriorityQueue.h"

int main()
{
  PriorityQueue queue = PriorityQueue();

  queue.enqueue(11, "c");
  queue.enqueue(14, "e");
  queue.enqueue(6, "b");
  queue.enqueue(8, "a");
  queue.enqueue(10, "d");
  queue.enqueue(9, "f");
  queue.enqueue(14, "g");
  queue.enqueue(13, "h");

  queue.print();
  //Результат: b a f d c h e g
}