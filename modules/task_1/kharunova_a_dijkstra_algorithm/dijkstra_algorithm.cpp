// Copyright 2022 Kharunova Alina
#include <vector>
#include <random>
#include <algorithm>
#include <iostream>
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
    int isConnected = 0;
    int startCol = 0;
    int destination = 0;
    for (int row = 0; row < num_of_vertex; row++) {
      for (int col = startCol; col < num_of_vertex; col++) {
        isConnected = dev() % 2;
        if (isConnected && row != col) {
          destination = dev() % max_destination;
          matrix_of_connection[row][col] = destination;
          matrix_of_connection[col][row] = destination;
        }
      }
      startCol++;
    }
    return matrix_of_connection;
}

void start_algorithm(int start_vertex, int num_of_vertex, int max_destination) {
  if (start_vertex < 0 || start_vertex >= num_of_vertex) {
    throw("Wrong value of start vertex");
  }
  if (num_of_vertex <= 0) {
    throw("Wrong number of vertexes");
  }
  if (max_destination <= 0) {
    throw("Wrong value of maximum destination");
  }

  std::vector<int> min_destinations(num_of_vertex, 1000);
  std::vector<int> passed_vertexes(num_of_vertex, 1);
  int temp, min_index, min_dest;
  std::vector<std::vector<int>> matrix_of_connections =
      create_random_graph(num_of_vertex, max_destination);

  min_destinations[start_vertex] = 0;

  do {
    min_index = 10000;
    min_dest = 10000;
    for (int i = 0; i < num_of_vertex; i++) {
      if ((passed_vertexes[i] == 1) &&
          (min_destinations[i] < min_dest)) {
        min_dest = min_destinations[i];
        min_index = i;
      }
    }
    if (min_index != 10000) {
      for (int i = 0; i < num_of_vertex; i++) {
        if (matrix_of_connections[min_index][i] > 0) {
          temp = min_dest + matrix_of_connections[min_index][i];
          if (temp < min_destinations[i]) {
            min_destinations[i] = temp;
          }
        }
      }
      passed_vertexes[min_index] = 0;
    }
  } while (min_index < 10000);

  std::vector<int> shortest_path;
  int end_vertex = num_of_vertex - 1;
  shortest_path.push_back(end_vertex);
  int weight_of_end_vertex = min_destinations[end_vertex];

  while (end_vertex != 0) {
    for (int i = 0; i < num_of_vertex; i++) {
      if (matrix_of_connections[i][end_vertex] != 0) {
        int weight_of_last_vertex =
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
