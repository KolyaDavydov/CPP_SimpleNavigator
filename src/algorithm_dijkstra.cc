#include <climits>
#include <limits>
#include <queue>
#include <set>

#include "s21_graph_algorithms.h"

namespace s21 {
int GraphAlgorithms::GetShortestPathBetweenVertices(Graph &graph, int vertex1,
                                                    int vertex2) {
  if (vertex1 > graph.GetSize() || vertex1 < 1 || vertex2 > graph.GetSize() ||
      vertex2 < 1) {
    return -1;
  }
  std::vector<std::vector<int>> matrix = graph.GetMatrix();

  std::vector<int> path(graph.GetSize() + 1);
  std::vector<bool> visited_vertex(graph.GetSize());
  std::vector<int> weights(graph.GetSize(), INT_MAX);

  vertex1 -= 1;
  vertex2 -= 1;

  std::queue<int> neighbors;
  weights[vertex1] = 0;
  path[0] = vertex1;
  visited_vertex[vertex1] = true;
  neighbors.push(vertex1);
  int v = 1;

  while (!neighbors.empty()) {
    int current = neighbors.front();
    int next = -1, min = INT_MAX;
    neighbors.pop();
    for (int i = 0; i < graph.GetSize(); ++i) {
      if (weights[i] > matrix[current][i] + weights[current] &&
          !visited_vertex[i] && matrix[current][i] != 0) {
        weights[i] = matrix[current][i] + weights[current];
        if (min > weights[i]) {
          min = weights[i];
          next = i;
        }
      } else if (weights[i] < matrix[current][i] + weights[current] &&
                 matrix[current][i] != 0 && !visited_vertex[i]) {
        min = weights[i];
        next = i;
      }
    }
    if (next != -1) {
      neighbors.push(next);
      path[v] = next;
      visited_vertex[next] = true;
      ++v;
    }
  }
  return weights[vertex2];
}
}  // namespace s21