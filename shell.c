##include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(void)
{
	char buffer[BUFFER_SIZE];
	size_t length;
	int error_code;

	while (1) {
		printf("$ "); /* Prompt */
		length = read(STDIN_FILENO, buffer, sizeof(buffer));

		if (length == 0) {
			exit(EXIT_SUCCESS);
		}

		if (buffer[length - 1] == '\n') {
			buffer[length - 1] = '\0';
		}

		error_code = execve(buffer, (char *const[]) { buffer, NULL }, NULL);
		if (error_code == -1) {
			perror("Error executing command");
		}
	}
