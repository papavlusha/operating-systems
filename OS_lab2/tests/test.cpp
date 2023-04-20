//
// Created by pawel on 4/11/23.
//
#include <gtest/gtest.h>
#include "../src/average.cpp"
#include "../src/min_max.cpp"
#include <ctime>

TEST(MinimumTest, Basic) {
    std::vector<int> arr = { 3, 5, 1, 7, 4, 9 };
    MinMaxThread min_max(arr);
    min_max.run();
    EXPECT_EQ(min_max.getMin(), 1);
}

TEST(MinimumTest, Negative) {
    std::vector<int> arr = { -3, -5, -1, -7, -4, -9 };
    MinMaxThread min_max(arr);
    min_max.run();
    EXPECT_EQ(min_max.getMin(), -9);
}

TEST(MinimumTest, Combine) {
    std::vector<int> arr = { -3, 5, -1, 7, -4, 9 };
    MinMaxThread min_max(arr);
    min_max.run();
    EXPECT_EQ(min_max.getMin(), -4);
}


TEST(MinimumTest, Border) {
    std::vector<int> arr = { -3, 5, INT32_MAX, 7, INT32_MIN, 9 };
    MinMaxThread min_max(arr);
    min_max.run();
    EXPECT_EQ(min_max.getMin(), INT32_MIN);
}

TEST(MaximunTest, Basic) {
    std::vector<int> arr = { 3, 5, 1, 7, 4, 9 };
    MinMaxThread min_max(arr);
    min_max.run();
    EXPECT_EQ(min_max.getMax(), 9);
}

TEST(MaximumTest, Negative) {
    std::vector<int> arr = { -3, -5, -1, -7, -4, -9 };
    MinMaxThread min_max(arr);
    min_max.run();
    EXPECT_EQ(min_max.getMax(), -1);
}

TEST(MaximumTest, Combine) {
    std::vector<int> arr = { -3, 5, -1, 7, -4, 9 };
    MinMaxThread min_max(arr);
    min_max.run();
    EXPECT_EQ(min_max.getMax(), 9);
}

TEST(MaximumTest, Border) {
    std::vector<int> arr = { -3, 5, INT32_MAX, 7, INT32_MIN, 9 };
    MinMaxThread min_max(arr);
    min_max.run();
    EXPECT_EQ(min_max.getMax(), INT32_MAX);
}


TEST(AverageTest, Basic) {
    std::vector<int> arr = { 3, 5, 1, 7, 4, 9 };
    double answer = 0;
    for (int i = 0; i < arr.size(); i++) {
        answer += arr[i];
    }
    answer /= arr.size();
    AverageThread avg(arr);
    avg.run();
    EXPECT_EQ(avg.getAverage(), answer);
}

TEST(AverageTest, Negative) {
    std::vector<int> arr = { -3, -5, -1, -7, -4, -9 };
    double answer = 0;
    for (int i = 0; i < arr.size(); i++) {
        answer += arr[i];
    }
    answer /= arr.size();
    AverageThread avg(arr);
    avg.run();
    EXPECT_EQ(avg.getAverage(), answer);
}

TEST(AverageTest, Combine) {
    std::vector<int> arr = {-3, 5, -1, 7, -4, -9 };
    double answer = 0;
    for (int i = 0; i < arr.size(); i++) {
        answer += arr[i];
    }
    answer /= arr.size();
    AverageThread avg(arr);
    avg.run();
    EXPECT_EQ(avg.getAverage(), answer);
}

TEST(AverageTest, Border) {
    std::vector<int> arr = { -3, 5, INT32_MAX, 7, INT32_MIN, 9 };
    double answer = 0;
    for (int i = 0; i < arr.size(); i++) {
        answer += arr[i];
    }
    answer /= arr.size();
    AverageThread avg(arr);
    avg.run();
    EXPECT_EQ(avg.getAverage(), answer);
}

TEST(TimeTest, Min_Max1) {
    std::vector<int> arr = { -3, 5, -1, 7, -4, 9 };
    int time = arr.size() * 7;
    MinMaxThread min_max(arr);
    clock_t start, end;
    start = clock();
    min_max.run();
    end = clock();
    double time_taken = (double(end - start) / double(CLOCKS_PER_SEC)) * 1000000;
    EXPECT_GT(time_taken, time);
}

TEST(TimeTest, Min_Max2) {
    std::vector<int> arr(2 << 6);
    for (int  i = 0; i < arr.size(); i++) {
        arr[i] = i;
    }
    int time = arr.size() * 7;
    MinMaxThread min_max(arr);
    clock_t start, end;
    start = clock();
    min_max.run();
    end = clock();
    double time_taken = (double(end - start) / double(CLOCKS_PER_SEC)) * 1000000;
    EXPECT_GT(time_taken, time);
}


TEST(TimeTest, Average1) {
    std::vector<int> arr = { -3, 5, -1, 7, -4, 9 };
    int time = arr.size() * 12;
    MinMaxThread min_max(arr);
    clock_t start, end;
    start = clock();
    min_max.run();
    end = clock();
    double time_taken = (double(end - start) / double(CLOCKS_PER_SEC)) * 1000000;
    EXPECT_GT(time_taken, time);
}
TEST(TimeTest, Average2) {
    std::vector<int> arr(2 << 6);
    for (int  i = 0; i < arr.size(); i++) {
        arr[i] = i;
    }
    int time = arr.size() * 12;
    AverageThread avg(arr);
    clock_t start, end;
    start = clock();
    avg.run();
    end = clock();
    double time_taken = (double(end - start) / double(CLOCKS_PER_SEC)) * 1000000;
    EXPECT_GT(time_taken, time);
}

