#include <climits>

#include "s21_graph_algorithms.h"

namespace s21 {
std::vector<std::vector<int>>
GraphAlgorithms::GetShortestPathsBetweenAllVertices(Graph &graph) {
  int size = graph.GetSize();
  std::vector<std::vector<int>> matrix = graph.GetMatrix();

  std::vector<std::vector<int>> result_matrix(size, std::vector<int>(size));

  for (int i = 0; i < size; ++i) {
    for (int j = 0; j < size; ++j) {
      if (i == j) {
        result_matrix[i][j] = 0;
      } else if (matrix[i][j] > 0) {
        result_matrix[i][j] = matrix[i][j];
      } else if (matrix[i][j] == 0) {
        result_matrix[i][j] = INT_MAX;
      }
    }
  }

  for (int k = 0; k < size; ++k) {
    for (int i = 0; i < size; ++i) {
      for (int j = 0; j < size; ++j) {
        if (result_matrix[i][k] < INT_MAX && result_matrix[k][j] < INT_MAX) {
          result_matrix[i][j] = std::min(
              result_matrix[i][j], result_matrix[i][k] + result_matrix[k][j]);
        }
      }
    }
  }
  return result_matrix;
}
}  // namespace s21