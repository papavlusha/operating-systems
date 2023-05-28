#include "windows.h"
#include <vector>

struct markerArguments {
    int* array;
    int& markerToStop;
    int size;
    int markerNumber;

    CRITICAL_SECTION& criticalSection;
    HANDLE startEvent;

    markerArguments(int* array, int size, int number, const CRITICAL_SECTION& criticalSection, const void* startEvent,
        int& markerToStop) : array(array), size(size), markerNumber(number),
        criticalSection(const_cast<CRITICAL_SECTION&>(criticalSection)), startEvent(const_cast<HANDLE>(startEvent)),
        markerToStop(markerToStop) {}
};

unsigned int WINAPI marker(void* arguments);

