//
// Created by pawel on 4/19/23.
//
#include <chrono>
#include "../include/min_max.h"

void MinMaxThread::run() {
    for (int i = 0; i < arr_.size(); ++i) {
        if (arr_[i] < min_) {
            min_ = arr_[i];
        }
        if (arr_[i] > max_) {
            max_ = arr_[i];
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(7));
    }
}
