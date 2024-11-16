CC = g++ -std=c++17 -Wall -Werror -Wextra -Wpedantic
SOURCE_GRAPH = s21_graph.cc
OBJECT_GRAPH = $(SOURCE_GRAPH:.cc=.o)

SOURCE_ALGORITHM = algorithm_dijkstra.cc algorithm_floyd_warshall.cc s21_graph_algorithms.cc algorithm_prima.cc ants/*.cc s21_graph.cc algorithm_ants.cc

OS = $(shell uname)

ifeq ($(OS), Linux)
	TEST_FLAGS =-lgtest -lm -lpthread -lrt
else
	TEST_FLAGS =-lgtest -lgcov --coverage
endif

all: clean main

s21_graph.a: clean $(SOURCE_GRAPH)
	$(CC) -c $(SOURCE_GRAPH)
	@ar rcs s21_graph.a $(OBJECT_GRAPH)
	@rm -rf *.o

s21_graph_algorithms.a: clean $(SOURCE_ALGORITHM)
	$(CC) -c $(SOURCE_ALGORITHM)
	@ar rcs s21_graph_algorithms.a *.o
	@rm -rf *.o

main: clean s21_graph.a s21_graph_algorithms.a
	$(CC) main.cc interface.cc s21_graph.a s21_graph_algorithms.a -o main
	./main

test: clean test.cc s21_graph.a s21_graph_algorithms.a
	$(CC) test.cc s21_graph.a s21_graph_algorithms.a $(TEST_FLAGS) -o test
	./test

clang:
	clang-format -style=Google -n *.cc  *.h

cl:
	clang-format -style=Google -i *.cc  *.h

leaks_test: clean test
ifeq ($(OS), Darwin)
	leaks --atExit -- test
else
	valgrind --leak-check=full --show-reachable=yes --show-leak-kinds=all --track-origins=yes --log-file=RESULT_VALGRIND.txt ./test
endif

clean:
	@rm -rf main \
			test \
			*.a \
			*.o \
			*.gcda \
			*.gcno \
			RESULT_VALGRIND.txt
			
