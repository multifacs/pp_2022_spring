// Copyright 2022 Vorobyova Anya
#include <gtest/gtest.h>
#include <omp.h>

#include "./gauss_horizontal.h"

TEST(GAUSS_HORIZONTAL_TBB, TEST_1) {
  const int width = 14, height = 16;
  img image = getRandomImage(width, height);

  img new_image = getGauss(image, width, height);
  img new_image_tbb = getGaussTBB(image, width, height);

  for (int i = 0; i < static_cast<int>(new_image.size()); i++) {
    ASSERT_EQ(new_image[i], new_image_tbb[i]);
  }
}

TEST(GAUSS_HORIZONTAL_TBB, TEST_2) {
  const int width = 10, height = 12;
  img image = getRandomImage(width, height);

  img new_image = getGauss(image, width, height);
  img new_image_tbb = getGaussTBB(image, width, height);

  for (int i = 0; i < static_cast<int>(new_image.size()); i++) {
    ASSERT_EQ(new_image[i], new_image_tbb[i]);
  }
}

TEST(GAUSS_HORIZONTAL_TBB, TEST_3) {
  const int width = 10, height = 10;
  img image = getRandomImage(width, height);

  img new_image = getGauss(image, width, height);
  img new_image_tbb = getGaussTBB(image, width, height);

  for (int i = 0; i < static_cast<int>(new_image.size()); i++) {
    ASSERT_EQ(new_image[i], new_image_tbb[i]);
  }
}

TEST(GAUSS_HORIZONTAL_TBB, TEST_4) {
  const int width = 11, height = 11;
  img image = getRandomImage(width, height);

  img new_image = getGauss(image, width, height);
  img new_image_tbb = getGaussTBB(image, width, height);

  for (int i = 0; i < static_cast<int>(new_image.size()); i++) {
    ASSERT_EQ(new_image[i], new_image_tbb[i]);
  }
}

TEST(GAUSS_HORIZONTAL_TBB, TEST_5) {
  const int width = 10, height = 10;
  img image = getRandomImage(width, height);

  double time_start, t1, t2;

  time_start = omp_get_wtime();
  img new_image_tbb = getGauss(image, width, height);
  t1 = omp_get_wtime() - time_start;

  time_start = omp_get_wtime();
  img new_image = getGaussTBB(image, width, height);
  t2 = omp_get_wtime() - time_start;

  std::cout << "Seq.: " << t1 << " Par.: " << t2 << " Speed: " << t1 / t2
            << std::endl;
}
