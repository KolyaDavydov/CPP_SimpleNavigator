#include <climits>

#include "s21_graph_algorithms.h"

namespace s21 {
std::vector<std::vector<int>> GraphAlgorithms::GetLeastSpanningTree(
    Graph &graph) {
  int size = graph.GetSize();
  std::vector<std::vector<int>> matrix = graph.GetMatrix();

  std::vector<bool> visited_vertex(size);

  std::vector<int> path(size, -1);

  std::vector<std::vector<int>> result_matrix(size, std::vector<int>(size));

  std::vector<int> min(size, INT_MAX);
  min[0] = 0;

  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      if (i != j && matrix[i][j] == 0) matrix[i][j] = INT_MAX;
    }
  }

  for (int i = 0; i < size; ++i) {
    int v = -1;
    for (int j = 0; j < size; ++j) {
      if (!visited_vertex[j] && (v == -1 || min[j] < min[v])) v = j;
    }
    visited_vertex[v] = true;
    if (path[v] != -1) {
      result_matrix[path[v]][v] = matrix[path[v]][v];
      result_matrix[v][path[v]] = matrix[v][path[v]];
    }
    for (int k = 0; k < size; ++k) {
      if (matrix[v][k] < min[k]) {
        min[k] = matrix[v][k];
        path[k] = v;
      }
    }
  }

  return result_matrix;
}
}  // namespace s21