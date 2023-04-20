//
// Created by pawel on 4/19/23.
//
#include <vector>
#include <thread>

class MinMaxThread {
public:
    explicit MinMaxThread(std::vector<int> arr) : arr_(arr) {}

    void run();

    int getMin() const {
        return min_;
    }

    int getMax() const {
        return max_;
    }

private:
    std::vector<int> arr_;
    int min_ = INT32_MAX;
    int max_ = INT32_MIN;
};
