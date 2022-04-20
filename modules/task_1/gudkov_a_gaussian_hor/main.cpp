// Copyright 2022 Gudkov Andrey
#include <gtest/gtest.h>
#include <omp.h>
#include "./gaussian.h"

TEST(Gudkov_Gauss, _10x10) {
    const int width = 10;
    const int height = 10;

    Image img = generateRandomImage(width, height);
    Image res = gaussianFilter(img, width, height);

    ASSERT_NE(res, img);
}

TEST(Gaussian_Image_Filtering_seq, _0x0) {
    const int width = 0;
    const int height = 0;

    Image img = generateRandomImage(width, height);

    ASSERT_EQ(img, gaussianFilter(img, width, height));
}

TEST(Gaussian_Image_Filtering_seq, _50x2) {
    const int width = 50;
    const int height = 2;

    Image img = generateRandomImage(width, height);

    ASSERT_NE(img, gaussianFilter(img, width, height));
}

TEST(Gaussian_Image_Filtering_seq, _2x50) {
    const int width = 2;
    const int height = 50;

    Image img = generateRandomImage(width, height);

    ASSERT_NE(img, gaussianFilter(img, width, height));
}

TEST(Gaussian_Image_Filtering_seq, _10x10_incorrect) {
    const int width = 10;
    const int height = 10;

    Image img = generateRandomImage(width, height);

    ASSERT_ANY_THROW(gaussianFilter(img, width, height - 1));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
