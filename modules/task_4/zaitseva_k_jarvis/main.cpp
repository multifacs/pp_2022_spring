// Copyright 2022 Zaitseva Ksenia
#include <gtest/gtest.h>

#include <chrono>  // NOLINT [build/c++11]
#include <vector>

#include "./jarvis.h"

TEST(OpenMP, Test_Point_equal) {
  Point p1 = {0.2, 0.1};
  Point p2 = p1;
  ASSERT_TRUE(p2 == p1);
}

TEST(OpenMP, Test_Point_less) {
  Point p1 = {0.2, 0.1};
  Point p2 = {-1.4, 0.0};
  ASSERT_TRUE(p2 < p1);
}

TEST(OpenMP, Test_Point_minus) {
  Point p1 = {0.2, 0.1};
  Point p2 = {-1.4, 0.0};
  Point p3 = p1 - p2;
  EXPECT_EQ(Point(1.6, 0.1), p3);
}

TEST(OpenMP, Test_Calc_Determinant) {
  Point p1 = {1.0, -2.0};
  Point p2 = {-1.0, 0.0};
  EXPECT_EQ(-2.0, cross(p1, p2));
}

TEST(OpenMP, Test_Jarvis) {
  std::vector<Point> points = {{2.0, 1.0}, {-0.5, 1.0}, {-3.0, -1.5},
                               {3.5, 1.0}, {0.5, 4.0},  {-4.5, -3.0},
                               {-2.5, 3.5}};
  std::vector<Point> res = Jarvis_parallel_std(points);
  std::vector<Point> expected_res = {
      {-4.5, -3}, {3.5, 1}, {0.5, 4}, {-2.5, 3.5}};
  EXPECT_EQ(res, expected_res);
}

TEST(OpenMP, Test_Generate_and_Draw) {
  std::vector<Point> points = Generate(15);
  std::ofstream fout("shell.txt");
  std::ofstream fout2("points.txt");
  std::vector<Point> res = Jarvis_parallel_std(points);
  for (std::size_t i = 0; i < res.size(); i++)
    fout << res[i].x << std::endl << res[i].y << std::endl;
  fout << res[0].x << std::endl << res[0].y << std::endl;
  for (auto i = points.begin(); i != points.end(); i++)
    fout2 << i->x << std::endl << i->y << std::endl;
  fout.close();
  fout2.close();
}

TEST(OpenMP, Test_Compare_with_Seq) {
  double time_par, time_seq;
  std::vector<Point> points = Generate(1000000);
  auto t1 = std::chrono::system_clock::now();
  std::vector<Point> res_par = Jarvis_parallel_std(points);
  auto t2 = std::chrono::system_clock::now();
  time_par =
      std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
  t1 = std::chrono::system_clock::now();
  std::vector<Point> res_seq = Jarvis(points);
  t2 = std::chrono::system_clock::now();
  time_seq =
      std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1).count();
  std::cout << "Sequential = " << time_seq / 1000.0 << std::endl;
  std::cout << "Parallel = " << time_par / 1000.0 << std::endl;
  std::cout << "Parallel version faster on " << time_seq / time_par
            << std::endl;
  EXPECT_EQ(res_par, res_seq);
}
