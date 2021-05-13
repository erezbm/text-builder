#include <stdio.h>
#include <stdlib.h>

#include "utils.h"
#include "buildtext.h"

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

