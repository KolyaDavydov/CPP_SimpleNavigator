#include "ants_colony.h"
namespace s21 {
AntsColony::AntsColony(Graph& graph) : graph_(graph) {
  allVertex_ = graph.GetSize();
  pheromons_ = std::vector<std::vector<double>>(
      allVertex_, std::vector<double>(allVertex_, 0.2));
  averageRouteLen_ = 0;
  for (int i = 0; i < allVertex_; i++) {
    for (int j = 0; j < allVertex_; j++) {
      averageRouteLen_ += graph.GetMatrix()[i][j];
    }
  }
  averageRouteLen_ /= allVertex_ * allVertex_ - allVertex_;
}

/**
 * @brief Генерация муравьев в случайном порядке для каждой вершины графа
 * @param allAnts количество вершин в графе
*/
void AntsColony::GenerateAnts(int allAnts) {
  ants_.clear();
  for (int i = 0; i < allAnts; i++) {
    ants_.push_back(Ant(Randomizer(allVertex_)));
  }
}

void AntsColony::FindPaths() {
  for (auto& ant : ants_) {
    ant.FindPath(graph_, pheromons_);
  }
}

int AntsColony::CalculatePathCost(std::vector<int>& path) {
  int res{};
  for (int i = 1; i < static_cast<int>(path.size()); i++) {
    res += graph_.GetMatrix()[path[i - 1]][path[i]];
  }
  return res;
}

void AntsColony::UpdateFeromon() {
  for (Ant& ant : ants_) {
    std::vector<int>& path = ant.GetPath();
    int cost = CalculatePathCost(path);
    double deltaPheromone = static_cast<double>(averageRouteLen_) / cost;
    for (int i = 1; i < static_cast<int>(path.size()); i++) {
      pheromons_[path[i - 1]][path[i]] *= pheromonRemains_;
      pheromons_[path[i - 1]][path[i]] += deltaPheromone;
    }
  }
  for (int i = 0; i < (int)pheromons_.size(); i++) {
    for (int j = 0; j < (int)pheromons_.size(); j++) {
      pheromons_[i][j] *= pheromonRemains_;
    }
  }
}

void AntsColony::UpdateResult(TsmResult& res) {
  for (auto& ant : ants_) {
    std::vector<int>& path = ant.GetPath();
    int cost = CalculatePathCost(path);
    if (cost < res.distance && cost) {
      res.distance = cost;
      res.vertices = path;
    }
  }
}
}