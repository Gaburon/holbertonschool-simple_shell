#include "shell.h"

/**
 * _calloc - allocates memory for an array, using malloc.
 * Return: pointer to the allocated memory, or NULL in fail
 */

void *_calloc(unsigned int nmemb, unsigned int size)
{
    char *ret;

    if (nmemb == 0 || size == 0)
        return NULL;

    ret = malloc(nmemb * size);
    if (ret == NULL)
        return NULL;

    memset(ret, 0, nmemb * size);

    return ret;
}
