// Copyright 2022 Zotov Maxim
#include <omp.h>
#include <vector>
#include <string>
#include <random>
#include <iostream>
#include "../../../modules/task_1/zotov_m_sort_with_batcher_merge/sort_with_batcher_merge.h"

const int MAX = 5000;

std::vector<int> getRandomVector(int size) {
    std::mt19937 generate;
    generate.seed(time(0));
    std::uniform_real_distribution<> uid(-MAX, MAX);
    std::vector<int> tmp;
    for (int i = 0; i < size; i++) {
        tmp.push_back(uid(generate));
    }
    return tmp;
}

int getMaxPower(const int max ) {
    int tmp = 0;
    for (int i = 1; i < 10; i++) {
        tmp = max / static_cast<int>(pow(10, i));
        if (tmp == 0) {
            std::cout << i << std::endl;
            return i;
        }
    }
}

void radixSort(std::vector<int>* main_data) {
    std::vector<int> sorted_data[19];
    int size = main_data->size();
    int koef = 0;
    int max_power = getMaxPower(MAX);
    while (koef < max_power) {
        for (int i = 0; i < size; i++) {
            int digit = (*main_data)[i] / static_cast<int>(pow(10, koef));
            digit = digit % 10;
            sorted_data[digit + 9].push_back((*main_data)[i]);
        }

        int iter = 0;
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < sorted_data[i].size(); j++) {
                (*main_data)[iter ] = sorted_data[i][j];
                iter++;
            }
            sorted_data[i].clear();
        }
        koef++;
    }
}
