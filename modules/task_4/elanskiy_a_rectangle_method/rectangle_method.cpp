// Copyright 2022 Elanskiy Alexander
#include "../../modules/task_4/elanskiy_a_rectangle_method/rectangle_method.h"

double rec_seq(std::vector<std::vector<int>> integrals, int step, const std::function<double(const double&)>& f) {
    int size_integ = integrals.size();
    std::vector<double> h;
    std::vector<double> vec_sum_inter;
    for (int i = 0; i < size_integ; i++) {
        float tmp = integrals[i][1] - integrals[i][0];
        tmp = tmp / step;
        h.push_back(tmp);
        vec_sum_inter.push_back(0);
    }
    for (int i = 0; i < step; i++) {
        for (int j = 0; j < size_integ; j++) {
            vec_sum_inter[j] += f(integrals[j][0] + i * h[j]) * h[j];
        }
    }
    double result = 1;
    for (int i = 0; i < size_integ; i++) {
        result *= vec_sum_inter[i];
    }
    result = round(result * 10000) / 10000;
    return result;
}

double rec_par(std::vector<std::vector<int>> integrals, int step, const std::function<double(const double&)>& f) {
    int size_integ = integrals.size();
    std::vector<double> h;
    std::vector<double> vec_sum_inter;
    std::vector<std::thread> vec_threads;
    int nthreads = 12;

    for (int i = 0; i < size_integ; i++) {
        float tmp = integrals[i][1] - integrals[i][0];
        tmp = tmp / step;
        h.push_back(tmp);
        vec_sum_inter.push_back(0);
    }

    int step_of_thread;
    int tmp;
    if (step / nthreads == 0) {
        do {
            nthreads--;
            step_of_thread = step / nthreads;
            tmp = step % nthreads;
        } while (step / nthreads == 0);
    } else {
        step_of_thread = step / nthreads;
        tmp = step % nthreads;
    }

    for (int i = 1; i <= step - tmp; i += step_of_thread) {
        int x1 = i;
        int x2 = i + step_of_thread - 1;
        if (x2 == step - tmp) {
            x2 += tmp;
        }
        vec_threads.push_back(std::thread(
            [x1, x2, &size_integ, &vec_sum_inter, &f, &integrals, &h]() {
                for (int e = x1; e <= x2; e++) {
                    for (int j = 0; j < size_integ; j++) {
                        vec_sum_inter[j] += f(integrals[j][0] + (e - 1) * h[j]) * h[j];
                    }
                }
            }));
    }

    for (int i = 0; i < static_cast<int>(vec_threads.size()); i++) {
        vec_threads[i].join();
    }

    double result = 1;
    for (int i = 0; i < size_integ; i++) {
        result *= vec_sum_inter[i];
    }
    result = round(result * 10000) / 10000;
    return result;
}
