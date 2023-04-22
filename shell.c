#include <stdio.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int main(void)
{
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read;
	int error_code;

	while (1) {
		printf("$ ");  // Prompt
		bytes_read = read(STDIN_FILENO, buffer, BUFFER_SIZE);

		if (bytes_read == 0) {
			// EOF (Ctrl+D)
			printf("\n");
			break;
		} else if (bytes_read == -1) {
			// Error
			perror("read");
			continue;
		}

		// Remove trailing newline character
		if (buffer[bytes_read - 1] == '\n') {
			buffer[bytes_read - 1] = '\0';
		}

		// Execute command
		error_code = execve(buffer, (char *const[]) { buffer, NULL }, NULL);
		if (error_code == -1) {
			perror("execve");
		}
	}

	return 0;
}
