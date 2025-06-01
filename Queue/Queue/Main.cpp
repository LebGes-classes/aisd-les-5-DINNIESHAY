#include "PriorityQueue.h"
#include "DurationCounter.h"
#include <iostream>
#include <ctime>
#include <iomanip>
#include "windows.h"

PriorityQueue queue = PriorityQueue();

void checkQueue()
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
    Ожидается:
    Результат до удаления элементов: b a f d c h e g
    Результат после удаления элементов: f d c h e g
  */
}

void fillQueue(int numOfValues)
{
  std::srand(std::time(0));

  for (int i = 0; i < numOfValues; i++)
  {
    int randomPriority = rand() % 100;
    std::string data = std::to_string(randomPriority);

    queue.enqueue(randomPriority, data);
  }
}

void clearQueue(int numOfValues)
{
  std::srand(std::time(0));

  for (int i = 0; i < numOfValues; i++)
  {
    queue.dequeue();
  }
}

void getAverageTimeOf(void(*algorithm)(int))
{
  DurationCounter durationCounter;

  const int startNumOfInputData = 10;
  const int endNumOfInputData = 50;
  const int dN = 5;

  for (int n = startNumOfInputData; n <= endNumOfInputData; n += dN)
  {
    auto averageTime = durationCounter.measure(algorithm, n);
    std::cout << "Время для " << n << ": " << std::fixed << std::setprecision(0) << averageTime << " нс\n";
  }
}

int main()
{
  SetConsoleCP(1251);
  SetConsoleOutputCP(1251);

  //Проверка очереди при добавлении и удалении элементов
  std::cout << "\nДобавление и удаление элементов очереди\n";
  checkQueue();
 
  //Исследование производительности методов очереди
  std::cout << "\nСреднее время вставки элементов в очередь для размера входных данных от 10 до 50\n";
  getAverageTimeOf(fillQueue);

  std::cout << "\nСреднее время удаления элементов из очереди для размера входных данных от 10 до 50\n";
  getAverageTimeOf(clearQueue);
}
