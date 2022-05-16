// Copyright 2022 Sorokina Ekaterina

#include "../../../modules/task_1/sorokina_e_radix_int_simple_merge/radix_int_simple_merge.h"

#include <omp.h>

#include <iostream>
#include <random>

INT_VEC getRandomVec(int n) {
  std::random_device dev;
  static std::mt19937 gen(dev());

  INT_VEC vec(n);

  std::generate(vec.begin(), vec.end(), [] { return gen() % 1000; });

  return vec;
}

void radixSort(INT_VEC* vec) {
  int n = static_cast<int>((*vec).size());
  int i = 0, digitPlace = 1;
  INT_VEC result(n);

  int largestNum = *std::max_element((*vec).begin(), (*vec).end());

  while (largestNum / digitPlace > 0) {
    int count[10] = {0};

    for (i = 0; i < n; i++) {
      count[((*vec)[i] / digitPlace) % 10]++;
    }
    for (i = 1; i < 10; i++) {
      count[i] += count[i - 1];
    }
    for (i = n - 1; i >= 0; i--) {
      result[count[((*vec)[i] / digitPlace) % 10] - 1] = (*vec)[i];
      count[((*vec)[i] / digitPlace) % 10]--;
    }
    for (i = 0; i < n; i++) {
      (*vec)[i] = result[i];
    }

    digitPlace *= 10;
  }
}

INT_VEC mergeVecs(INT_VEC arr1, INT_VEC arr2) {
  int n1 = static_cast<int>(arr1.size());
  int n2 = static_cast<int>(arr2.size());

  int i = 0, j = 0, k = 0;

  INT_VEC arr3(n1 + n2);

  while (i < n1 && j < n2) {
    if (arr1[i] < arr2[j])
      arr3[k++] = arr1[i++];
    else
      arr3[k++] = arr2[j++];
  }

  while (i < n1) arr3[k++] = arr1[i++];
  while (j < n2) arr3[k++] = arr2[j++];

  return arr3;
}

void radixSortSimpleMerge(INT_VEC* vec, int parts) {
  std::vector<INT_VEC> vecs(parts);
  int grainsize = static_cast<int>((*vec).size()) / parts;

  if (!grainsize) {
    radixSort(vec);
    return;
  }

  for (int i = 0; i < parts - 1; i++) {
    INT_VEC::const_iterator first = (*vec).begin() + grainsize * i;
    INT_VEC::const_iterator last = (*vec).begin() + grainsize * (i + 1);

    vecs[i] = INT_VEC(first, last);
  }
  vecs.back() = INT_VEC((*vec).begin() + grainsize * (parts - 1), (*vec).end());

  for (auto&& elem : vecs) {
    radixSort(&elem);
  }

  (*vec) = vecs[0];

  for (auto iter = vecs.begin() + 1; iter != vecs.end(); ++iter) {
    (*vec) = mergeVecs((*vec), *iter);
  }
}

void printVec(const INT_VEC& vec) {
  for (auto elem : vec) {
    std::cout << elem << " ";
  }
  std::cout << "\n";
}

bool checkOrder(const INT_VEC& vec) {
  for (auto iter = vec.begin(); iter != std::prev(vec.end()); ++iter) {
    if (*iter > *(iter + 1)) {
      return false;
    }
  }
  return true;
}
