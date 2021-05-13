#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "builders.h"

char *build_text(char *input, int argc, char *argv[]) {
	char *text = malloc(sizeof(char[strlen(input) + 1]));
	strcpy(text, input);

	int opt;
	optind = 1;
	while ((opt = getopt(argc, argv, "ulr")) != -1) {
		switch (opt) {
			case 'u': uppercase(&text); break;
			case 'l': lowercase(&text); break;
			case 'r': reverse(&text); break;
			default: free(text); return NULL;
		}
	}

	return text; 
}

