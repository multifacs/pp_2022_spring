// Copyright 2022 Gleb "belgad" Danshin
#include <gtest/gtest.h>
#include <chrono>
#include <cmath>
#include <iostream>

#include "../../../modules/task_1/danshin_g_integral_rectangle/integral_rectangle.hpp"

TEST(Danshin, Test1) {
    size_t dim = 1;
    auto step = new double{0.1};
    auto lower = new double{0.0};
    auto upper = new double{1.0};
    auto func = [](double* point) -> double {
        return point[0];
    };
    auto start_time = std::chrono::system_clock::now();
    auto result = Integrate(dim, step, lower, upper, func);
    auto end_time = std::chrono::system_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>
        (end_time - start_time).count();
    std::cout << "Time: " << duration << " us" << std::endl;
    delete step;
    delete lower;
    delete upper;
    ASSERT_DOUBLE_EQ(result, 0.45);
}

TEST(Danshin, Test2) {
    size_t dim = 2;
    auto step = new double[2]{0.1, 0.1};
    auto lower = new double[2]{0.0, 0.0};
    auto upper = new double[2]{1.0, 1.0};
    auto func = [](double* point) -> double {
        return point[0] * point[1];
    };
    auto start_time = std::chrono::system_clock::now();
    auto result = Integrate(dim, step, lower, upper, func);
    auto end_time = std::chrono::system_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>
        (end_time - start_time).count();
    std::cout << "Time: " << duration << " us" << std::endl;
    delete[] step;
    delete[] lower;
    delete[] upper;
    ASSERT_DOUBLE_EQ(result, 0.2025);
}

TEST(Danshin, Test3) {
    size_t dim = 2;
    auto step = new double[2]{0.001, 0.001};
    auto lower = new double[2]{0.0, 0.0};
    auto upper = new double[2]{1.0, 1.0};
    auto func = [](double* point) -> double {
        return point[0] * point[1];
    };
    auto start_time = std::chrono::system_clock::now();
    auto result = Integrate(dim, step, lower, upper, func);
    auto end_time = std::chrono::system_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>
        (end_time - start_time).count();
    std::cout << "Time: " << duration << " us" << std::endl;
    delete[] step;
    delete[] lower;
    delete[] upper;
    ASSERT_NEAR(result, 0.2495, 0.0001);
}

TEST(Danshin, Test4) {
    size_t dim = 3;
    auto step = new double[3]{0.1, 0.1, 0.1};
    auto lower = new double[3]{0.0, 0.0, 0.0};
    auto upper = new double[3]{2.0, 1.5, 1.0};
    auto func = [](double* point) -> double {
        return std::sqrt(point[0]) * point[1] + point[2];
    };
    auto start_time = std::chrono::system_clock::now();
    auto result = Integrate(dim, step, lower, upper, func);
    auto end_time = std::chrono::system_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>
        (end_time - start_time).count();
    std::cout << "Time: " << duration << " us" << std::endl;
    delete[] step;
    delete[] lower;
    delete[] upper;
    ASSERT_NEAR(result, 3.249, 0.001);
}

TEST(Danshin, Test5) {
    size_t dim = 3;
    auto step = new double[3]{0.001, 0.001, 0.1};
    auto lower = new double[3]{0.0, 0.0, 0.0};
    auto upper = new double[3]{2.0, 1.5, 1.0};
    auto func = [](double* point) -> double {
        return std::sqrt(point[0]) * point[1] + point[2];
    };
    auto start_time = std::chrono::system_clock::now();
    auto result = Integrate(dim, step, lower, upper, func);
    auto end_time = std::chrono::system_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>
        (end_time - start_time).count();
    std::cout << "Time: " << duration << " us" << std::endl;
    delete[] step;
    delete[] lower;
    delete[] upper;
    ASSERT_NEAR(result, 3.4691, 0.0001);
}

int main(int argc, char* argv[]) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
