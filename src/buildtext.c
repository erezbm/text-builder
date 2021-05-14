#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "builders.h"

char *build_text(char *input, int argc, char *argv[]) {
	char *text = malloc(sizeof(char[strlen(input) + 1]));
	strcpy(text, input);

	int opt;
	optind = 1;
	while ((opt = getopt(argc, argv, "ulRra:p:")) != -1) {
		switch (opt) {
			case 'u': uppercase (&text); break;
			case 'l': lowercase (&text); break;
			case 'R': randomcase(&text); break;
			case 'r': reverse   (&text); break;
			case 'a': append    (&text, optarg); break;
			case 'p': prepend   (&text, optarg); break;
		}
	}

	return text; 
}

