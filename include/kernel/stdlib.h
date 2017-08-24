#ifndef _STDLIB_H
#define _STDLIB_H

#include <stddef.h>

#define EXIT_SUCCESS (0)
#define EXIT_FAILURE (-1)

void free(void *ptr);
void *realloc(void *ptr, size_t size);
int abs(int j);
unsigned long int strtoul(const char *nptr, char **endptr, int base);
void exit(int status);
void abort(void);

#endif
