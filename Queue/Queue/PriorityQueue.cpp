#include "PriorityQueue.h"

void PriorityQueue::enqueue(int priority, const std::string & data)
{
  Item item = Item(priority, data);
  heap.push(item);
}

std::string PriorityQueue::dequeue()
{
  //Если очередь пуста, выбрасываем исключение
  if (heap.getSize() == 0)
  {
    throw std::logic_error("Queue is empty.\n");
  }

  Item itemToDel = heap.pop();

  return itemToDel.data;
}

std::string PriorityQueue::peek()
{
  Item minItem = heap.getMin();

  return minItem.data;
}

bool PriorityQueue::isEmpty()
{
  bool isEmpty;

  if (heap.getSize() != 0)
  {
    isEmpty = false;
  }
  else
  {
    isEmpty = true;
  }

  return isEmpty;
}

void PriorityQueue::print()
{
  //Создаём копию очереди и поочереди удаляем из неё элементы, выводя их
  PriorityQueue tempQueue = *this;
  while (!tempQueue.isEmpty())
  {
    std::cout << tempQueue.dequeue() << " ";
  }
  std::cout << std::endl;
}

PriorityQueue::Item::Item(int priority, std::string data)
{
  this->priority = priority;
  this->data = data;
}

bool PriorityQueue::Item::operator<(const Item & otherItem) const
{
  return this->priority < otherItem.priority;
}

bool PriorityQueue::Item::operator<=(const Item & otherItem) const
{
  return this->priority <= otherItem.priority;
}

bool PriorityQueue::Item::operator>(const Item & otherItem) const
{
  return this->priority > otherItem.priority;
}

bool PriorityQueue::Item::operator>=(const Item & otherItem) const
{
  return this->priority >= otherItem.priority;
}

