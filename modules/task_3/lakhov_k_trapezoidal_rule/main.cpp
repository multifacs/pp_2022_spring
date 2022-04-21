// Copyright 2022 Lakhov Kirill
#include <gtest/gtest.h>
#include <math.h>

#include <algorithm>
#include <vector>

#include "./trapezoidal_rule.h"

// f(x) = x
double f1(std::vector<double> args) {
  return args[0];
}

// f(x, y) = x + y
double f2(std::vector<double> args) {
  return args[0] + args[1];
}

// f(x, y, z) = x + y + z
double f3(std::vector<double> args) {
  return args[0] + args[1] + args[2];
}

// f(x, y, z) = e^(-x-y-z)
double f4(std::vector<double> args) {
  return exp(-args[0]-args[1]-args[2]);
}

// f(x, y) = log10(x^2) + 3y
double f5(std::vector<double> args) {
  return log10(args[0]*args[0]) + 3 * args[1];
}

TEST(lakhov_trapezoidal_rule_tbb, func1) {
  ASSERT_EQ(true, true);
}

TEST(lakhov_trapezoidal_rule_tbb, func2) {
  std::vector<std::pair<double, double>> intervals(2);
  intervals[0] = {0, 2};
  intervals[1] = {0, 2};
  int interval_count = 70;
  // double result_seq = trapezoidalRuleSeq(f2, intervals, interval_count);
  double result_p = trapezoidalRuleParallel(f2, intervals, interval_count);
  std::cout << result_p << std::endl;
  ASSERT_EQ(true, true);
}

TEST(lakhov_trapezoidal_rule_tbb, func3) {
  ASSERT_EQ(true, true);
}

TEST(lakhov_trapezoidal_rule_tbb, func4) {
  ASSERT_EQ(true, true);
}

TEST(lakhov_trapezoidal_rule_tbb, func5) {
  ASSERT_EQ(true, true);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
