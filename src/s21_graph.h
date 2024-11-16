#ifndef A2_SIMPLENAVIGATOR_SRC_S21_GRAPH_H_
#define A2_SIMPLENAVIGATOR_SRC_S21_GRAPH_H_

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

namespace s21 {
class Graph {
 public:
  Graph() : size_(0), is_error_(false){};
  ~Graph() = default;
  int operator()(int row, int column) { return matrix_[row][column]; }

  /**
   * @brief загрузка графа из файла в формате матрицы смежности
   * @param filename файла, содержащего матрицу смежности
   */
  bool LoadGraphFromFile(std::string filename);

  /**
   * @brief выгрузка графа в файл в формате dot или gv
   * Для просмотра: `vimdot [название файла]`
   * @param filename название файла куда сохранить нужно
   */
  void ExportGraphToDot(std::string filename);

  /**
   * @brief получение размера граффа
   * @return разер  графа
   */
  int GetSize() { return size_; };

  int GetMatrixElement(int col, int row) { return matrix_[col][row]; }
  /**
   * @brief получение матрицы смежности
   * @return матрица смежности
   */
  std::vector<std::vector<int>> GetMatrix() { return matrix_; };

 private:
  // размер квадратной матрицы смежности
  int size_;
  // матрица смежности
  std::vector<std::vector<int>> matrix_;
  // если файл со смежной матрицей некорректный будет true
  bool is_error_;
  std::vector<int> graph_{};

 private:
  /**
   * @brief задет размер матрицы смежности
   * @param line строка с целым числом
   */
  void SetSize(std::string line);

  /**
   * @brief парсит строку в вектор и засовывает его в матрицу смежности
   * (matrix_)
   */
  void ParseVector(std::string line);

  /**
   * @brief очистка графа
   */
  void Clear();
};
}  // namespace s21

#endif  // A2_SIMPLENAVIGATOR_SRC_S21_GRAPH_H_
