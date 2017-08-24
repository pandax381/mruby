#ifndef _STRING_H
#define _STRING_H

#include <stddef.h>

inline void *
memcpy (void *dst, const void *src, size_t n) {
  char *d = (char *)dst;
  char *s = (char *)src;
  while (n--) {
      *d++ = *s++;
  }
  return dst;
}

inline size_t
strlen (const char *s) {
  const char *_s = s;
  while (*_s)
    _s++;
  return _s - s;
}

inline int
strcmp(const char *s1, const char *s2) {
  while (*s1 != '\0' && *s1 == *s2) {
    s1++;
    s2++;
  }
  return (*(unsigned char *)s1) - (*(unsigned char *)s2);
}

inline void *
memchr (const void *s, int c, size_t n) {
  const unsigned char *_s = (const unsigned char *) s;
  while (n--) {
    if (*_s == (unsigned char)c)
      return (void *) _s;
    _s++;
  }
  return NULL;
}

inline int
memcmp (const void *s1, const void *s2, size_t n) {
  unsigned char *_s1 = (unsigned char *)s1;
  unsigned char *_s2 = (unsigned char *)s2;
  while (n--) {
    if (*_s1 != *_s2)
      return *_s1 - *_s2;
    _s1++;
    _s2++;
  }
  return 0;
}

inline void *
memmove(void *dst, const void *src, size_t len) {
  char *d = (char *)dst;
  const char *s = (const char *)src;

  if (s < d && d < s + len) {
    /* Have to copy backwards */
    s += len;
    d += len;
    while (len--)
      *--d = *--s;
  } else {
    while (len--)
      *d++ = *s++;
  }
  return dst;
}

inline void *
memset(void *b, int c, size_t len) {
  char *_b = (char *)b;
  while (len--)
    *_b++ = (char)c;
  return b;
}

#endif
