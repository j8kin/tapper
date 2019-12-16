#include <stdio.h>
#include <unistd.h>
#include <wiringPi.h>

int main() {
    printf("Amina's tapper simulator. RaspberryPi\n");
    wiringPiSetup () ;

    pinMode (12, INPUT) ;
    
    // int i = 0;
    while(1) {
        int curDotKeyPressed = digitalRead(12);
        if (curDotKeyPressed == 1) {
            printf("\nDot Key down\n");
        }
        
        // ++i;
        // if (i == 10) {
        //     printf(".");
        //     i = 0;
        // }
        usleep(100); // 10Hz
    }
}