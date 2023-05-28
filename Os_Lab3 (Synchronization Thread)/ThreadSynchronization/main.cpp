#include <iostream>
#include "marker.h"
#include "windows.h"
#include "process.h"

void print(int* array, int size) {
    int i = 0;
    while (i < size) {
        std::cout << array[i] << " ";
        ++i;
    }
    std::cout << std::endl;
}

int main() {
    int size;
    int* array;
    int markerCount;

    CRITICAL_SECTION criticalSection;

    std::cout << "Input array size: " << std::endl;
    std::cin >> size;

    array = new int[size];

    std::fill(array, array + size, 0);

    std::cout << "Input markers count: " << std::endl;
    std::cin >> markerCount;

    HANDLE startEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
    std::vector<HANDLE> threads;
    HANDLE thread;
    std::vector<markerArguments*> args;
    markerArguments* temp;

    int markerToStop;

    int i = 0;
    while (i < markerCount) {
        temp = new markerArguments(array, markerCount, i + 1, criticalSection, startEvent, markerToStop);
        thread = (HANDLE)_beginthreadex(NULL, 0, marker, temp, 0, NULL);

        ++i;
    }
}
