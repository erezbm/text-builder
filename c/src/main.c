#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "utils.h"
#include "buildtext.h"

void print_usage(char *name) {
	printf("Usage: %s [-u | -l | -r | -R | -a POSTFIX | -p PREFIX | -m COUNT]...\n", name);
}

void print_options() {
	puts("Available options:");
	puts("  -u Uppercase the input");
	puts("  -l Lowercase the input");
	puts("  -r Reverse the input");
	puts("  -R Randomcase the input");
	puts("  -a Append POSTFIX at the end of the input");
	puts("  -p Prepend PREFIX at the start of the input");
	puts("  -m Repeat the input COUNT times (negative COUNT means 0)");
	puts("  -h Show this help text");
}

int main(int argc, char *argv[]) {
	srand(time(NULL));
	opterr = 0;
	int opt;
	while ((opt = getopt(argc, argv, "ulRra:p:m:")) != -1) {
		if (opt == '?')	{
			print_usage(argv[0]);
			if (optopt == 'h')
				print_options();
			return optopt != 'h';
		}
	}

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

