#include "s21_graph_algorithms.h"

namespace s21 {
// GraphAlgorithms::GraphAlgorithms(/* args */) {}

// GraphAlgorithms::~GraphAlgorithms() {}

/// @brief Алгоритм поиска в глубину
/// @param graph граф по которому ведется поиск
/// @param start_vertex начальная вершина для поиска
/// @return вектор с номерами вершин в порядке их обхода
std::vector<int> GraphAlgorithms::DepthFirstSearch(Graph &graph,
                                                   int start_vertex) {
  Stack<int> st;
  int v = start_vertex;
  std::vector<bool> visited;
  visited.resize(graph.GetSize(), false);
  std::vector<int> visits;
  visited[v] = true;
  visits.push_back(v + 1);
  st.push(v);
  while (!st.empty()) {
    v = st.top();
    st.pop();
    if (!visited[v]) {
      visits.push_back(v + 1);
      visited[v] = true;
    }
    for (int adjacent = 0; adjacent < graph.GetSize(); adjacent++) {
      if (graph.GetMatrixElement(v, adjacent) && !visited[adjacent]) {
        st.push(adjacent);
      }
    }
  }
  return visits;
}

/// @brief Алгоритм поиска в ширину
/// @param graph граф по которому ведется поиск
/// @param start_vertex начальная вершина для поиска
/// @return вектор с номерами вершин в порядке их обхода
std::vector<int> GraphAlgorithms::BreadthFirstSearch(Graph &graph,
                                                     int start_vertex) {
  std::vector<bool> visited;
  std::vector<int> visits;
  visited.resize(graph.GetSize(), false);

  List<int> queue;

  visited[start_vertex] = true;
  queue.push_back(start_vertex);

  while (!queue.empty()) {
    start_vertex = queue.front();
    visits.push_back(start_vertex + 1);
    queue.pop_front();

    for (int adjacent = 0; adjacent < graph.GetSize(); adjacent++) {
      if (graph.GetMatrixElement(start_vertex, adjacent) &&
          !visited[adjacent]) {
        visited[adjacent] = true;
        queue.push_back(adjacent);
      }
    }
  }
  return visits;
}

// int GraphAlgorithms::GetShortestPathBetweenVertices(Graph &graph, int
// vertex1,
//                                                     int vertex2) {}

// std::vector<int> GraphAlgorithms::GetShortestPathsBetweenAllVertices(
//     Graph &graph) {}

// std::vector<int> GraphAlgorithms::GetLeastSpanningTree(Graph &graph) {}

// TsmResult GraphAlgorithms::SolveTravelingSalesmanProblem(Graph &graph) {
//   int antsNumber = graph.GetMatrix().size();
//   int CountWithoutUpgrade = 30, maxCount = 50;

//   AntsColony colony(graph);
//   TsmResult prevRes;
//   TsmResult res;
//   prevRes.distance = INFINITY;
//   res.distance = INFINITY;

//   while (CountWithoutUpgrade) {
//     colony.GenerateAnts(antsNumber);
//     colony.FindPaths();
//     colony.UpdateFeromon();
//     colony.UpdateResult(res);

//     if (res.distance == prevRes.distance) {
//       CountWithoutUpgrade--;
//     } else {
//       prevRes = res;
//       CountWithoutUpgrade = maxCount;
//     }
//   }
//   return res;
// }
}  // namespace s21