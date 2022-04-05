// Copyright 2018 Nesterov Alexander
#include <gtest/gtest.h>
#include <vector>
#include "../kulemin_p_discharge_double_sort/discharge_double_sort.h"

TEST(Sequential, Test_Arr_10) {
    const int count = 10;
    double* st = create_random_vector(count);
    double* sd = new double[count];
    memcpy(sd, st, sizeof(double) * count);
    discharge_sort(st, count);
    std::sort(sd, sd + count);
    ASSERT_EQ(0, std::memcmp(st, sd, sizeof(st)));
}

TEST(Sequential, Test_Arr_20) {
    const int count = 20;
    double* st = create_random_vector(count);
    double* sd = new double[count];
    memcpy(sd, st, sizeof(double) * count);
    discharge_sort(st, count);
    std::sort(sd, sd + count);
    ASSERT_EQ(0, std::memcmp(st, sd, sizeof(st)));
}

TEST(Sequential, Test_Arr_50) {
    const int count = 50;
    double* st = create_random_vector(count);
    double* sd = new double[count];
    memcpy(sd, st, sizeof(double) * count);
    discharge_sort(st, count);
    std::sort(sd, sd + count);
    ASSERT_EQ(0, std::memcmp(st, sd, sizeof(st)));
}

TEST(Sequential, Test_Arr_100) {
    const int count = 100;
    double* st = create_random_vector(count);
    double* sd = new double[count];
    memcpy(sd, st, sizeof(double) * count);
    discharge_sort(st, count);
    std::sort(sd, sd + count);
    ASSERT_EQ(0, std::memcmp(st, sd, sizeof(st)));
}

TEST(Sequential, Test_Arr_150) {
    const int count = 150;
    double* st = create_random_vector(count);
    double* sd = new double[count];
    memcpy(sd, st, sizeof(double) * count);
    discharge_sort(st, count);
    std::sort(sd, sd + count);
    ASSERT_EQ(0, std::memcmp(st, sd, sizeof(st)));
}
