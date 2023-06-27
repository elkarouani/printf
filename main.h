#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <limits.h>

int _printf(const char *format, ...);
int _printf_with_spec(va_list argv, char conversion_spec);
void _printf_int(int n);
void _printf_uint(unsigned int n);
void _printf_octal(unsigned int n);
void _printf_hex(unsigned long int n, short int u);
int _putchar(char c);
void _putstr(char *s);
void _putptr(unsigned long int p);

#endif
