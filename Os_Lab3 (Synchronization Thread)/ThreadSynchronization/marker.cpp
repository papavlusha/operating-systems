#include "marker.h"
#include <iostream>

unsigned int WINAPI marker(void* arguments) {
    markerArguments* params = (markerArguments*)arguments;
    srand(params->markerNumber);
    WaitForSingleObject(params->startEvent, INFINITE);

    printf("Marker %i started", params->markerNumber);

    bool stop = false;

    int rNumber;
    int* changedNumbers = new int[params->size];
    int changedCount = 0;

    while (!stop) {
        EnterCriticalSection(&params->criticalSection);

        rNumber = rand() % params->size;
        if (params->array[rNumber] == 0) {
            Sleep(5);
            params->array[rNumber] = params->markerNumber;
            changedNumbers[changedCount] = rNumber;
            ++changedCount;
            LeaveCriticalSection(&params->criticalSection);
            Sleep(5);
        }
        else {
            printf("Marker %i stopped", params->markerNumber);
            LeaveCriticalSection(&params->criticalSection);

            WaitForSingleObject(params->startEvent, INFINITE);
            if (params->markerNumber == params->markerToStop) {
                while (changedCount != 0) {
                    --changedCount;
                    params->array[changedNumbers[changedCount]] = 0;
                }
                stop = true;
                printf("Marker %i ended its work", params->markerNumber);
            }
            else {
                WaitForSingleObject(params->startEvent, INFINITE);
            }
        }
    }


}
