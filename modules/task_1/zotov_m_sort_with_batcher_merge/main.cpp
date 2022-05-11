// Copyright 2022 Zotov Maksim
#include <gtest/gtest.h>
#include <vector>
#include <limits>
#include "./sort_with_batcher_merge.h"

TEST(Accessory_Functions_Tests, RadixSort_test) {

    if (1) {
        std::vector<int> data;
        std::cout <<INT_MIN<< std::endl;
        int amount = 20;
        std::cout << sizeof(int) << std::endl;
        data = getRandomVector(amount);
        for (int i = 0; i < amount; i++) {
            std::cout << data[i] << " ";
        }
        std::cout << std::endl;
        std::vector<int> actual_data = data;
        RadixSort(&actual_data, actual_data.size()/2, 10);
        sort(data.begin(), data.end());
        ASSERT_TRUE(data == actual_data);
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
