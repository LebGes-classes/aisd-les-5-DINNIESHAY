#ifndef MIN_BINARY_HEAP
#define MIN_BINARY_HEAP

#include <vector>

template <typename T>
class MinBinaryHeap
{
public:

  //Конструктор без параметров (по умолчанию)
  MinBinaryHeap() = default;

  //Деструктор (по умолчанию)
  ~MinBinaryHeap() = default;

  //Добавление нового элемента в кучу
  void push(T element);
  //Изъятие корневого (минимального) элемента из кучи
  T pop();
  //Получение корневого (минимального) элемента кучи
  T getMin();
  //Получение размера кучи
  size_t getSize();

private:

  //Элементы кучи хранятся в массиве
  std::vector<T> array;

  //Сдвиг элемента вверх по порядку для сохранения свойства минимальной двоичной кучи
  void shiftUp(size_t index);
  //Сдвиг элемента вниз по порядку для сохранения свойства минимальной двоичной кучи
  void shiftDown(size_t index);
  //Получение индекса родителя
  size_t getParentIndex(size_t index);
  //Получение индекса левого ребенка
  size_t getLeftChildIndex(size_t index);
  //Получение индекса правого ребенка
  size_t getRightChildIndex(size_t index);
  //Получение индекса последнего добавленного элемента
  size_t getLastIndex();
};

template <typename T>
void MinBinaryHeap<T>::push(T element)
{
  //Добавление элемента в массив
  array.push_back(element);
  size_t newElementIndex = getLastIndex();
  //Балансировка сверху
  shiftUp(newElementIndex);
}

template <typename T>
T MinBinaryHeap<T>::pop()
{
  if (array.empty())
  {
    throw std::logic_error("Queue is empty.\n");
  }

  //Корневой элемент будет удаляться
  T elementToPop = array[0];

  //На место корневого элемента ставим последний добавленный элемент
  array[0] = array[getLastIndex()];
  array.pop_back();

  //Балансировка снизу
  shiftDown(0);

  return elementToPop;
}

template <typename T>
T MinBinaryHeap<T>::getMin()
{
  if (array.empty())
  {
    throw std::logic_error("Error: Heap is empty.\n");
  }

  T minElement = array[0];

  return minElement;
}

template <typename T>
void MinBinaryHeap<T>::shiftUp(size_t index)
{
  //Пока не достигли корневого элемента и текущий элемент меньше своего родителя, идём по куче вверх
  while (index != 0 && array[index] < array[getParentIndex(index)])
  {
    //Меняем местами текущий элемент и его родителя
    std::swap(array[index], array[getParentIndex(index)]);
    index = getParentIndex(index);
  }
}

template <typename T>
size_t MinBinaryHeap<T>::getSize()
{
  return array.size();
}

template <typename T>
void MinBinaryHeap<T>::shiftDown(size_t index)
{
  //Пока существует левый ребенок, идём по куче вниз
  while (getLeftChildIndex(index) < array.size())
  {
    //Получаем наименьшего ребенка из двух
    size_t minChildIndex = getLeftChildIndex(index);
    if (minChildIndex + 1 < array.size() && array[minChildIndex + 1] < array[minChildIndex])
    {
      minChildIndex++;
    }

    //Если текущий элемент не превышает наименьшего ребенка, балансировка завершается
    if (array[index] <= array[minChildIndex])
    {
      break;
    }
    else
    {
      //Иначе - меняем местами текущий элемент с его наименьшим ребенком
      std::swap(array[index], array[minChildIndex]);
      index = minChildIndex;
    }
  }
}

template <typename T>
size_t MinBinaryHeap<T>::getParentIndex(size_t index)
{
  size_t parentIndex = (index - 1) / 2;

  return parentIndex;
}

template <typename T>
size_t MinBinaryHeap<T>::getLeftChildIndex(size_t index)
{
  size_t leftChildIndex = 2 * index + 1;

  return leftChildIndex;
}

template <typename T>
size_t MinBinaryHeap<T>::getRightChildIndex(size_t index)
{
  size_t rightChildIndex = 2 * index + 2;

  return rightChildIndex;
}

template <typename T>
size_t MinBinaryHeap<T>::getLastIndex()
{
  size_t lastIndex = array.size() - 1;

  return lastIndex;
}

#endif
