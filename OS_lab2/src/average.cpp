//
// Created by pawel on 4/19/23.
//

#include "../include/average.h"
#include <chrono>
#include <thread>

void AverageThread::run() {
    int sum = 0;
    for (int i : arr_) {
        sum += i;
        std::this_thread::sleep_for(std::chrono::milliseconds(12));
    }
    avg_ = 1.0 * sum / arr_.size();
}
