#ifndef A2_SIMPLENAVIGATOR_SRC_S21_GRAPH_ALGORITHMS_H_
#define A2_SIMPLENAVIGATOR_SRC_S21_GRAPH_ALGORITHMS_H_

#include <climits>
#include <iostream>
#include <vector>

#include "./container/s21_queue.h"
#include "./container/s21_stack.h"
// #include "ants/ants_colony.h"
#include "s21_graph.h"

#define CMD_RESET "\x1b[0m"
#define CMD_RED "\x1b[31;1m"
#define CMD_GREEN "\x1b[32;1m"
#define CMD_BLUE "\033[34m"

namespace s21 {
struct TsmResult {
  // TsmResult() : distance(0) {};
  std::vector<int>
      vertices;  // массив с искомым маршрутом (с порядком обхода вершин).
  double distance;  // длина этого маршрута
};

class GraphAlgorithms {
 private:
  /* data */
 public:
  GraphAlgorithms(/* args */) = default;
  ~GraphAlgorithms() = default;
  std::vector<int> DepthFirstSearch(Graph &graph, int start_vertex);
  std::vector<int> BreadthFirstSearch(Graph &graph, int start_vertex);
  int GetShortestPathBetweenVertices(Graph &graph, int vertex1, int vertex2);
  std::vector<std::vector<int>> GetShortestPathsBetweenAllVertices(
      Graph &graph);
  std::vector<std::vector<int>> GetLeastSpanningTree(Graph &graph);
  TsmResult SolveTravelingSalesmanProblem(Graph &graph);
};
}  // namespace s21
#endif  // A2_SIMPLENAVIGATOR_SRC_S21_GRAPH_ALGORITHMS_H_
