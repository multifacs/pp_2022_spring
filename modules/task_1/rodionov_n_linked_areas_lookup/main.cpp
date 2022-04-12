// Copyright 2022 Nikita Rodionov
#include <gtest/gtest.h>
#include <cstdio>
#include <iostream>
#include <gtest-mpi-listener.hpp>
#include "./linked_areas.h"

const int IMAGE_SIZE1 = 50;
const int IMAGE_SIZE2 = 100;
const int IMAGE_SIZE3 = 200;

TEST(LinkedAreasLookup, GenerateBinaryImageTest1) {
    BinaryImage image = GenerateBinrayImage(IMAGE_SIZE1);

    ASSERT_EQ(image.size, IMAGE_SIZE1);
    // Try to read all values, to check wheter array is okay
    for (int x = 0; x < image.size; x++)
        for (int y = 0; y < image.size; y++)
            bool val = image.Get(x, y);
}
TEST(LinkedAreasLookup, FindAreasTest1) {
    BinaryImage image = GenerateBinrayImage(IMAGE_SIZE1);
    BinaryImageAreas* areas = FindAreas(image);

    // Try to read all values, to check wheter array is okay
    for (int x = 0; x < areas->size; x++)
        for (int y = 0; y < areas->size; y++)
            int val = areas->Get(x, y);
}

TEST(LinkedAreasLookup, GenerateBinaryImageTest2) {
    BinaryImage image = GenerateBinrayImage(IMAGE_SIZE2);

    ASSERT_EQ(image.size, IMAGE_SIZE2);
    // Try to read all values, to check wheter array is okay
    for (int x = 0; x < image.size; x++)
        for (int y = 0; y < image.size; y++)
            bool val = image.Get(x, y);
}
TEST(LinkedAreasLookup, FindAreasTest2) {
    BinaryImage image = GenerateBinrayImage(IMAGE_SIZE2);
    BinaryImageAreas* areas = FindAreas(image);

    // Try to read all values, to check wheter array is okay
    for (int x = 0; x < areas->size; x++)
        for (int y = 0; y < areas->size; y++)
            int val = areas->Get(x, y);
}

TEST(LinkedAreasLookup, GenerateBinaryImageTest3) {
    BinaryImage image = GenerateBinrayImage(IMAGE_SIZE3);

    ASSERT_EQ(image.size, IMAGE_SIZE1);
    // Try to read all values, to check wheter array is okay
    for (int x = 0; x < image.size; x++)
        for (int y = 0; y < image.size; y++)
            bool val = image.Get(x, y);
}
TEST(LinkedAreasLookup, FindAreasTest3) {
    BinaryImage image = GenerateBinrayImage(IMAGE_SIZE3);
    BinaryImageAreas* areas = FindAreas(image);

    // Try to read all values, to check wheter array is okay
    for (int x = 0; x < areas->size; x++)
        for (int y = 0; y < areas->size; y++)
            int val = areas->Get(x, y);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    ::testing::TestEventListeners& listeners =
        ::testing::UnitTest::GetInstance()->listeners();

    listeners.Release(listeners.default_result_printer());
    listeners.Release(listeners.default_xml_generator());

    return RUN_ALL_TESTS();
}
