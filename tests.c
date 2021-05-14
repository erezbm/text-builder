#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "src/builders.h"

#define TEST_BUILDER(builder, expected, input) {\
	char *text = strdup(input);\
	builder(&text);\
	exit_status |= expect_str(expected, text, #builder ":");\
	free(text);\
}

#define TEST_BUILDER_WITH_ARGS(builder, expected, input, ...) {\
	char *text = strdup(input);\
	builder(&text, __VA_ARGS__);\
	exit_status |= expect_str(expected, text, #builder ":");\
	free(text);\
}

int expect_str(char *expected, char *actual, char *fail_message) {
	if (strcmp(actual, expected) != 0) {
		puts(fail_message);
		printf("expected = %s\n", expected);
		printf("actual   = %s\n", actual);
		return 1;
	}
	return 0;
}

int main() {
	int exit_status = 0;

	/* Builders Tests */
	TEST_BUILDER(uppercase, "1AAAA1", "1aAaA1");
	TEST_BUILDER(lowercase, "1aaaa1", "1aAaA1");
	TEST_BUILDER(randomcase, "1234;,[", "1234;,[");
	TEST_BUILDER(reverse, "1AaAa1", "1aAaA1");
	TEST_BUILDER_WITH_ARGS(append, "hello world", "hello", " world");
	TEST_BUILDER_WITH_ARGS(prepend, "hello world", "world", "hello ");

	if (exit_status == 0)
		puts("All tests succeeded");

	return exit_status;
}

