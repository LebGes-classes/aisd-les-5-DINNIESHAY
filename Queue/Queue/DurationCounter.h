#ifndef DURATION_COUNTER_H
#define DURATION_COUNTER_H

#include <chrono>

using timePoint_t = std::chrono::high_resolution_clock::time_point;

class DurationCounter
{
public:

  double measure(void(*algorithm)(int), int numOfInputData);

private:

  static const int numOfRepetitions = 5;

  timePoint_t getStartTime();
  timePoint_t getEndTime();
  double findMean(const double array[], const int count);
};

#endif