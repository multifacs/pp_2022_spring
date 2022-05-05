// Copyright 2022 Elanskiy Alexander
#include "../../modules/task_3/elanskiy_a_rectangle_method/rectangle_method.h"

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
    //  tbb::task_scheduler_init init(16);
    tbb::parallel_for(tbb::blocked_range<int>(0, size_integ),
        [&vec_sum_inter, &integrals, &step, &h](const tbb::blocked_range<int>& r) {
            for (int i = r.begin(); i != r.end(); i++) {
                float tmp = integrals[i][1] - integrals[i][0];
                tmp = tmp / step;
                h.push_back(tmp);
                vec_sum_inter.push_back(0);
            }
        });
    tbb::parallel_for(tbb::blocked_range<int>(0, step),
        [&size_integ, &vec_sum_inter, &f, &integrals, &h](const tbb::blocked_range<int>& r) {
            for (int i = r.begin(); i != r.end(); i++) {
                for (int j = 0; j < size_integ; j++) {
                    vec_sum_inter[j] += f(integrals[j][0] + i * h[j]) * h[j];
                }
            }
        });
    double result = 1;
    tbb::parallel_for(tbb::blocked_range<int>(0, size_integ),
        [&vec_sum_inter, &result](const tbb::blocked_range<int>& r) {
            for (int i = r.begin(); i != r.end(); i++) {
                result *= vec_sum_inter[i];
            }
        });
    result = round(result * 10000) / 10000;
    return result;
}
