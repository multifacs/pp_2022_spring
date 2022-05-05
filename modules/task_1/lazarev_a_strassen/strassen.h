// Copyright 2022 Lazarev Aleksey
#ifndef MODULES_TASK_1_LAZAREV_A_STRASSEN_STRASSEN_H_
#define MODULES_TASK_1_LAZAREV_A_STRASSEN_STRASSEN_H_

#include <string>
#include <vector>

const int threshold = 128;

int** initializeMatrix(int n);
void setToRandom(int** A, int n);

int** strassenMultiply(int** A, int** B, int n);
int** multiply(int** A, int** B, int n);

void cleanup(int** A, int n);

#endif  // MODULES_TASK_1_LAZAREV_A_STRASSEN_STRASSEN_H_
