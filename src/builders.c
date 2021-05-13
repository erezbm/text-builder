#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void uppercase(char **input) {
	char *input_val = *input;
	size_t len = strlen(input_val);
	for (int i = 0; i < len; i++)
		input_val[i] = toupper(input_val[i]);
}

void lowercase(char **input) {
	char *input_val = *input;
	size_t len = strlen(input_val);
	for (int i = 0; i < len; i++)
		input_val[i] = tolower(input_val[i]);
}

void reverse(char **input) {
	char *input_val = *input;
	size_t len = strlen(input_val);
	for (int i = 0, j = len - 1; i < j; i++, j--) {
		char temp = input_val[i];
		input_val[i] = input_val[j];
		input_val[j] = temp;
	}
}

