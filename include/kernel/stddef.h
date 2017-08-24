#ifndef _STDDEF_H
#define _STDDEF_H

#ifndef NULL
#define NULL (0)
#endif

typedef long ssize_t;
typedef unsigned long size_t;

#define __PTRDIFF_TYPE__ long int
typedef __PTRDIFF_TYPE__ ptrdiff_t;

#endif
