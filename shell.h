#ifndef SHELL_H
#define SHELL_H
#define _GNU_SOURCE

/* libraries */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

/* macros */

#define CHECK_ISATTY_OUT \
	do {\
	if (isatty(0) == 0)\
		break;\
	} while (0)

#define CHECK_ISATTY_PROMPT(PROMPT, LEN) \
	do {\
	if (isatty(0) == 1)\
		write(STDOUT_FILENO, (PROMPT), (LEN));\
	} while (0)

#define FREE_RESOURCES_ON_ERROR(LINE, ARGV_START, ARGV_ZERO, ARGV, ERRORLINE) \
		do {\
		write(STDERR_FILENO, ERRORLINE, _strlen(ERRORLINE));\
		free(ERRORLINE);\
		if (ARGV_START == 1)\
			free(ARGV_ZERO);\
		free(ARGV);\
		free(LINE);\
		} while (0)

#define FREE_RESOURCES_AND_EXIT(LINE, ARGV, ERRORLINE) \
		do {\
		free(LINE);\
		free(ARGV);\
		free(ERRORLINE);\
		exit(EXIT_FAILURE);\
		} while (0)

#define CHECK_ISATTY_RESULT(N)\
		do {\
		if (isatty(0) != (N))\
			break;\
		} while (0)

/* functions */

int init_shell(char *prompt, char *error, size_t aux);
int linetoargv(char *line, char **argv, ssize_t linelen);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int count_words(char *s);
void *_calloc(unsigned int nmemb, unsigned int size);
void env_builtin(void);
extern char **environ;

#endif
