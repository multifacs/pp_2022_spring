// Copyright 2022 Lebedev Alexey
#include <algorithm>
#include <iostream>
#include "../../../modules/task_2/lebedev_a_convex_hull/convex_hull.h"


bool cw(const cv::Point2d& p1, const cv::Point2d& p2, const cv::Point2d& p3) {
    return p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y) < 0;
}

bool ccw(const cv::Point2d& p1, const cv::Point2d& p2, const cv::Point2d& p3) {
    return p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y) > 0;
}

using points_iterator = std::vector<cv::Point2d>::iterator;
void convex_hull_impl(points_iterator begin, points_iterator end, std::vector<cv::Point2d>* output) {
    size_t size = end - begin;
    if (size <= 2) {
        output->clear();
        output->resize(size);
        std::copy(begin, end, output->begin());
        return;
    }
    std::sort(begin, end, [](const cv::Point2d& p1, const cv::Point2d& p2) {
        return p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y);
        });
    cv::Point2d p1 = *begin, p2 = *(end - 1);
    std::vector<cv::Point2d> up, down;
    up.push_back(p1);
    down.push_back(p1);
    for (size_t i = 1; i < size; ++i) {
        cv::Point2d p = *(begin + i);
        if (i == size - 1 || cw(p1, p, p2)) {
            while (up.size() >= 2 && !cw(up[up.size() - 2], up[up.size() - 1], p)) {
                up.pop_back();
            }
            up.push_back(p);
        }
        if (i == size - 1 || ccw(p1, p, p2)) {
            while (down.size() >= 2 && !ccw(down[down.size() - 2], down[down.size() - 1], p)) {
                down.pop_back();
            }
            down.push_back(p);
        }
    }
    output->clear();
    output->resize(up.size() + down.size() - 2);
    auto it = std::copy(up.begin(), up.end(), output->begin());
    std::copy(down.rbegin() + 1, down.rend() - 1, it);
}


void lab2::convex_hull(const cv::Mat& c1_image, std::vector<cv::Point2d>* output) {
    std::vector<cv::Point2d> non_zeros;
    cv::findNonZero(c1_image, non_zeros);
    convex_hull_impl(non_zeros.begin(), non_zeros.end(), output);
}
