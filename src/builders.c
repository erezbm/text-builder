#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char *uppercase(char *input) {
        size_t len = strlen(input);
        char *output = malloc(sizeof(char[len + 1]));
        for (int i = 0; i <= len; i++)
                output[i] = toupper(input[i]);
	free(input);
        return output;
}

char *lowercase(char *input) {
        size_t len = strlen(input);
        char *output = malloc(sizeof(char[len + 1]));
        for (int i = 0; i <= len; i++)
                output[i] = tolower(input[i]);
	free(input);
        return output;
}

char *reverse(char *input) {
	size_t len = strlen(input);
        char *output = malloc(sizeof(char[len + 1]));
        for (int i = 0, j = len - 1; i < len; i++, j--)
                output[j] = input[i];
	free(input);
	output[len] = '\0';
        return output;
}

