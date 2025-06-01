#ifndef DURATION_COUNTER_H
#define DURATION_COUNTER_H

#include <chrono>

using timePoint_t = std::chrono::high_resolution_clock::time_point;

class DurationCounter
{
public:

  //Измерение времени работы заданного алгоритма с заданным количеством входных данных
  long long measure(void(*algorithm)(int), int numOfInputData);
  //Вывод времени работы алгоритма с входными данными из диапазона
  void printTimeInRange(void(*alorithm)(int), int start, int end, int step);

private:

  //Количество повторений измерения
  static const int numOfRepetitions = 5;

  //Получение начального времени
  timePoint_t getStartTime();
  //Получение конечного времени
  timePoint_t getEndTime();
  //Получение среднего арифметического из элементов списка
  long long findMean(const long long array[], const int count);
};

#endif