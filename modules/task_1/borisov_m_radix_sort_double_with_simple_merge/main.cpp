// Copyright 2022 Borisov Maxim

#include "../../../modules/task_1/borisov_m_radix_sort_double/radix_sort.h"
#include "gtest/gtest.h"

#define EPSILON 0.0001

TEST(borisov_task1, test_size_10) {
  std::vector<double> vec = random_vec(10);
  vec = radix_sort(vec);
  ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
}

TEST(borisov_task1, test_size_100) {
  std::vector<double> vec = random_vec(100);
  vec = radix_sort(vec);
  ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
}

TEST(borisov_task1, test_size_500) {
  std::vector<double> vec = random_vec(500);
  vec = radix_sort(vec);
  ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
}

TEST(borisov_task1, test_size_1000) {
  std::vector<double> vec = random_vec(1000);
  vec = radix_sort(vec);
  ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
}

TEST(borisov_task1, test_size_2000) {
  std::vector<double> vec = random_vec(2000);
  vec = radix_sort(vec);
  ASSERT_TRUE(std::is_sorted(vec.begin(), vec.end()));
}

int main(int argc, char** argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}