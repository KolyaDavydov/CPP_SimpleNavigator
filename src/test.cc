#include <gtest/gtest.h>

#include <stdexcept>
#include <vector>

#include "s21_graph.h"
#include "s21_graph_algorithms.h"

TEST(SimpleNavigator, load) {
  s21::Graph graph;
  graph.LoadGraphFromFile("graph_files/matrix_52.txt");
  EXPECT_EQ((int)graph.LoadGraphFromFile("graph_files/matrix_52.txt"), 0);
  EXPECT_EQ((int)graph.LoadGraphFromFile("graph_files/matrix_"), 1);
}

TEST(SimpleNavigator, size) {
  s21::Graph graph;
  EXPECT_EQ(graph.GetSize(), 0);
  graph.LoadGraphFromFile("graph_files/matrix_5.txt");
  EXPECT_EQ(graph.GetSize(), 5);
}

TEST(SimpleNavigator, save) {
  s21::Graph graph;
  graph.LoadGraphFromFile("graph_files/matrix_52.txt");
  try {
    graph.ExportGraphToDot("/qqq");
    FAIL() << "Expected std::runtime_error";
  } catch (std::runtime_error const& err) {
    EXPECT_EQ(err.what(), std::string("Unable to write file"));
  } catch (...) {
    FAIL() << "Expected std::out_of_range";
  }
}

TEST(SimpleNavigator, BFS) {
  s21::Graph graph;
  s21::GraphAlgorithms graph_algorithms;
  std::vector<int> route = {5, 4, 1, 2, 3};
  graph.LoadGraphFromFile("graph_files/matrix_52.txt");
  EXPECT_EQ(graph_algorithms.BreadthFirstSearch(graph, 4), route);
}

TEST(SimpleNavigator, DFS) {
  s21::Graph graph;
  s21::GraphAlgorithms graph_algorithms;
  std::vector<int> route = {1, 4, 5, 2, 3};
  graph.LoadGraphFromFile("graph_files/matrix_52.txt");
  EXPECT_EQ(graph_algorithms.DepthFirstSearch(graph, 0), route);
}

TEST(SimpleNavigator, GetShortestPathsBetweenAllVertices) {
  s21::Graph graph;
  s21::GraphAlgorithms graph_algorithms;
  std::vector<std::vector<int>> dist_matrix = {{0, 3, 9, 4, 8},
                                               {2, 0, 6, 6, 5},
                                               {13, 16, 0, 13, 6},
                                               {7, 5, 6, 0, 4},
                                               {7, 10, 13, 7, 0}};
  graph.LoadGraphFromFile("graph_files/matrix_5.txt");
  EXPECT_EQ(graph_algorithms.GetShortestPathsBetweenAllVertices(graph),
            dist_matrix);
}

TEST(SimpleNavigator, GetShortestPathBetweenVertices) {
  s21::Graph graph;
  s21::GraphAlgorithms graph_algorithms;
  std::vector<int> route = {5, 4, 1, 2, 3};
  graph.LoadGraphFromFile("graph_files/matrix_52.txt");
  EXPECT_EQ(graph_algorithms.GetShortestPathBetweenVertices(graph, 1, 5), 2);
}

TEST(SimpleNavigator, GetLeastSpanningTree) {
  s21::Graph graph;
  s21::GraphAlgorithms graph_algorithms;
  std::vector<std::vector<int>> span_tree = {{0, 1, 0, 1, 0},
                                             {1, 0, 1, 0, 0},
                                             {0, 1, 0, 0, 0},
                                             {1, 0, 0, 0, 1},
                                             {0, 0, 0, 1, 0}};
  graph.LoadGraphFromFile("graph_files/matrix_52.txt");
  EXPECT_EQ(graph_algorithms.GetLeastSpanningTree(graph), span_tree);
}

int main(int argc, char** argv) {
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}