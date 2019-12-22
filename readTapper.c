#include <stdio.h>
#include <string.h>
#include <sys/time.h>
#include <wiringPi.h>
#include "readTapper.h"

void readTapper(int dotPin, int dashPin, char* morse) {
    int execute = 1;
    struct timeval  tv;
    int i = 0;

    gettimeofday(&tv, NULL);
    double curTime = 
         (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000 ; // convert tv_sec & tv_usec to millisecond
    double prevTime = 
         (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000 ; // convert tv_sec & tv_usec to millisecond
    
    while (execute) {
        gettimeofday(&tv, NULL);
        curTime = (tv.tv_sec) * 1000 + (tv.tv_usec) / 1000 ;

        int curDotKeyPressed = digitalRead(dotPin);
        int curDashKeyPressed = digitalRead(dashPin);
        if (curDotKeyPressed == 1) {
            prevTime = curTime;
            morse[i++] = '.';
            printf(".\n");
        }
        if (curDashKeyPressed == 1) {
            prevTime = curTime;
            morse[i++] = '-';
            printf("-\n");
        }
        if (curTime - prevTime > 2000) {
            execute = 0;
        }
        delay(100); // 10Hz
    }
    morse[i] ='\0';
}

void readTapperWord(int dotPin, int dashPin, char* morse, int nLetters) {
    char morseLetter[15];
    int nLettersEntred = 0;
    int iPosMorse = 0;
    while ((nLettersEntred < nLetters) && (strcmp(morseLetter, ".......") !=0)) {
        readTapper(dotPin, dashPin, morseLetter);
        if (strlen(morseLetter) != 0) {
            for (int i = 0; i<strlen(morseLetter); i++, iPosMorse++) {
                morse[iPosMorse] = morseLetter[i];
            }
            printf("\n");
            morse[iPosMorse] = ' ';
            iPosMorse++;
            nLettersEntred++;
        }
    }
    morse[iPosMorse-1] = '\0'; // remove last space
    if (strcmp(morseLetter, ".......") == 0) {
        memcpy(morse, ".......\0", 8); // exit code
    }
}