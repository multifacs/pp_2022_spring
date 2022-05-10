// Copyright 2022 Bezrodnov Dmitry

#include <iostream>

#include "../../../modules/task_3/bezrodnov_d_radix_sort_double_batcher/radix_sort_double_batcher.h"

std::vector<std::vector<int>> get_vector_part_tbb(const std::vector<int>& vec,
                                                unsigned int part) {
    std::vector<std::vector<int>> result(part);
    tbb::parallel_for(tbb::blocked_range<int>(0, result.size()),
        [&](const tbb::blocked_range<int>& range) {
            for (int i = range.begin(); i < range.end(); i++) {
                for (int j = 0; j < vec.size() / part; j++) {
                    int index = i * (vec.size() / part);
                    result[i].push_back(vec[index + j]);
                }
            }
        });

    if (part * (vec.size() / part) < vec.size()) {
        for (size_t i = part * (vec.size() / part); i < vec.size(); i++) {
            result[result.size() - 1].push_back(vec[i]);
        }
    }
    return result;
}

std::vector<int> to_int_tbb(const std::vector<double>& vec,
                                unsigned int count) {
    std::vector<int> result(vec.size());
    tbb::parallel_for(tbb::blocked_range<int>(0, vec.size()),
        [&](const tbb::blocked_range<int>& range) {
            for (int i = range.begin(); i < range.end(); i++) {
                result[i] = static_cast<int>(vec[i] * pow(10, count));
            }
        });
    return result;
}

std::vector<double> to_double_tbb(const std::vector<int>& vec,
                                    unsigned int count) {
    std::vector<double> result(vec.size());
    tbb::parallel_for(tbb::blocked_range<int>(0, vec.size()),
        [&](const tbb::blocked_range<int>& range) {
            for (int i = range.begin(); i < range.end(); i++) {
                result[i] = static_cast<double>(vec[i]) / pow(10.0, count);
            }
        });
    return result;
}

std::vector<int> counting_sort_tbb(const std::vector<int>& vec, int div) {
    std::vector<int> result(vec.size());
    std::vector<int> count(10, 0);

    for (int i = 0; i < vec.size(); i++) {
        int index = (vec[i] / div) % 10;
        count[index]++;
    }

    for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (int i = vec.size() - 1; i >= 0; i--) {
        result[count[(vec[i] / div) % 10] - 1] = vec[i];
        count[(vec[i] / div) % 10]--;
    }
    return result;
}

std::vector<double> radix_sort_tbb(const std::vector<double>& vec,
                                    unsigned int count) {
    std::vector<int> vec_int = to_int_tbb(vec, count);
    unsigned int num_thread = 4;
    std::vector<std::vector<int>> vector_part
                        = get_vector_part_tbb(vec_int, num_thread);

    tbb::parallel_for(tbb::blocked_range<int>(0, num_thread, 1),
        [&](const tbb::blocked_range<int>& range) {
            for (int i = range.begin(); i < range.end(); i++) {
                int m = *max_element(vector_part[i].begin(),
                                        vector_part[i].end());
                for (int div = 1; m / div > 0; div *= 10) {
                    vector_part[i] = counting_sort_tbb(vector_part[i], div);
                }
            }
        });

    OddEvenMerge merge;
    std::vector<int> part_all
                    = merge.odd_even_merge(vector_part[0], vector_part[1]);
    for (size_t i = 2; i < num_thread; i++) {
        part_all = merge.odd_even_merge(part_all, vector_part[i]);
    }
    std::vector<double> current_result = to_double_tbb(part_all, count);
    return current_result;
}

bool check_sort(const std::vector<double>& vec) {
    for (int i = 0; i < vec.size() - 1; i++) {
        if (vec[i] > vec[i + 1])
            return false;
    }
    return true;
}

std::vector<double> get_random_double_vector(unsigned int elements) {
    std::vector<double> result(elements);
    std::uniform_real_distribution<double> distribution(10.0, 120.0);
    std::mt19937 engine{ std::random_device().operator ()() };
    auto generator = std::bind(distribution, engine);
    std::generate_n(result.begin(), elements, generator);
    for (int i = 0; i < result.size(); i++) {
        result[i] -= remainder(result[i], 0.001);
    }
    return result;
}
