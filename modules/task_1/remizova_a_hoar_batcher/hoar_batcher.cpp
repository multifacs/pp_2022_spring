// Copyright 2022 Remizova Antonina
#include "../../../modules/task_1/remizova_a_hoar_batcher/hoar_batcher.h"
#include <iostream>
#include <random>
#include <vector>

std::vector<double> getRandVector(int size) {
    if (size < 0)
        throw "negative vector size";

    std::mt19937 gen(time(0));
    std::uniform_int_distribution <int> dist(-100000, 100000);
    std::vector <double> vec(size);
    for (int i = 0; i < size; i++) {
        vec[i] = dist(gen);
    }
    return vec;
}

bool isSortCorrectly(std::vector <double>& vec) {
    return std::is_sorted(vec.begin(), vec.end());
}

void hoarSort(std::vector <double>& vec, int l_ind, int r_ind) {
    if (l_ind >= r_ind)
        return;

    if (isSortCorrectly(vec))
        return;

    int l = l_ind, r = r_ind;
    double pvt = vec[(l + r) / 2];

    while (l <= r) {
        while (vec[l] < pvt)
            l++;
        while (vec[r] > pvt)
            r--;
        if (l <= r) {
            std::swap(vec[l], vec[r]);
            l++;
            r--;
        }
    }

    if (l < r_ind)
        hoarSort(vec, l, r_ind);
    if (l_ind < r)
        hoarSort(vec, l_ind, r);

    return;
}

std::vector<double> evenBatcherSort(const std::vector<double>& vec1, const std::vector<double>& vec2)
{
    const int size_v1 = vec1.size();
    const int size_v2 = vec2.size();
    int i = 0, j = 0, k = 0, l = 0;
    const int size_eres = vec1.size() / 2 + vec2.size() / 2 + vec1.size() % 2 + vec2.size() % 2;
    std::vector<double> eres(size_eres);
    for (i, j, k; i < size_v1 && j < size_v2; k++) {
        if (vec1[i] <= vec2[j]) {
            eres[k] = vec1[i];
            i += 2;
        }
        else {
            eres[k] = vec2[j];
            j += 2;
        }
    }
    if (i >= size_v1)
        for (k, l = j; l < size_v2; l += 2, k++)
            eres[k] = vec2[l];
    else
        for (k, l = i; l < size_v1; l += 2, k++)
            eres[k] = vec1[l];

    return eres;
}

std::vector<double> oddBatcherSort(const std::vector<double>& vec1, const std::vector<double>& vec2)
{
    const int size_v1 = vec1.size();
    const int size_v2 = vec2.size();
    int i = 1, j = 1, k = 0, l = 0;
    const int size_ores = vec1.size() / 2 + vec2.size() / 2;
    std::vector<double> ores(size_ores);
    for (i, j, k; i < size_v1 && j < size_v2; k++) {
        if (vec1[i] <= vec2[j]) {
            ores[k] = vec1[i];
            i += 2;
        }
        else {
            ores[k] = vec2[j];
            j += 2;
        }
    }
    if (i >= size_v1)
        for (k, l = j; l < size_v2; l += 2, k++)
            ores[k] = vec2[l];
    else
        for (k, l = i; l < size_v1; l += 2, k++)
            ores[k] = vec1[l];

    return ores;
}

std::vector<double> oddEvenBatcherSort(const std::vector<double>& vec1, const std::vector<double>& vec2)
{
    int size_oeres = vec1.size() + vec2.size();
    std::vector<double> oeres(size_oeres);
    for (size_t i = 0; i < vec1.size(); i++)
        oeres[i] = vec1[i];
    for (size_t i = vec1.size(), j = 0; i < size_oeres; i++, j++)
        oeres[i] = vec2[j];

    return oeres;
}

std::vector<double> mergeBatcher(const std::vector<double>& vec, int middle) {
    int size_res = vec.size();
    std::vector <double> res(size_res);
    int buf;
    for (int i = 0; i < size_res - middle; i++) {
        res[i * 2] = vec[i];
        res[i * 2 + 1] = vec[middle + i];
    }

    if (middle * 2 - size_res >= 1)
        res[size_res - 1] = vec[middle - 1];

    if (middle * 2 - size_res == 2)
        res[size_res - 2] = vec[middle - 2];

    for (int i = 1; i < size_res; i++) {
        if (res[i] < res[i - 1]) {
            buf = res[i - 1];
            res[i - 1] = res[i];
            res[i] = buf;
        }
    }

    return res;
}

std::vector<double> hoarBatcher(const std::vector<double>& vec, int size) {
    int k = size / 2;
    std::vector<double>arr1;
    arr1.assign(vec.begin(), vec.end() - k);
    hoarSort(arr1, 0, arr1.size() - 1);

    std::vector<double> arr2;
    arr2.assign(vec.end() - k, vec.end());
    hoarSort(arr2, 0, arr2.size() - 1);

    std::vector<double>even = evenBatcherSort(arr1, arr2);
    std::vector<double>odd = oddBatcherSort(arr1, arr2);
    std::vector<double>res_oe = oddEvenBatcherSort(even, odd);
    std::vector<double>sort_res = mergeBatcher(res_oe, even.size());
    return sort_res;
}
