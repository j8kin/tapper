#include <stdio.h>
#include <unistd.h>
#include <wiringPi.h>
#include "WpioGpio.h"
#include "readTapper.h"

int main() {
    printf("Amina's tapper simulator. RaspberryPi\n");
    wiringPiSetup () ;

    pinMode(GPIO17, OUTPUT);
    pinMode(GPIO27, INPUT);
    pinMode(GPIO22, INPUT);
    
    int i = 0;
    int j = 0;
    char morseLetter[256] ="\0";
    int cSymbol = 0;;
    while(1) {
        if (j == 5) {
            digitalWrite(GPIO17, HIGH); // delay(500);
        }
        if (j==10) {
            digitalWrite(GPIO17, LOW); // delay(500);
            j = -1;
        }
        ++j;

        int curDotKeyPressed = digitalRead(GPIO27);
        int curDashKeyPressed = digitalRead(GPIO22);

        if (curDotKeyPressed == 1) {
            // printf("\nDot Key down\n");
            ++i;
        }
        else {
            if (i>0) {
                // printf("Dot Key down for %d sec\n", i/10);
                // printf(".");
                morseLetter[cSymbol++]='.';
                morseLetter[cSymbol]='\0';
                i = 0;
            }
        }

        if (curDashKeyPressed == 1) {
            // printf("\Dash Key down\n");
            ++i;
        }
        else {
            if (i>0) {
                // printf("Dash Key down for %d sec\n", i/10);
                // printf("-");
                morseLetter[cSymbol++]='-';
                morseLetter[cSymbol]='\0';

                i = 0;
            }
        }

        if (cSymbol > 5) {
            printf("%s\n", morseLetter);
            cSymbol = 0;
            morseLetter[cSymbol]='\0';
        }
        delay(100); // 10Hz
    }

    return 0;
}