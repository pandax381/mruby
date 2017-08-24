#ifndef _SETJMP_H
#define _SETJMP_H

#define JMP_BUF_SIZE 6

typedef struct {
    unsigned long __jmp_buf[JMP_BUF_SIZE];
} jmp_buf[1];

#define _setjmp(env) __builtin_setjmp((void **)env)
#define _longjmp(env, val) __builtin_longjmp((void **)env, val)

#define setjmp(env) __builtin_setjmp(env)
#define longjmp(env, val) __builtin_longjmp(env, val)

#endif
