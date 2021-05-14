#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "src/builders.h"

#define TEST_BUILDER(builder, input, expected) {\
	char *text = strdup(input);\
	builder(&text);\
	if (strcmp(text, expected) != 0) {\
		printf(#builder "\n");\
		printf("actual   = %s\n", text);\
		printf("expected = %s\n", expected);\
		exit_status = 1;\
	}\
	free(text);\
}

int main() {
	int exit_status = 0;

	/* Builders Tests */
	TEST_BUILDER(uppercase, "1aAaA1", "1AAAA1");
	TEST_BUILDER(lowercase, "1aAaA1", "1aaaa1");
	TEST_BUILDER(reverse, "1aAaA1", "1AaAa1");

	if (exit_status == 0)
		puts("All tests succeeded");

	return exit_status;
}

