#include "PriorityQueue.h"
#include "DurationCounter.h"
#include <ctime>
#include "windows.h"

//Проверка очереди при добавлении и удалении элементов
void checkQueue()
{
  PriorityQueue queue = PriorityQueue();

  /*
    Ожидается:
    Результат до удаления элементов: b a f d c h e g
    Результат после удаления элементов: f d c h e g
  */
  queue.enqueue(11, "c");
  queue.enqueue(14, "e");
  queue.enqueue(6, "b");
  queue.enqueue(8, "a");
  queue.enqueue(10, "d");
  queue.enqueue(9, "f");
  queue.enqueue(14, "g");
  queue.enqueue(13, "h");
  std::cout << "Result before deleting elements: ";
  queue.print();

  queue.dequeue();
  queue.dequeue();
  std::cout << "Result after deleting elements: ";
  queue.print();
}

int getRandomInt()
{
  //Получение рандомного числа в диапазоне [0, 99]
  int randomInt = rand() % 100;

  return randomInt;
}

//Заполнение очереди заданным количеством элементов
PriorityQueue getFilledQueue(int numOfValues)
{
  PriorityQueue queue = PriorityQueue();

  for (int i = 0; i < numOfValues; i++)
  {
    int randomPriority = getRandomInt();
    std::string data = std::to_string(randomPriority);

    queue.enqueue(randomPriority, data);
  }

  return queue;
}

int main()
{
  std::srand(std::time(0));

  //Проверка очереди при добавлении и удалении элементов
  std::cout << "\nAdding and deleting elements in queue\n";
  checkQueue();
 
  //Исследование производительности методов очереди
  DurationCounter durationCounter;
  //Начальное количество входных данных
  const int startNumOfInputData = 10;
  //Конечное количество входных данных
  const int endNumOfInputData = 50;
  //Шаг
  const int step = 5;

  std::cout << "\nAverage time of priority queue methods:\n";

  for (int n = startNumOfInputData; n <= endNumOfInputData; n += step)
  {
    PriorityQueue queue = getFilledQueue(n);

    std::cout << "\nTime for n = " << n << ":\n";

    std::cout << "enqueue - " 
              << durationCounter.measure([&queue]() {
                 queue.enqueue(getRandomInt(), "data"); }) << ", ";
    
    std::cout << "dequeue - "
              << durationCounter.measure([&queue]() {
                 queue.dequeue(); }) << ", ";

    std::cout << "peek - "
              << durationCounter.measure([&queue]() {
                 queue.peek(); }) << std::endl;
  }
}
