#include "funcs.h"
#include <iostream>
namespace s21 {
/**
 * @brief Проверяет есть ли переданное число в переданном векторе
 * @param vertex переданное число
 * @param vertices вктор целых чисел
 * @return если числа нет - false
*/
bool IsContain(int vertex, std::vector<int>& vertices) {
  for (int elem : vertices) {
    if (elem == vertex) return true;
  }
  return false;
}

/**
 * @brief генерирует случайное число в диапазоне от 0 до переданного занчения
 * @param dist верхний предел для генерации случайного числа
 * @return случайное число
*/
int Randomizer(size_t dist) {
  std::random_device rd;
  std::default_random_engine engine{rd()};
  std::uniform_int_distribution<int> distribution{0,
                                                  static_cast<int>(dist) - 1};
  return distribution(engine);
}
}