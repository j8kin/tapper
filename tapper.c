#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <wiringPi.h>
#include "WpioGpio.h"
#include "readTapper.h"
#include "morse.h"

int main() {
    char morseBuffer[100];

    printf("Amina's tapper simulator. RaspberryPi\n");
    
    wiringPiSetup () ;

    pinMode(GPIO17, OUTPUT);
    pinMode(GPIO27, INPUT);
    pinMode(GPIO22, INPUT);

    printf("Enter difficulty level (one dot level 1, 4 dots - level 4): \n");
    do {
        readTapper(GPIO27,GPIO22, morseBuffer);
    } while ((strcmp(morseBuffer, ".") != 0) && 
             (strcmp(morseBuffer, "..") != 0) &&
             (strcmp(morseBuffer, "...") != 0) &&
             (strcmp(morseBuffer, "....") != 0));

    int difficultyLevel = strlen(morseBuffer);
    printf("Your choice is %d\n", difficultyLevel);
    int exit = 0;
    int i=0;
    char wordToType[15];
    char correctMorse[100];

    while(!exit) {
        if (i == 0) {
            printf("To exit press dot 7 times\n");
        }
        morseWordToType(difficultyLevel, wordToType, correctMorse);
        printf("Tapper in Morse code: %s", wordToType);
        if (difficultyLevel == 1 || difficultyLevel == 3) {
            printf(" (%s)\n", correctMorse);
        }
        else {
            printf("\n");
        }
        do {
            readTapper(GPIO27,GPIO22, morseBuffer);
        } while (strlen(morseBuffer) == 0);
        
        if (strcmp(morseBuffer,".......")==0) {
            exit = 1;
        }
        else {
            if (strcmp(correctMorse, morseBuffer) == 0) {
                printf("CORRECT!\n");
            }
            else {
                printf("Incorrect. You type: %s instead of: %s\nTry one more time.\n", morseBuffer, correctMorse);
            }
        }
        i++;
    }
    printf("Thanks for using Amina's Morse tapper simulator!\n");
    
    return 0;
}