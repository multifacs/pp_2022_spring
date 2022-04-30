// Copyright 2022 Kuklin Andrey
#include <gtest/gtest.h>
#include "./batcher_mergesort.h"

TEST(kuklin_a_betcher_mergesort, genRandVec) {
  ASSERT_NO_THROW(getRandVec(10, -100., 100.));
}

TEST(kuklin_a_betcher_mergesort, can_sort_positive_nubm) {
  auto vec = getRandVec(10, 10, 30);

  ASSERT_NO_THROW(floatRadixSort(&vec));
}

TEST(kuklin_a_betcher_mergesort, can_sort_negative_nubm) {
  auto vec = getRandVec(10, -30, -20);

  ASSERT_NO_THROW(floatRadixSort(&vec));
}

TEST(kuklin_a_betcher_mergesort, can_sort_rand_nubm) {
  auto vec = getRandVec(10, -100, 100);

  ASSERT_NO_THROW(floatRadixSort(&vec));
}

TEST(kuklin_a_betcher_mergesort, radix_sort_correct) {
  auto vec = getRandVec(100, -100, 100);

  auto copy_vec(vec);
  std::sort(copy_vec.begin(), copy_vec.end());

  floatRadixSort(&vec);
  ASSERT_EQ(vec, copy_vec);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
