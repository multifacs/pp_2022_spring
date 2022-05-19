
#include "../../../modules/task_1/purtova_k_shell_sort_batcher_merge/shell_sort.h"
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


//Сортировка Шелла с четно-нечетным слиянием Бэтчера.

// Сортировка Шелла
void Shell(std::vector<int>& A, int n) {

	for (int step = n / 2; step > 0; step /= 2) { 
		for (int i = step; i < n; i++) { 
			for (int j = i - step; j >= 0 && A[j] > A[j + step]; j -= step) { 
				int x = A[j]; 
				A[j] = A[j + step]; 
				A[j + step] = x; 
			} 
		} 
	}
}

// Слияние двух массивов через элемент 
std::vector <int> MergerEvenOdd(std::vector<int>& arr1, std::vector<int>& arr2, int i1, int i2, int size_result) {
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
std::vector<int> BatcherEvenNumber(std::vector<int>& arr1, std::vector<int>& arr2) {		// even - четные 
	int size_result = arr1.size()/2 + arr2.size()/2 + arr1.size()%2 + arr2.size()%2;

	std::vector <int> array_result(size_result);

	int i1 = 0, i2 = 0;

	array_result = MergerEvenOdd(arr1, arr2, i1, i2, size_result);

	return array_result;
}

// Слияние элементов под нечетными номерами 
std::vector<int> BatcherOddNumber(std::vector<int>& arr1, std::vector<int>& arr2) {		//odd - нечетные
	int size_result = arr1.size() / 2 + arr2.size() / 2;

	std::vector <int> array_result(size_result);

	int i1 = 1, i2 = 1;

	array_result = MergerEvenOdd(arr1, arr2, i1, i2, size_result);

	return array_result;
}



//4
//2 | 2
//even 2
//odd 2
//
//5 
//3 | 2
//even 3
//odd 2

std::vector<int> BatcherMerger(std::vector<int>& arr1, std::vector<int>& arr2) {
	int size_result = arr1.size() + arr2.size();
	std::vector<int> array_result(size_result);
	int i1 = 0, i2 = 0, i = 0;

	while ((i1 != arr1.size()) && (i2 != arr2.size()))
	{
		if (arr1[i1] <= arr2[i2])
		{
			array_result[i] = arr1[i1];
			i1++;
		}
		else
		{
			array_result[i] = arr2[i2];
			i2++;
		}
		i++;
	}
	if (i1 == arr1.size())
		for (int j = i2; j < arr2.size(); j++)
			array_result[arr1.size() + j] = arr2[j];
	else
		for (int j = i1; j < arr1.size(); j++)
			array_result[arr2.size() + j] = arr1[j];

	return array_result;
}


// Четно-нечетное слияние Бэтчера 

std::vector<int> ShellWithBatcher(std::vector<int>& A, int n) {
	int half = n / 2;
	std::vector<int> arr1(half + 1);
	arr1 = { A.begin(), A.end() - half };
	std::vector<int> arr2(half);
	arr2 = { A.end() - half, A.end() }; // - half + 1 ?
	
	Shell(arr1, arr1.size());
	Shell(arr2, arr2.size());

	std::vector<int> even = BatcherEvenNumber(arr1, arr2);
	std::vector<int> odd = BatcherOddNumber(arr1, arr2);
	std::vector<int> merger = BatcherMerger(even, odd);
	return merger;
}

