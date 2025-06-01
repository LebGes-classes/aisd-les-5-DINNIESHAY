#include "PriorityQueue.h"
#include "DurationCounter.h"
#include <ctime>
#include "windows.h"

PriorityQueue queue = PriorityQueue();

//Проверка очереди при добавлении и удалении элементов
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

//Заполнение очереди заданным количеством элементов
void fillQueue(int numOfValues)
{
  std::srand(std::time(0));

  for (int i = 0; i < numOfValues; i++)
  {
    //Приоритет задается рандомно в диапазоне [0, 99]
    int randomPriority = rand() % 100;
    std::string data = std::to_string(randomPriority);

    queue.enqueue(randomPriority, data);
  }
}

//Очищение очереди из заданного количества элементов
void clearQueue(int numOfValues)
{
  for (int i = 0; i < numOfValues; i++)
  {
    queue.dequeue();
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
  DurationCounter durationCounter;
  //Начальное количество входных данных
  const int startNumOfInputData = 10;
  //Конечное количество входных данных
  const int endNumOfInputData = 50;
  //Шаг
  const int step = 5;

  std::cout << "\nСреднее время вставки элементов в очередь для размера входных данных от 10 до 50\n";
  durationCounter.printTimeInRange(fillQueue, startNumOfInputData, endNumOfInputData, step);

  std::cout << "\nСреднее время удаления элементов из очереди для размера входных данных от 10 до 50\n";
  durationCounter.printTimeInRange(clearQueue, startNumOfInputData, endNumOfInputData, step);
}
