#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "utils.h"
#include "builders.h"

char *build_text(char *input, int argc, char **argv) {
	char *text = malloc(sizeof(char[strlen(input) + 1]));
	strcpy(text, input);

	int opt;
	optind = 1;
	while ((opt = getopt(argc, argv, "ulr")) != -1) {
		switch (opt) {
			case 'u': text = uppercase(text); break;
			case 'l': text = lowercase(text); break;
			case 'r': text = reverse(text); break;
			default: free(text); return NULL;
		}
	}

	return text; 
}

int main(int argc, char **argv) {
	char *line = NULL;
	size_t len = 0;

	while (read_line(&line, &len) != NULL) {
		char *built_text = build_text(line, argc, argv);
		if (built_text == NULL) { free(line); return 1; }

		puts(built_text);
		free(built_text);
	}

	free(line);
	return 0;
}

