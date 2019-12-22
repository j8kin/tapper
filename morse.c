#include <stdlib.h>
#include "morseConverters.h"

const char* const morseDict[] = { 
	"apple", "one", "two", "at", "word", "four", "five"
};
const int sizeOfMorseDict = 7;

void morseWordToType(int dificultyLevel, char *wordToType, char* expectMorse) {
	int index = 0;
	if (dificultyLevel == 1 || dificultyLevel == 2) {
		index = (int)(((double)rand() / RAND_MAX) * 35);
		if (index <= 25) {
			wordToType[0] = (char)('a' + index);
		}
		else {
			wordToType[0] = (char)('0' + index-26);
		}
		wordToType[1] = '\0';
	}
	else {
		index = (int)(((double)rand() / RAND_MAX) * sizeOfMorseDict);
		int i = 0;
		while (morseDict[index][i] != '\0') {
			wordToType[i] = morseDict[index][i];
			i++;
		}
		wordToType[i] = '\0';
	}

	toMorse(wordToType, expectMorse);
}