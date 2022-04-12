// Copyright 2022 Nazarov Nikita
#include <gtest/gtest.h>
#include "../../../modules/task_1/nazarov_n_simpson/simpson.h"

double function1(const std::vector<double>& x) { return (x[0] * x[1]); }

double function2(const std::vector<double>& x) { return (x[0] * x[1] * x[2]); }

double function3(const std::vector<double>& x) { return (x[0] * x[1] * x[2] * x[3]); }

double function4(const std::vector<double>& x) { return (x[0] * x[1] * x[2] * x[3] * x[4]); }

double function5(const std::vector<double>& x) { return (x[0] * x[1] * x[2] * x[3] * x[4] * x[5]); }

TEST(Simpson, Dimension_2) {
    int dimension = 2;
    std::vector<std::pair<double, double>> borders { {1, 18}, {-7, 2} };
    std::vector<int> steps(dimension, 100);

    ASSERT_NEAR(simpson(function1, borders, steps), -3633.75, 0.0001);
}

TEST(Simpson, Dimension_3) {
    int dimension = 3;
    std::vector<std::pair<double, double>> borders{ {1, 18}, {-7, 2}, {1, 3} };
    std::vector<int> steps(dimension, 12);

    ASSERT_NEAR(simpson(function2, borders, steps), -14535, 0.0001);

}

TEST(Simpson, Dimension_4) {
    int dimension = 4;
    std::vector<std::pair<double, double>> borders{ {1, 18}, {-7, 2}, {1, 3}, {7, 11} };
    std::vector<int> steps(dimension, 4);

    ASSERT_NEAR(simpson(function3, borders, steps), -523260, 0.0001);

}

TEST(Simpson, Dimension_5) {
    int dimension = 5;
    std::vector<std::pair<double, double>> borders{ {1, 18}, {-7, 2}, {1, 3}, {7, 11}, {0.1, 0.9} };
    std::vector<int> steps(dimension, 2);

    ASSERT_NEAR(simpson(function4, borders, steps), -209304, 0.0001);

}

TEST(Simpson, Dimension_6) {
    int dimension = 6;
    std::vector<std::pair<double, double>> borders{ {1, 18}, {-7, 2}, {1, 3}, {7, 11}, {0.1, 0.9}, {2, 3} };
    std::vector<int> steps(dimension, 1);

    ASSERT_NEAR(simpson(function5, borders, steps), -523260, 0.0001);

}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
    return 0;
}