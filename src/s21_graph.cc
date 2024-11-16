#include "s21_graph.h"

namespace s21 {
bool Graph::LoadGraphFromFile(std::string filename) {
  Clear();

  std::ifstream file(filename);
  if (file.is_open() == false) {
    is_error_ = true;
  } else {
    std::string line;
    getline(file, line);
    SetSize(line);
    while (getline(file, line)) {
      ParseVector(line);
    }
  }
  return is_error_;
}

void Graph::SetSize(std::string line) { size_ = stoi(line); }

void Graph::ParseVector(std::string line) {
  std::vector<int> vector;
  size_t pos{};
  while (true) {
    vector.push_back(stoi(line, &pos));
    line.erase(0, pos);
    if (line.size() < 2) break;
  }
  if ((int)vector.size() != size_) {
    is_error_ = true;
    return;
  }
  matrix_.push_back(vector);
}

void Graph::Clear() {
  matrix_.clear();
  size_ = 0;
  is_error_ = false;
}

void Graph::ExportGraphToDot(std::string filename) {
  std::string file_path{filename};
  std::fstream file;
  file.open(file_path, std::fstream::out);
  if (!file.is_open()) {
    throw std::runtime_error("Unable to write file");
  }
  std::string dot_separator;
  std::string dot_graph_type;

  dot_separator = " -- ";
  dot_graph_type = "graph ";

  file << dot_graph_type << "dotfile"
       << " {" << std::endl;
  for (int i{}; i < size_; ++i) {
    for (int j{}; j < size_; ++j) {
      if (matrix_[i][j] == 1) {
        file << "\t" << i + 1 << dot_separator << j + 1 << ";" << std::endl;
      } else if (matrix_[i][j] > 1) {
        file << "\t" << i + 1 << dot_separator << j + 1
             << " [label=" << matrix_[i][j] << "];" << std::endl;
      }
    }
  }

  file << "}\n";
}
}  // namespace s21