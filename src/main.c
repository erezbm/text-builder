#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "utils.h"
#include "buildtext.h"

int main(int argc, char *argv[]) {
	srand(time(NULL));
	int opt;
	while ((opt = getopt(argc, argv, "ulRra:p:")) != -1)
		if (opt == '?')	return 1;

	char *line = NULL;
	size_t len = 0;
	while (read_line(&line, &len) != NULL) {
		char *built_text = build_text(line, argc, argv);
		puts(built_text);
		free(built_text);
	}

	free(line);
	return 0;
}

