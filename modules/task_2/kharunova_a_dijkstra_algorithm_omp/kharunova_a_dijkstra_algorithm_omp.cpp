// Copyright 2022 Kharunova Alina
#include <omp.h>
#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
#include "../../../modules/task_1/kharunova_a_dijkstra_algorithm/dijkstra_algorithm.h"

std::vector<std::vector<int>> create_random_graph(int num_of_vertex,
                                                  int max_destination) {
  if (num_of_vertex <= 0) {
    throw "Wrong number of vertexes";
  }
  std::vector<std::vector<int>> matrix_of_connection(
      num_of_vertex, std::vector<int>(num_of_vertex, 0));
  std::random_device dev;
  std::mt19937 gen(dev());
  int isConnected = 0, startCol = 0, destination = 0, row, col;
#pragma omp parallel shared(matrix_of_connection) private(row, col)
  {
#pragma omp for
    for (row = 0; row < num_of_vertex; row++) {
      for (col = startCol; col < num_of_vertex; col++) {
        isConnected = dev() % 2;
        if (isConnected && row != col) {
          destination = dev() % max_destination;
          matrix_of_connection[row][col] = destination;
          matrix_of_connection[col][row] = destination;
        }
      }
      startCol++;
    }
  }
  return matrix_of_connection;
}

void start_parallel_algorithm(int start_vertex, int num_of_vertex,
                              int max_destination) {
  if (start_vertex < 0 || start_vertex >= num_of_vertex) {
    throw("Wrong value of start vertex");
  }
  if (num_of_vertex <= 0) {
    throw("Wrong number of vertexes");
  }
  if (max_destination <= 0) {
    throw("Wrong value of maximum destination");
  }

  std::vector<int> min_destinations(num_of_vertex, 10000);
  std::vector<int> passed_vertexes(num_of_vertex, 0);
  int temp, min_index, min_dest, i, j, k, min_index2 = 0;
  std::vector<std::vector<int>> matrix_of_connections =
      create_random_graph(num_of_vertex, max_destination);

  min_destinations[start_vertex] = 0;

  for (int i = 0; i < num_of_vertex; i++) {
    int min_weight = 10000;
     int min_weight2 = 10000;
#pragma omp parallel shared( \
    min_destinations, passed_vertexes) \
    firstprivate(min_weight, min_index, j) {
#pragma omp for
      for (j = 0; j < num_of_vertex; j++) {
        if (!passed_vertexes[j] && min_destinations[j] <= min_weight) {
          min_weight = min_destinations[j];
          min_index = j;
        }
      }
      if (min_weight < min_weight2) {
        min_weight2 = min_weight;
        min_index2 = min_index;
      }
    }
    passed_vertexes[min_index2] = 1;
#pragma omp parallel shared(min_destinations, matrix_of_connections, \
                            passed_vertexes) \
    firstprivate(k) {
#pragma omp for
      for (k = 0; k < num_of_vertex; k++) {
        if (!passed_vertexes[k] && min_destinations[min_index2] != 10000 &&
            matrix_of_connections[min_index2][k] &&
            min_destinations[min_index2] +
                    matrix_of_connections[min_index2][k] <
                min_destinations[k]) {
          min_destinations[k] = min_destinations[min_index2] +
                                matrix_of_connections[min_index2][k];
        }
      }
    }
  }

  std::vector<int> shortest_path;
  int end_vertex = num_of_vertex - 1;
  shortest_path.push_back(end_vertex);
  int weight_of_end_vertex = min_destinations[end_vertex],
      weight_of_last_vertex;

  while (end_vertex != 0) {
      for (int i = 0; i < num_of_vertex; i++) {
        if (matrix_of_connections[i][end_vertex] != 0) {
          weight_of_last_vertex =
              weight_of_end_vertex - matrix_of_connections[i][end_vertex];
          if (weight_of_last_vertex == min_destinations[i]) {
            weight_of_end_vertex = weight_of_last_vertex;
            end_vertex = i;
            shortest_path.push_back(i);
          }
        }
      }
    }
}
