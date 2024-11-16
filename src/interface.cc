#include "interface.h"

namespace s21 {
void Interface::Start() {
  while (true) {
    DisplayMenu();
    switch (Button()) {
      case 0:
        exit(0);
      case 1:
        LoadGraphFromFile();
        break;
      case 2:
        BreadthFirstSearch();
        break;
      case 3:
        DepthFirstSearch();
        break;
      case 4:
        GetShortestPathBetweenVertices();
        break;
      case 5:
        GetShortestPathsBetweenAllVertices();
        break;
      case 6:
        GetLeastSpanningTree();
        break;
      case 7:
        SolveTravelingSalesmanProblem();
        break;
      case 8:
        ExportGraphToDot();
        break;
    }
    std::cin.get();
    std::cin.get();
    system("clear");
  }
}

void Interface::DisplayMenu() {
  std::cout << CMD_GREEN
            << "╔══╗╔══╗╔╗  ╔╗╔═══╗╔╗  ╔═══╗   ╔╗ "
               "╔╗╔══╗╔╗╔╗╔══╗╔═══╗╔══╗╔════╗╔══╗╔═══╗      "
            << CMD_RED << "*\n"
            << CMD_GREEN
      "║╔═╝╚╗╔╝║║  ║║║╔═╗║║║  ║╔══╝   "
      "║╚═╝║║╔╗║║║║║╚╗╔╝║╔══╝║╔╗║╚═╗╔═╝║╔╗║║╔═╗║      ^ \n"
      "║╚═╗ ║║ ║╚╗╔╝║║╚═╝║║║  ║╚══╗   ║╔╗ ║║╚╝║║║║║ ║║ ║║╔═╗║╚╝║  ║║  "
      "║║║║║╚═╝║     /|\\ \n"
      "╚═╗║ ║║ ║╔╗╔╗║║╔══╝║║  ║╔══╝   ║║╚╗║║╔╗║║╚╝║ ║║ ║║╚╗║║╔╗║  ║║  "
      "║║║║║╔╗╔╝    //|\\\\ \n"
      "╔═╝║╔╝╚╗║║╚╝║║║║   ║╚═╗║╚══╗   ║║ ║║║║║║╚╗╔╝╔╝╚╗║╚═╝║║║║║  ║║  "
      "║╚╝║║║║║    ///|\\\\\\ \n"
      "╚══╝╚══╝╚╝  ╚╝╚╝   ╚══╝╚═══╝   ╚╝ ╚╝╚╝╚╝ ╚╝ ╚══╝╚═══╝╚╝╚╝  ╚╝  "
      "╚══╝╚╝╚╝      ]|[ \n"
            << CMD_RESET << std::endl;
  std::cout << CMD_BLUE << "      Авторы: almetate и nohoteth" << std::endl;
  std::cout << "  для выбора необходимого действия необходимо ввести цифру в "
               "МЕНЮ и следовать инструкции в консоли"
            << CMD_RESET << std::endl;
  std::cout << "" << std::endl;
  std::cout << CMD_GREEN << "_______МЕНЮ________" << CMD_RESET << std::endl;
  std::cout << "" << std::endl;
  std::cout << "    1. Загрузка исходного графа из файла." << std::endl;
  std::cout
      << "    2. Обход графа в ширину с выводом результата обхода в консоль."
      << std::endl;
  std::cout
      << "    3. Обход графа в глубину с выводом результата обхода в консоль."
      << std::endl;
  std::cout
      << "    4. Поиск кратчайшего пути между произвольными двумя вершинами "
         "с выводом результата в консоль."
      << std::endl;
  std::cout
      << "    5. Поиск кратчайших путей между всеми парами вершин в графе с "
         "выводом результирующей матрицы в консоль."
      << std::endl;
  std::cout << "    6. Поиск минимального остовного дерева в графе с выводом "
               "результирующей матрицы смежности в консоль."
            << std::endl;
  std::cout << "    7. Решение задачи комивояжера с выводом результирующего "
               "маршрута и его длины в консоль."
            << std::endl;
  std::cout << "    8. Сохранение графа в формате .dot" << std::endl;
  std::cout << "    0. Выход." << std::endl << std::endl;
}

int Interface::Button() {
  std::cout << CMD_GREEN << "Введите номер меню: " << CMD_RESET;
  int button;
  std::cin >> button;
  return button;
}

void Interface::LoadGraphFromFile() {
  std::cout << "Введите относительный путь к файлу (например - "
               "'graph_files/matrix_5.txt'): ";
  std::string filename;
  std::cin >> filename;
  if (graph_.LoadGraphFromFile(filename)) {
    std::cout << CMD_RED << " Файл несуществует или некорректный" << CMD_RESET
              << std::endl;
  } else {
    std::cout << CMD_GREEN << "Файл загружен" << CMD_RESET << std::endl;
  }
}

void Interface::ExportGraphToDot() {
  if (graph_.GetSize() == 0) {
    std::cout << CMD_RED << " Граф не загружен" << CMD_RESET << std::endl;
  } else {
    std::cout << "Введите название куда хотите сохранить файл (например - "
                 "'graph_files/matrix.dot'): ";
    std::string filename;
    std::cin >> filename;
    graph_.ExportGraphToDot(filename);
  }
}

void Interface::DepthFirstSearch() {
  s21::GraphAlgorithms ga1;
  if (graph_.GetSize() == 0) {
    std::cout << CMD_RED << " Граф не загружен" << CMD_RESET << std::endl;
  } else {
    int vertex1 = 0;

    std::cout << "Введите первую вершину от 1 до " << graph_.GetSize()
              << " и нажмите 'ENTER: ";
    std::cin >> vertex1;
    if (vertex1 > 0 && vertex1 < graph_.GetSize() + 1) {
      std::vector<int> vert = ga1.DepthFirstSearch(graph_, vertex1 - 1);
      std::cout << "Визиты: " << std::endl;
      for (size_t i = 0; i < vert.size(); ++i) {
        std::cout << std::setw(4) << vert[i] << " ";
      }
      std::cout << std::endl;
    } else {
      std::cout << "Такой вершины не существует" << std::endl;
    }
  }
}

void Interface::BreadthFirstSearch() {
  s21::GraphAlgorithms ga1;
  if (graph_.GetSize() == 0) {
    std::cout << CMD_RED << " Граф не загружен" << CMD_RESET << std::endl;
  } else {
    int vertex1 = 0;

    std::cout << "Введите первую вершину от 1 до " << graph_.GetSize()
              << " и нажмите 'ENTER: ";
    std::cin >> vertex1;
    if (vertex1 > 0 && vertex1 < graph_.GetSize() + 1) {
      std::vector<int> vert = ga1.BreadthFirstSearch(graph_, vertex1 - 1);
      std::cout << "Визиты: " << std::endl;
      for (size_t i = 0; i < vert.size(); ++i) {
        std::cout << std::setw(4) << vert[i] << " ";
      }
      std::cout << std::endl;
    } else {
      std::cout << "Такой вершины не существует" << std::endl;
    }
  }
}

void Interface::GetShortestPathBetweenVertices() {
  int vertex1, vertex2;
  std::cout << "Введите первую вершину и нажмите 'ENTER: ";
  std::cin >> vertex1;
  std::cout << "Введите втроую вершину и нажмите 'ENTER: ";
  std::cin >> vertex2;
  std::cout << "Наименьшее растояние между вершинами: "
            << graph_algorithms_.GetShortestPathBetweenVertices(graph_, vertex1,
                                                                vertex2);
}

void Interface::GetShortestPathsBetweenAllVertices() {
  std::vector<std::vector<int>> result =
      graph_algorithms_.GetShortestPathsBetweenAllVertices(graph_);
  PrintMatrix(result);
}
void Interface::PrintMatrix(std::vector<std::vector<int>> matrix) {
  for (int i = 0; i < (int)matrix.size(); ++i) {
    for (int j = 0; j < (int)matrix[i].size(); ++j) {
      std::cout << std::setw(4) << matrix[i][j] << " ";
    }
    std::cout << std::endl;
  }
}

void Interface::GetLeastSpanningTree() {
  std::vector<std::vector<int>> matrix = graph_.GetMatrix();
  int error = 0;
  for (int i = 0; i < graph_.GetSize(); ++i) {
    for (int j = 0; j < graph_.GetSize(); ++j) {
      if (matrix[i][j] != matrix[j][i]) {
        error = 1;
        break;
      }
    }
  }
  if (error == 1) {
    std::cout << CMD_RED << "Некорректный граф." << CMD_RESET << std::endl;
    std::cout << CMD_RED << "необходим взвешенный неориентированный граф."
              << CMD_RESET << std::endl;
    std::cout << CMD_RED << "Загрузите другой граф." << CMD_RESET << std::endl;
  } else {
    std::vector<std::vector<int>> result =
        graph_algorithms_.GetLeastSpanningTree(graph_);
    PrintMatrix(result);
  }
}

void Interface::SolveTravelingSalesmanProblem() {
  TsmResult res_struct;
  res_struct = graph_algorithms_.SolveTravelingSalesmanProblem(graph_);

  if (res_struct.distance == INT_MAX) {
    std::cout << CMD_RED << "Данный граф не может быть пройден" << CMD_RESET
              << std::endl;
  } else {
    std::cout << "Длина маршрута: " << res_struct.distance << std::endl;
    std::cout << "Массив с искомым маршрутом: ";

    for (unsigned i{}; i < res_struct.vertices.size(); ++i) {
      std::cout << res_struct.vertices[i] + 1;
      if (res_struct.vertices.size() - 1 != i) {
        std::cout << "->";
      }
    }
  }

  std::cout << std::endl;
}

}  // namespace s21