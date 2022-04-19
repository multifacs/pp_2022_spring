// Copyright 2022 Tyrina Anastasia
#include "./deicstra_algorithm.h"

#include <algorithm>
#include <random>
#include <vector>

std::vector<std::vector<int>> getRandomVector(const size_t count) {
  std::vector<std::vector<int>> graf(count, std::vector<int>(count));
  std::random_device dev;
  std::mt19937 gen(2);

  for (size_t i = 0; i < count; ++i) {
    graf[i][i] = 0;
    for (size_t j = i + 1; j < count; ++j) {
      graf[i][j] = gen() % 100;
      graf[j][i] = graf[i][j];
    }
  }
  return graf;
}

std::vector<int> getDeicstra(const std::vector<std::vector<int>>& graf,
                             const size_t count, const size_t top) {
  std::vector<bool> visitedTops(count);
  std::vector<int> dist(count, 10000);
  dist[top] = 0;
  int min_dist = 0;
  int min_vertex = top;

  while (min_dist < 10000) {
    size_t i = min_vertex;
    visitedTops[i] = true;
    for (size_t j = 0; j < count; ++j)
      if ((dist[i] + graf[i][j] < dist[j]) && (graf[i][j] != 0))
        dist[j] = dist[i] + graf[i][j];
    min_dist = 10000;
    for (size_t j = 0; j < count; ++j)
      if (!visitedTops[j] && dist[j] < min_dist) {
        min_dist = dist[j];
        min_vertex = j;
      }
  }

  return dist;
}

std::vector<int> getSeqDeicstra(const std::vector<std::vector<int>>& graf,
                                const size_t count) {
  size_t top = 0;
  std::vector<int> result(count * count, 0);
  for (top = 0; top < count; ++top) {
    auto tmp = getDeicstra(graf, count, top);
    for (size_t i = 0; i < count; ++i) {
      result[top * count + i] = tmp[i];
    }
  }

  return result;
}
