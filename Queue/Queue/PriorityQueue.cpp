#include "PriorityQueue.h"

void PriorityQueue::enqueue(int priority, const std::string & data)
{
  Item item = Item(priority, data);
  heap.push(item);
}

std::string PriorityQueue::dequeue()
{
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
  while (heap.getSize() != 0)
  {
    std::cout << dequeue() << " ";
  }
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

