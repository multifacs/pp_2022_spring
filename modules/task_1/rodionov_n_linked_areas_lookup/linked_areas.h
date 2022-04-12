// Copyright 2022 Nikita Rodionov
#ifndef MODULES_TASK_1_RODIONOV_N_LINKED_AREAS_LOOKUP_LINKED_AREAS_H_
#define MODULES_TASK_1_RODIONOV_N_LINKED_AREAS_LOOKUP_LINKED_AREAS_H_

#include <cstdlib>

struct BinaryImage {
    bool** image;
    int size;

    BinaryImage(bool** image, int size) {
        this->image = image;
        this->size = size;
    }

    bool Get(int a, int b) {
        if (a < 0 || b < 0 || a >= size || b >= size) {
            return false;
        }
        return image[a][b];
    }
};

struct BinaryImageAreas {
    int components;
    int** image;
    int size;
    int Get(int a, int b) {
        if (a < 0 || b < 0 || a >= size || b >= size) {
            return -1;
        }
        return image[a][b];
    }
};


BinaryImage GenerateBinrayImage(int size);

BinaryImageAreas* FindAreas(BinaryImage image);

void show(BinaryImageAreas image);
#endif  // MODULES_TASK_1_RODIONOV_N_LINKED_AREAS_LOOKUP_LINKED_AREAS_H_
