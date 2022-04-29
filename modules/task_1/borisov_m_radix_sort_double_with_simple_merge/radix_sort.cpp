// Copyright 2022 Borisov Maxim

#include "../../../modules/task_1/borisov_m_radix_sort_double_with_simple_merge/radix_sort.h"

std::vector<double> random_vec(int size) {
  std::vector<double> data(size);
  std::mt19937 gen;
  gen.seed(static_cast<uint32_t>(time(0)));
  std::uniform_real_distribution<double> buf(1, 1000);
  std::transform(data.begin(), data.end(), data.begin(),
                 [&](double x) { return buf(gen); });
  return data;
}

std::vector<double> merge(double* arr1, double* arr2, int len1, int len2) {
  std::vector<double> out(len1 + len2);
  int x = 0, y = 0;
  for (int i = 0; i < len1 + len2; i++) {
    if (x >= len1) {
      out[i] = arr2[y++];
    } else if (y >= len2) {
      out[i] = arr1[x++];
    } else if (arr1[x] < arr2[y]) {
      out[i] = arr1[x++];
    } else {
      out[i] = arr2[y++];
    }
  }
  return out;
}

void count_sort(double* in, double* out, int len, int exp) {
  u_char* buf = reinterpret_cast<u_char*>(in);
  int count[256] = {0};
  int val = 0;
  for (int i = 0; i < len; i++) {
    count[buf[8 * 8 + exp]]++;
  }
  int j = 0;
  for (; j < 256; j++) {
    if (count[j] != 0) break;
  }
  val = count[j];
  count[j] = 0;
  j++;
  for (; j < 256; j++) {
    int tmp = count[j];
    count[j] = val;
    val += tmp;
  }
  for (int i = 0; i < len; i++) {
    out[count[buf[8 * i + exp]]] = in[i];
    count[buf[8 * i + exp]]++;
  }
}

std::vector<double> radix_sort(std::vector<double> data1,
                               std::vector<double> data2) {
  std::vector<double> out_data(data1.size());

  int len1 = static_cast<int>(data1.size());
  int len2 = static_cast<int>(data2.size());

  double* in1 = data1.data();
  double* out1 = reinterpret_cast<double*>(malloc(sizeof(double) * len1));

  double* in2 = data2.data();
  double* out2 = reinterpret_cast<double*>(malloc(sizeof(double) * len2));

  for (int i = 0; i < 4; i++) {
    count_sort(in1, out1, len1, 2 * i);
    count_sort(out1, in1, len1, 2 * i + 1);
  }

  for (int i = 0; i < 4; i++) {
    count_sort(in2, out2, len2, 2 * i);
    count_sort(out2, in2, len2, 2 * i + 1);
  }
  return merge(in1, in2, len1, len2);
}
