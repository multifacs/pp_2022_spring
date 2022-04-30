// Copyright 2022 Poplavsky Anton
#include <gtest/gtest.h>

#include "../../../modules/task_1/poplavsky_a_bin_convex_hull/conv.h"

TEST(ConvexHull, time) {
  time_t time1, time2;
  std::random_device dev;
  std::mt19937 gen(dev());
  std::uniform_real_distribution<> urd(-1000, 1000);
  std::vector<Coordinates> points;
  Coordinates pt;
  for (int i = 0; i < SIZE; i++) {
    pt.set_x(urd(gen));
    pt.set_y(urd(gen));
    points.push_back(pt);
  }

  time1 = clock();
  std::vector<Coordinates> hull = graham(points);
  time2 = clock();
  printf("hull time : %lf\n\n",
         static_cast<float>(time2 - time1) / CLOCKS_PER_SEC);
}
