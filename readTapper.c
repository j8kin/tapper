#include <sys/time.h>
#include <wiringPi.h>
#include "readTapper.h"

#define NULL 0L

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
        }
        if (curDashKeyPressed == 1) {
            prevTime = curTime;
            morse[i++] = '-';
        }
        if (curTime - prevTime > 2000) {
            execute = 0;
        }
        delay(100); // 10Hz
    }
    morse[i] ='\0';
}