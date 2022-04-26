// Copyright 2022 Borisov Maxim

#include "../../../modules/task_1/borisov_m_radix_sort_double/radix_sort.h"

std::vector<double> random_vec(int size) {
  std::vector<double> data(size);
  std::mt19937 gen;
  gen.seed(static_cast<uint32_t>(time(0)));
  std::uniform_real_distribution<double> buf(1, 1000);
  for (int i = 0; i < data.size(); i++) {
    data[i] = buf(gen);
  }
  return data;
}

std::vector<int> merge(const std::vector<int>& lhs,
                       const std::vector<int>& rhs) {
  std::vector<int> out(lhs.size() + rhs.size());
  int x = 0, y = 0;
  for (size_t i = 0; i < lhs.size() + rhs.size(); i++) {
    if (x >= lhs.size()) {
      out[i] = rhs[y++];
    } else if (y >= rhs.size()) {
      out[i] = lhs[x++];
    } else if (lhs[x] < rhs[y]) {
      out[i] = lhs[x++];
    } else {
      out[i] = rhs[y++];
    }
  }
  return out;
}

std::vector<int> count_sort(const std::vector<int>& data, int exp) {
  std::vector<int> out(data.size());
  int count[10] = {0};

  for (int i = 0; i < data.size(); i++) {
    count[(data[i] / exp) % 10]++;
  }

  for (int i = 1; i < 10; i++) {
    count[i] += count[i - 1];
  }

  for (int i = data.size() - 1; i >= 0; i--) {
    out[count[(data[i] / exp) % 10] - 1] = data[i];
    count[(data[i] / exp) % 10]--;
  }

  return out;
}

std::vector<double> radix_sort(const std::vector<double>& data) {
  std::vector<double> out(data.size());
  std::vector<int> vec(data.size());
  std::transform(data.begin(), data.end(), vec.begin(),
                 [](double var) { return static_cast<int>(var * 100000); });
  int half_size = static_cast<int>(data.size() / 2);
  std::vector<int> v1(half_size);
  std::vector<int> v2(vec.size() - half_size);
  std::copy(vec.begin(), vec.begin() + half_size, v1.begin());
  std::copy(vec.begin() + (vec.size() - half_size), vec.end(), v2.begin());

  int max_f = *std::max_element(v1.begin(), v1.end());
  for (int exp = 1; max_f / exp > 0; exp *= 10) {
    v1 = count_sort(v1, exp);
  }
  int max_s = *std::max_element(v2.begin(), v2.end());
  for (int exp = 1; max_s / exp > 0; exp *= 10) {
    v2 = count_sort(v2, exp);
  }

  vec = merge(v1, v2);

  std::transform(vec.begin(), vec.end(), out.begin(), [](int var) {
    return static_cast<double>(static_cast<double>(var) / 100000);
  });
  return out;
}

bool is_sorted(const std::vector<double>& data) {
  for (int i = 1; i < data.size(); i++) {
    if (data[i] < data[i - 1]) return false;
  }
  return true;
}
