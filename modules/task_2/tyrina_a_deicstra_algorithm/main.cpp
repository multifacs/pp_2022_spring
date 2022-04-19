// Copyright 2022 Tyrina Anastasia
#include <gtest/gtest.h>

#include <vector>

#include "./deicstra_algorithm.h"

TEST(DEICSTRA_ALGORITHM_OMP, TEST_1) {
  const int count = 6;
  std::vector<int> result;
  std::vector<int> ref;
  std::vector<std::vector<int>> graph;

  graph = {{0, 7, 9, 0, 0, 14},  {7, 0, 10, 15, 0, 0}, {9, 10, 0, 11, 0, 2},
           {0, 15, 11, 0, 6, 0}, {0, 0, 0, 6, 0, 9},   {14, 0, 2, 0, 9, 0}};

  result = getDeicstra(graph, count, 0);
  ref = {0, 7, 9, 20, 20, 11};

  for (int i = 0; i < count; ++i) {
    ASSERT_EQ(result[i], ref[i]);
  }
}

TEST(DEICSTRA_ALGORITHM_OMP, TEST_2) {
  const int count = 6;
  std::vector<int> result;
  std::vector<int> ref;
  std::vector<std::vector<int>> graph;

  graph = {{0, 7, 9, 0, 0, 14},  {7, 0, 10, 15, 0, 0}, {9, 10, 0, 11, 0, 2},
           {0, 15, 11, 0, 6, 0}, {0, 0, 0, 6, 0, 9},   {14, 0, 2, 0, 9, 0}};

  result = getOMPDeicstra(graph, count);

  ref = {0,  7,  9,  20, 20, 11, 7,  0,  10, 15, 21, 12, 9,  10, 0, 11, 11, 2,
         20, 15, 11, 0,  6,  13, 20, 21, 11, 6,  0,  9,  11, 12, 2, 13, 9,  0};

  for (int i = 0; i < count * count; ++i) {
    ASSERT_EQ(result[i], ref[i]);
  }
}

TEST(DEICSTRA_ALGORITHM_OMP, TEST_3) {
  const int count = 6;
  std::vector<int> result;
  std::vector<int> ref;
  std::vector<std::vector<int>> graph;

  graph = {{0, 44, 39, 33, 60, 63}, {44, 0, 79, 27, 3, 97},
           {39, 79, 0, 83, 1, 66},  {33, 27, 83, 0, 56, 99},
           {60, 3, 1, 56, 0, 78},   {63, 97, 66, 99, 78, 0}};

  result = getOMPDeicstra(graph, count);

  ref = {0,  43, 39, 33, 40, 63, 43, 0, 4, 27, 3, 70, 39, 4,  0,  31, 1,  66,
         33, 27, 31, 0,  30, 96, 40, 3, 1, 30, 0, 67, 63, 70, 66, 96, 67, 0};

  for (int i = 0; i < count * count; ++i) {
    ASSERT_EQ(result[i], ref[i]);
  }
}

TEST(DEICSTRA_ALGORITHM_OMP, TEST_4) {
  const int count = 6;
  std::vector<int> result;
  std::vector<int> ref;
  std::vector<std::vector<int>> graph;

  graph = {{0, 45, 39, 24, 68, 63}, {45, 0, 13, 91, 41, 59},
           {39, 13, 0, 32, 48, 49}, {24, 91, 32, 0, 16, 43},
           {68, 41, 48, 16, 0, 13}, {63, 59, 49, 43, 13, 0}};

  result = getOMPDeicstra(graph, count);

  ref = {0,  45, 39, 24, 40, 53, 45, 0,  13, 45, 41, 54, 39, 13, 0,  32, 48, 49,
         24, 45, 32, 0,  16, 29, 40, 41, 48, 16, 0,  13, 53, 54, 49, 29, 13, 0};

  for (int i = 0; i < count * count; ++i) {
    ASSERT_EQ(result[i], ref[i]);
  }
}

TEST(DEICSTRA_ALGORITHM_OMP, TEST_5) {
  const int count = 200;
  std::vector<int> result;
  std::vector<int> ref;
  std::vector<std::vector<int>> graph;

  graph = getRandomVector(count);
  result = getOMPDeicstra(graph, count);
}
