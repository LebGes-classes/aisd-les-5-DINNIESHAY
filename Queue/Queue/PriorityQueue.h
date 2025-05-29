#ifndef PRIORITY_QUEUE_H
#define PRIORITY_QUEUE_H

#include <string>
#include <vector>
#include <utility>
#include <iostream>

#include "MinBinaryHeap.h"

/*
  Неубывающая очередь с приоритетами на основе бинарной пирамиды.
  Приоритет - целое число, данные - строка.
  Элементы с меньшими значениями имеют более высокий приоритет.
*/
class PriorityQueue
{
public:

  //Добавление элемента в очередь
  void enqueue(int priority, const std::string & data);

  //Извлечение элемента с наивысшим приоритетом из очереди
  std::string dequeue();

  //Получение элемента с наивысшим приоритетом
  std::string peek();

  //Проверка на пустоту очереди
  bool isEmpty();

  //Вывод элементов очереди
  void print();

private:

  //Item - элемент очереди, который хранит в себе приоритет и данные
  struct Item
  {
    int priority;
    std::string data;

    Item(int priority, std::string data);

    //Перегрузка операторов <, <=, >, >=
    bool operator<(const Item & otherItem) const;

    bool operator<=(const Item & otherItem) const;

    bool operator>(const Item & otherItem) const;

    bool operator>=(const Item & otherItem) const;
  };

  //Минимальная бинарная пирамида
   MinBinaryHeap<Item> heap;
};

#endif