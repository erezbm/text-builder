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

void randomcase(char **input) {
	char *input_val = *input;
	size_t len = strlen(input_val);
	for (int i = 0; i < len; i++)
		input_val[i] = rand() % 2 == 0
		       ? toupper(input_val[i])
		       : tolower(input_val[i]);
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

void append(char **input, char *postfix) {
	size_t new_size = sizeof(char[strlen(*input) + strlen(postfix) + 1]);
	*input = realloc(*input, new_size);
	strcat(*input, postfix);
}

void prepend(char **input, char *prefix) {
	size_t input_size = sizeof(char[strlen(*input) + 1]);
	size_t prefix_len = strlen(prefix);
	*input = realloc(*input, sizeof(char[prefix_len]) + input_size);

	memmove(*input + prefix_len, *input, input_size);
	memcpy(*input, prefix, sizeof(char[prefix_len]));
}

void repeat(char **input, int times) {
	if (times < 0) times = 0;
	size_t input_len = strlen(*input);
	size_t input_size = sizeof(char[input_len]);
	*input = realloc(*input, input_size * times + sizeof(char));

	for (int i = 1; i < times; i++)
		memcpy(*input + (i * input_len), *input, input_size);
	(*input)[times * input_len] = '\0';
}

