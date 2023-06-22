#include <iostream>
#include <Windows.h>
#include <string>
#include <stdlib.h>
#include <fstream>
#include "../contracts/Constants.h"

CRITICAL_SECTION criticalSection;

int main() {
    printf("Input filename: ");
    char filename[FILENAME_SIZE];
    std::cin >> filename;
    printf("Input processes of sender number");
    int countOfSenders;
    std::cin >> countOfSenders;
    HANDLE* SenderEventsToSync = new HANDLE[countOfSenders];

    InitializeCriticalSection(&criticalSection);

    const char* appName = "sender.exe";
    HANDLE eventToStart = CreateEventA(&securityAtb, FALSE, FALSE, EVENT_NAME);
    for (int i = 0; i < countOfSenders; i++) {
        char arg[SIZE_OF_ARGS];
        char buff[10];
        strcat(arg, filename);

        char argg[10];
        strcat(argg, "Event ");
        strcat(argg, itoa(i, buff, 10));

        strcat(arg, " Event ");
        strcat(arg, itoa(i, buff, 10));

    }
    WaitForMultipleObjects(countOfSenders, SenderEventsToSync, TRUE, INFINITE);
    SetEvent(eventToStart);
}

