#ifndef A2_SIMPLENAVIGATOR_SRC_INTERFACE_H_
#define A2_SIMPLENAVIGATOR_SRC_INTERFACE_H_

#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

#include "s21_graph.h"
#include "s21_graph_algorithms.h"

namespace s21 {
class Interface {
 public:
  /**
   * @brief вызов консольного интерфейса с выводом меню
   */
  void Start();

 private:
  void DisplayMenu();
  int Button();
  void LoadGraphFromFile();
  void ExportGraphToDot();

 private:
  void DepthFirstSearch();
  void BreadthFirstSearch();
  void GetShortestPathBetweenVertices();
  void GetShortestPathsBetweenAllVertices();
  void PrintMatrix(std::vector<std::vector<int>> matrix);
  void GetLeastSpanningTree();
  void SolveTravelingSalesmanProblem();

 private:
  Graph graph_;
  GraphAlgorithms graph_algorithms_;
};
}  // namespace s21

#endif  // A2_SIMPLENAVIGATOR_SRC_INTERFACE_H_