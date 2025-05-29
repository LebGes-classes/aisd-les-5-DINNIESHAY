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
  std::cout << "Результат до удаления элементов: ";
  queue.print();

  queue.dequeue();
  queue.dequeue();
  std::cout << "Результат после удаления элементов: ";
  queue.print();

  /*
    Результат до удаления элементов: b a f d c h e g
    Результат после удаления элементов: f d c h e g
  */
}