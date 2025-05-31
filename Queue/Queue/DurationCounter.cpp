#include "DurationCounter.h"
#include <algorithm>

double DurationCounter::measure(void(*algorithm)(int), int numOfInputData)
{
  double timeResults[numOfRepetitions];

  for (int i = 0; i < numOfRepetitions; i++)
  {
    timePoint_t start = getStartTime();
    algorithm(numOfInputData);
    timePoint_t end = getEndTime();

    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);

    timeResults[i] = duration.count();
  }

  std::sort(std::begin(timeResults), std::end(timeResults));

  const int toKeep = numOfRepetitions * 0.8;
  int averageTime = findMean(timeResults, toKeep);

  return averageTime;
}

timePoint_t DurationCounter::getStartTime()
{
  return std::chrono::high_resolution_clock::now();
}

timePoint_t DurationCounter::getEndTime()
{
  return std::chrono::high_resolution_clock::now();
}

double DurationCounter::findMean(const double array[], const int count)
{
  double sum = 0;

  for (int i = 0; i < count; i++)
  {
    sum += array[i];
  }

  return sum / count;
}
