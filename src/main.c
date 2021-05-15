#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#include "utils.h"
#include "buildtext.h"

void print_usage(char *name) {
	printf("Usage: %s [-ulrR] [-a postfix] [-p prefix] [-m count]\n", name);
}

void print_options() {
	puts("  -u uppercase the input");
	puts("  -l lowercase the input");
	puts("  -r reverse the input");
	puts("  -R randomcase the input");
	puts("  -a append <postfix> at the end of the input");
	puts("  -p prepend <prefix> at the start of the input");
	puts("  -m repeat the input <count> times (negative <count> means 0)");
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

