#include <string.h>
#include "morseConverters.h"

char fromMorseLetter(const char* morseLetter) {
	if (strcmp(morseLetter, ".-")) {
		return 'a';
	}
	if (strcmp(morseLetter, "-...")) {
		return 'b';
	}
	if (strcmp(morseLetter, "-.-.")) {
		return 'c';
	}
	if (strcmp(morseLetter, "-..")) {
		return 'd';
	}
	if (strcmp(morseLetter, ".")) {
		return 'e';
	}
	if (strcmp(morseLetter, "..-.")) {
		return 'f';
	}
	if (strcmp(morseLetter, "--.")) {
		return 'g';
	}
	if (strcmp(morseLetter, "....")) {
		return 'h';
	}
	if (strcmp(morseLetter, "..")) {
		return 'i';
	}
	if (strcmp(morseLetter, ".---")) {
		return 'j';
	}
	if (strcmp(morseLetter, "-.-")) {
		return 'k';
	}
	if (strcmp(morseLetter, ".-..")) {
		return 'l';
	}
	if (strcmp(morseLetter, "--")) {
		return 'm';
	}
	if (strcmp(morseLetter, "-.")) {
		return 'n';
	}
	if (strcmp(morseLetter, "---")) {
		return 'o';
	}
	if (strcmp(morseLetter, ".--.")) {
		return 'p';
	}
	if (strcmp(morseLetter, "--.-")) {
		return 'q';
	}
	if (strcmp(morseLetter, ".-.")) {
		return 'r';
	}
	if (strcmp(morseLetter, "...")) {
		return 's';
	}
	if (strcmp(morseLetter, "-")) {
		return 't';
	}
	if (strcmp(morseLetter, "..-")) {
		return 'u';
	}
	if (strcmp(morseLetter, "...-")) {
		return 'v';
	}
	if (strcmp(morseLetter, ".--")) {
		return 'w';
	}
	if (strcmp(morseLetter, "-..-")) {
		return 'x';
	}
	if (strcmp(morseLetter, "-.--")) {
		return 'y';
	}
	if (strcmp(morseLetter, "--..")) {
		return 'z';
	}
	if (strcmp(morseLetter, ".----")) {
		return '1';
	}
	if (strcmp(morseLetter, "..---")) {
		return '2';
	}
	if (strcmp(morseLetter, "...--")) {
		return '3';
	}
	if (strcmp(morseLetter, "....-")) {
		return '4';
	}
	if (strcmp(morseLetter, ".....")) {
		return '5';
	}
	if (strcmp(morseLetter, "-....")) {
		return '6';
	}
	if (strcmp(morseLetter, "--...")) {
		return '7';
	}
	if (strcmp(morseLetter, "---..")) {
		return '8';
	}
	if (strcmp(morseLetter, "----.")) {
		return '9';
	}
	if (strcmp(morseLetter, "-----")) {
		return '0';
	}
	return ' ';
}

void toMorseLetter(const char symbol, char* morseLetter) {
	switch (symbol) {
	case 'a':
		memcpy(morseLetter, ".-",2);
		morseLetter[2] = '\0';
		break;
	case 'b':
		memcpy(morseLetter, "-...", 4);
		morseLetter[4] = '\0';
		break;
	case 'c':
		memcpy(morseLetter, "-.-.", 4);
		morseLetter[4] = '\0';
		break;
	case 'd':
		memcpy(morseLetter, "-..",3);
		morseLetter[3] = '\0';
		break;
	case 'e':
		memcpy(morseLetter, ".",1);
		morseLetter[1] = '\0';
		break;
	case 'f':
		memcpy(morseLetter, "..-.",4);
		morseLetter[4] = '\0';
		break;
	case 'g':
		memcpy(morseLetter, "--.",3);
		morseLetter[3] = '\0';
		break;
	case 'h':
		memcpy(morseLetter, "....",4);
		morseLetter[4] = '\0';
		break;
	case 'i':
		memcpy(morseLetter, "..",2);
		morseLetter[2] = '\0';
		break;
	case 'j':
		memcpy(morseLetter, ".---",4);
		morseLetter[4] = '\0';
		break;
	case 'k':
		memcpy(morseLetter, "-.-",3);
		morseLetter[3] = '\0';
		break;
	case 'l':
		memcpy(morseLetter, ".-..",4);
		morseLetter[4] = '\0';
		break;
	case 'm':
		memcpy(morseLetter, "--",2);
		morseLetter[2] = '\0';
		break;
	case 'n':
		memcpy(morseLetter, "-.",2);
		morseLetter[2] = '\0';
		break;
	case 'o':
		memcpy(morseLetter, "---",3);
		morseLetter[3] = '\0';
		break;
	case 'p':
		memcpy(morseLetter, ".--.",4);
		morseLetter[4] = '\0';
		break;
	case 'q':
		memcpy(morseLetter, "--.-",4);
		morseLetter[4] = '\0';
		break;
	case 'r':
		memcpy(morseLetter, ".-.",3);
		morseLetter[3] = '\0';
		break;
	case 's':
		memcpy(morseLetter, "...",3);
		morseLetter[3] = '\0';
		break;
	case 't':
		memcpy(morseLetter, "-",1);
		morseLetter[1] = '\0';
		break;
	case 'u':
		memcpy(morseLetter, "..-",3);
		morseLetter[3] = '\0';
		break;
	case 'v':
		memcpy(morseLetter, "...-",4);
		morseLetter[4] = '\0';
		break;
	case 'w':
		memcpy(morseLetter, ".--",3);
		morseLetter[3] = '\0';
		break;
	case 'x':
		memcpy(morseLetter, "-..-",4);
		morseLetter[4] = '\0';
		break;
	case 'y':
		memcpy(morseLetter, "-.--",4);
		morseLetter[4] = '\0';
		break;
	case 'z':
		memcpy(morseLetter, "--..",4);
		morseLetter[4] = '\0';
		break;
	case '1':
		memcpy(morseLetter, ".----",5);
		morseLetter[5] = '\0';
		break;
	case '2':
		memcpy(morseLetter, "..---",5);
		morseLetter[5] = '\0';
		break;
	case '3':
		memcpy(morseLetter, "...--",5);
		morseLetter[5] = '\0';
		break;
	case '4':
		memcpy(morseLetter, "....-",5);
		morseLetter[5] = '\0';
		break;
	case '5':
		memcpy(morseLetter, ".....",5);
		morseLetter[5] = '\0';
		break;
	case '6':
		memcpy(morseLetter, "-....",5);
		morseLetter[5] = '\0';
		break;
	case '7':
		memcpy(morseLetter, "--...",5);
		morseLetter[5] = '\0';
		break;
	case '8':
		memcpy(morseLetter, "---..",5);
		morseLetter[5] = '\0';
		break;
	case '9':
		memcpy(morseLetter, "----.",5);
		morseLetter[5] = '\0';
		break;
	case '0':
		memcpy(morseLetter, "-----",5);
		morseLetter[5] = '\0';
		break;

	default:
		morseLetter[0]='\0';
		break;
	}
}

int toMorse(char* input, char* output) {
	int i = 0;
	int j = 0;
	char morseLetter[100] = { '\0' };
	while (input[i] != '\0') {
		int k = 0;
		toMorseLetter(input[i], morseLetter);
		while (morseLetter[k] != '\0') {
			output[j] = morseLetter[k];
			k++;
			j++;
		}
		output[j] = ' ';
		j++;
		i++;
	}
	output[j-1] = '\0'; // replace last space with string end

	return j;
}

// morse input is like: '--- ... ----.' each letter separated from another with ' '
void fromMorse(char* input, char* output) {
	int i = 0;
	int j = 0;
	int k = 0;
	char morseLetter[10];
	
	while (input[i] != '\0') {
		j = 0;
		while (input[i] != ' ' || input[i] != '\0') {
			morseLetter[j] = input[i];
			i++;
			j++;
		}
		morseLetter[j] = '\0';
		output[k] = fromMorseLetter(morseLetter);
		i++;
		k++;
	}
	output[k] = '\0';
}