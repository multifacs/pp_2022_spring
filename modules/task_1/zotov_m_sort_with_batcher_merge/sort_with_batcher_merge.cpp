// Copyright 2018 Nesterov Alexander
#include <omp.h>
#include <vector>
#include <string>
#include <random>
#include <iostream>
#include "../../../modules/task_1/zotov_m_sort_with_batcher_merge/sort_with_batcher_merge.h"

std::vector<int> getRandomVector(int size) {
    std::mt19937 generate;
    generate.seed(time(0));
    std::uniform_real_distribution<> uid(-300, 300);
    std::vector<int> tmp;
    for (int i = 0; i < size; i++) {
        tmp.push_back(uid(generate));
    }
    return tmp;
}

int GetMaxPower(std::vector<int>* data) {
    int max_power = 0;
    int size = data->size();
    while (size > 0) {
        max_power++;
        for (size_t i = 0; i < data->size(); i++) {
            int div = (*data)[i] / powf(10, max_power);
            if (div == 0)
                size--;
        }
    }

    return max_power;
}

void RadixSort(std::vector<int>* main_data, int size, int offset) {
    std::vector<int> sorted_data[19];
    int koef = 0;
    int max_power = GetMaxPower(main_data);
    
    while (koef < max_power) {
        for (int i = offset; i < offset + size; i++) {
            int digit = (*main_data)[i] / pow(10, koef);
            digit = digit % 10;
            sorted_data[digit + 9].push_back((*main_data)[i]);
        }

        //std::cout << "OK" << std::endl;
        //main_data->clear();
        int iter = 0;
        for (int i = 0; i < 19; i++) {
            for (int j = 0; j < sorted_data[i].size(); j++) {
                (*main_data)[offset + iter ] = sorted_data[i][j];
                iter++;
                //main_data->push_back(sorted_data[i][j]);
            }
            sorted_data[i].clear();
        }
        koef++;
        for (int i = offset; i < size + offset; i++) {
            std::cout << (*main_data)[i] << " ";
        }
        std::cout <<"wtf?" << std::endl;
    }

    //return main_data;
}
/*
std::vector<int> RadixSort(std::vector<int> main_data, int n) {
    std::vector<int> sorted_data[19];
    int koef = 0;
    int max_power = GetMaxPower(main_data);
    while (koef < max_power) {
        for (int i = 0; i < n; i++) {
            int digit = main_data[i] / pow(10, koef);
            digit = digit % 10;
            sorted_data[digit + 9].push_back(main_data[i]);
        }


        main_data.clear();
        for (int i = 0; i < 19; i++) {
            for (size_t j = 0; j < sorted_data[i].size(); j++) {
                main_data.push_back(sorted_data[i][j]);
            }
            sorted_data[i].clear();
        }
        koef++;
        for (int i = 0; i < n; i++) {
            std::cout << main_data[i] << " ";
        }
        std::cout << std::endl;
    }

    return main_data;
}
*/