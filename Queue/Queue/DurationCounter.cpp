#include "DurationCounter.h"
#include <algorithm>
#include <iostream>

//Измерение времени работы заданного алгоритма с заданным количеством входных данных
long long DurationCounter::measure(void(*algorithm)(int), int numOfInputData)
{
  //Список измерений времени
  long long timeResults[numOfRepetitions];

  for (int i = 0; i < numOfRepetitions; i++)
  {
    //Начальное время
    timePoint_t start = getStartTime();
    //Выполнение алгоритма
    algorithm(numOfInputData);
    //Конечное время
    timePoint_t end = getEndTime();

    //Длительность работы алгоритма
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    //Добавление результата в список измерений времени
    timeResults[i] = duration.count();
  }

  //Сортировка времени по возрастанию
  std::sort(std::begin(timeResults), std::end(timeResults));

  //Получаем среднее арифметическое от первых 80% значений времени
  const int toKeep = numOfRepetitions * 0.8;
  int averageTime = findMean(timeResults, toKeep);

  return averageTime;
}

//Вывод времени работы алгоритма с входными данными из диапазона
void DurationCounter::printTimeInRange(void(*algorithm)(int), int start, int end, int step)
{
  for (int n = start; n <= end; n += step)
  {
    //Измеряем время алгоритма для n-го количества входных данных
    long long averageTime = measure(algorithm, n);
    std::cout << "Время для " << n << ": " << averageTime << " нс\n";
  }
}

//Получение начального времени
timePoint_t DurationCounter::getStartTime()
{
  return std::chrono::high_resolution_clock::now();
}

//Получение конечного времени
timePoint_t DurationCounter::getEndTime()
{
  return std::chrono::high_resolution_clock::now();
}

//Получение среднего арифметического из элементов списка
long long DurationCounter::findMean(const long long array[], const int count)
{
  long long sum = 0;

  for (int i = 0; i < count; i++)
  {
    sum += array[i];
  }

  return std::llround(sum / count);
}
