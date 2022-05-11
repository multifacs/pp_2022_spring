// Copyright 2022 Zotov Maxim
#include <gtest/gtest.h>
#include <vector>
#include <limits>
#include "./sort_with_batcher_merge.h"

TEST(zotov_radix_sort, Radix_Sort_1) {
    std::vector<int> first_vector = {5,30,-10,-3,23,0,-1,16};
    std::vector<int> second_vector = {-10,-3,-1,0,5,16,23,30};
    radixSort(&first_vector);
    ASSERT_EQ(second_vector, first_vector);
}

TEST(zotov_radix_sort, Radix_Sort_2) {
    std::vector<int> first_vector = getRandomVector(100);
    std::vector<int> second_vector = first_vector;
    radixSort(&first_vector);
    std::sort(second_vector.begin(), second_vector.end());
    ASSERT_EQ(second_vector, first_vector);
}

TEST(zotov_radix_sort, Radix_Sort_3) {
    std::vector<int> first_vector = getRandomVector(10000);
    std::vector<int> second_vector = first_vector;
    radixSort(&first_vector);
    std::sort(second_vector.begin(), second_vector.end());
    ASSERT_EQ(second_vector, first_vector);
}

TEST(zotov_radix_sort, Radix_Sort_4) {
    std::vector<int> first_vector = getRandomVector(100000);
    std::vector<int> second_vector = first_vector;
    radixSort(&first_vector);
    std::sort(second_vector.begin(), second_vector.end());
    ASSERT_EQ(second_vector, first_vector);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
