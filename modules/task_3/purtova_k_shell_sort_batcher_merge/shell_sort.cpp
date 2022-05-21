// Copyright 2022 Purtova Ksenia 
#include "../../../modules/task_3/purtova_k_shell_sort_batcher_merge/shell_sort.h"
#include <tbb/tbb.h>
#include <iostream>
#include <vector>
#include <random>
#include <ctime>

// Генерация рандомного вектора

std::vector<int> VectorRandomizer(int size) { 

    std::vector<int> vec(size);

    std::mt19937 engine;
    engine.seed(static_cast<int>(time(nullptr)));

    for (int i = 0; i < size; i++) 
        vec[i] = engine();
    return vec;
}

// Сортировка Шелла с четно-нечетным слиянием Бэтчера.

// Сортировка Шелла
std::vector<int> Shell(const std::vector<int>& arr, int n) {
    std::vector A = arr;
    for (int step = n / 2; step > 0; step /= 2) { 
        for (int i = step; i < n; i++) { 
            for (int j = i - step; j >= 0 && A[j] > A[j + step]; j -= step) { 
                int x = A[j]; 
                A[j] = A[j + step]; 
                A[j + step] = x; 
            } 
        } 
    }
    return A;
}

// Разделение одного вектора на части
std::vector <std::vector<int>> splitVector(const std::vector<int>& vec, size_t number) {
    std::vector<std::vector<int>> array_of_vec;
    size_t piece_lenght = vec.size() / number;
    size_t remainder = vec.size() % number;
    size_t begin = 0, end = 0;

    for (int i = 0; i < std::min(number, vec.size()); i++) {
        if (remainder > 0) {
            end += piece_lenght + 1;
            remainder--;
        }
        else end += piece_lenght;

        array_of_vec.push_back(std::vector<int>(vec.begin() + begin, vec.begin() + end));
        begin = end;
    }
    return array_of_vec;
}

// Слияние двух массивов через элемент 
std::vector <int> MergerEvenOdd(const std::vector<int>& arr1, const std::vector<int>& arr2, int i1, int i2, int size_result) {
    std::vector <int> array_result(size_result);
    int i = 0;
    while (i1 < arr1.size() && (i2 < arr2.size())) {
        if (arr1[i1] <= arr2[i2]) {
            array_result[i] = arr1[i1];
            i++;
            i1 += 2;
        }
        else {
            array_result[i] = arr2[i2];
            i++;
            i2 += 2;
        }
    }

    if (i1 >= arr1.size()) {
        for (i2; i2 < arr2.size(); i2 += 2) {
            array_result[i] = arr2[i2];
            i++;
        }
    }
    if (i2 >= arr2.size()) {
        for (i1; i1 < arr1.size(); i1 += 2) {
            array_result[i] = arr1[i1];
            i++;
        }
    }

    return array_result;
}

// Слияние элементов под четными номерами 
std::vector<int> BatcherEvenNumber(const std::vector<int>& arr1, const std::vector<int>& arr2) {		// even - четные 
    int size_result = arr1.size()/2 + arr2.size()/2 + arr1.size()%2 + arr2.size()%2;

    std::vector <int> array_result(size_result);

    int i1 = 0, i2 = 0;

    array_result = MergerEvenOdd(arr1, arr2, i1, i2, size_result);

    return array_result;
}

// Слияние элементов под нечетными номерами 
std::vector<int> BatcherOddNumber(const std::vector<int>& arr1, const std::vector<int>& arr2) {		//odd - нечетные
    int size_result = arr1.size() / 2 + arr2.size() / 2;

    std::vector <int> array_result(size_result);

    int i1 = 1, i2 = 1;

    array_result = MergerEvenOdd(arr1, arr2, i1, i2, size_result);

    return array_result;
}

std::vector<int> BatcherMerger(const std::vector<int>& arr1, const std::vector<int>& arr2) {
    int size_result = arr1.size() + arr2.size();
    std::vector<int> array_result(size_result);
    int i1 = 0, i2 = 0, i = 0;

    while ((i1 != arr1.size()) && (i2 != arr2.size()))
    {
        if (arr1[i1] <= arr2[i2]) {
            array_result[i] = arr1[i1];
            i1++;
        }
        else {
            array_result[i] = arr2[i2];
            i2++;
        }
        i++;
    }
    if (i1 == arr1.size()) {
        for (int j = i2; j < arr2.size(); j++)
            array_result[arr1.size() + j] = arr2[j];
	}
    else {
        for (int j = i1; j < arr1.size(); j++)
            array_result[arr2.size() + j] = arr1[j];
	}
    return array_result;
}

// Последовательное четно-нечетное слияние Бэтчера 
std::vector<int> ShellWithBatcher(const std::vector<int>& arr, int size, int number) {

    std::vector<std::vector<int>> array_of_vec = splitVector(arr, number);

    for (int i = 0; i < array_of_vec.size(); i++) 
        array_of_vec[i] = Shell(array_of_vec[i], array_of_vec[i].size());

    std::vector<int> even, odd, merger;
    std::vector<int> result_vector = array_of_vec[0];
    for (int i = 1; i < number; i++) {
        even = BatcherEvenNumber(result_vector, array_of_vec[i]);
        odd = BatcherOddNumber(result_vector, array_of_vec[i]);
        result_vector = BatcherMerger(even, odd);
    }
    return result_vector;
}

// Параллельное четно-нечетное слияние Бэтчера 
std::vector<int> ShellWithBatcherTBB(const std::vector<int>& arr, int size, int number) {

    std::vector<std::vector<int>> array_of_vec = splitVector(arr, number);
    
    tbb::task_scheduler_init init(number);
    int grainSize = size/number;
    tbb::parallel_for(tbb::blocked_range<size_t>(0, array_of_vec.size(), grainSize),
        [=](const tbb::blocked_range<size_t>& r) {
            int begin = r.begin(), end = r.end(); 
            for (int i = begin; i != end; i++)
            array_of_vec[i] = Shell(array_of_vec[i], array_of_vec[i].size());
        });
        }
    init.terminate();

    std::vector<int> even, odd, merger;
    std::vector<int> result_vector = array_of_vec[0];

    for (int i = 1; i < number; i++) {
        even = BatcherEvenNumber(result_vector, array_of_vec[i]);
        odd = BatcherOddNumber(result_vector, array_of_vec[i]);
        result_vector = BatcherMerger(even, odd);
    }
    return result_vector;
}