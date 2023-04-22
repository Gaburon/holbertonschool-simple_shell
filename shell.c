int main(void)
{
	char buffer[1024];
	int error_code;
	size_t length;

	while (1) {
		printf("$ "); /* Prompt */
		length = read(STDIN_FILENO, buffer, sizeof(buffer));
		if (length == -1) {
			perror("read");
			return (EXIT_FAILURE);
		}
		if (length == 0) {
			printf("\n");
			return (EXIT_SUCCESS);
		}
		buffer[length - 1] = '\0';
		char *args[] = { buffer, NULL };
		error_code = execve(buffer, args, NULL);
		if (error_code == -1) {
			perror("execve");
			return (EXIT_FAILURE);
		}
	}
}
