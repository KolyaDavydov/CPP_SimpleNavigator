#include "ants/ants_colony.h"
#include "s21_graph_algorithms.h"

namespace s21 {
/**
 * @brief Возвращает один из самых выходных путей найденных по муравьиному
 * алгоритму
 * @param graph граф в виде матрицы смежности
 * @return путь и размер пути в виде струткуры
 */
TsmResult GraphAlgorithms::SolveTravelingSalesmanProblem(Graph& graph) {
  int antsNumber = graph.GetSize();
  int countWithoutUpgrade = 30, maxCount = 50;

  AntsColony colony(graph);
  TsmResult prevRes, res;
  prevRes.distance = INT_MAX;
  res.distance = INT_MAX;

  while (countWithoutUpgrade) {
    colony.GenerateAnts(antsNumber);
    colony.FindPaths();
    colony.UpdateFeromon();
    colony.UpdateResult(res);

    if (res.distance == prevRes.distance) {
      countWithoutUpgrade--;
    } else {
      prevRes = res;
      countWithoutUpgrade = maxCount;
    }
  }
  return res;
}
}  // namespace s21