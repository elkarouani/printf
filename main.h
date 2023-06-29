#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

int _printf(const char *format, ...);
int _printf_with_spec(va_list argv, char conversion_spec);
int _printf_int(int n);
int _printf_uint(unsigned int n);
int _printf_octal(unsigned int n);
int _printf_hex(unsigned long int n, short int u);
int _printf_binary(unsigned int n);
int _putchar(char c);
int _putstr(char *s);
int _putptr(unsigned long int p);

#endif
