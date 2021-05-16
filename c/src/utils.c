#include <stdio.h>

char *read_line(char **line, size_t *len) {
	ssize_t nread = getline(line, len, stdin);
	if (nread == -1) return NULL;

	if ((*line)[nread - 1] == '\n') (*line)[nread - 1] = '\0';
	return *line;
}

