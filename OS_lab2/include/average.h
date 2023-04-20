//
// Created by pawel on 4/19/23.
//
#include <vector>

class AverageThread {
public:
    explicit AverageThread(const std::vector<int>& arr) : arr_(arr) {}

    void run();

    [[nodiscard]] double getAverage() const {
        return avg_;
    }

private:
    std::vector<int> arr_;
    double avg_ = 0.0;
};
