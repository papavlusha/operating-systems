//
// Created by pawel on 4/19/23.
//
#include <iostream>
#include <thread>
#include <vector>
#include "../include/min_max.h"
#include "../include/average.h"

int main() {
    int size;
    std::cout << "Enter array size: ";
    std::cin >> size;

    std::vector<int> arr(size);
    std::cout << "Fill in array: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    MinMaxThread min_max(arr);
    AverageThread average(arr);

    std::thread min_max_thread(&MinMaxThread::run, &min_max);
    std::thread average_thread(&AverageThread::run, &average);

    min_max_thread.join();
    average_thread.join();

    double avg = average.getAverage();
    std::cout << "Average value " << avg << std::endl;

    int min = min_max.getMin();
    int max = min_max.getMax();
    std::cout << "Min element: " << min << std::endl;
    std::cout << "Max element: " << max << std::endl;

    for (int i = 0; i < size; ++i) {
        if (arr[i] == min || arr[i] == max) {
            arr[i] = static_cast<int>(avg);
        }
    }

    std::cout << "Array after replacing: ";
    for (int i = 0; i < size; ++i) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}
