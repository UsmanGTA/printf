#ifndef _HOLBERTON_H
#define _HOLBERTON_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

/**
 * struct num_s - struct that stores number formatting configurations
 * @spec: format specifier
 * @power: exp value associated with @c. determines function behavior
 * @hex_char: assists in printing chars for hex bases. 0 for other bases
 */
typedef struct num_s
{
	char spec;
	int power;
	int hex_char;
} num_t;

/**
 * struct config_s - struct that stores print format configuration settings
 * @spec: format specifier code
 * @len: if 1, print arg as a long int
 * @minus: if 1, print arg right-aligned
 * @plus: if 1, print the '+' sign before a number arg
 * @space: if 1, print placeholder chars with spaces
 * @zero: if 1, print placeholder chars with zeroes
 * @hash: if 1, print non-base 10 digits with prefixes
 * @width: minimum number of chars to print
 * @precision: maximum number of chars to print
 * @str: if the argument is a string, it is stored here
 * @arg: if the argument is anything else, it is stored here
 */
typedef struct config_s
{
	int spec;
	int len;
	int minus;
	int plus;
	int space;
	int zero;
	int hash;
	int width;
	int precision;
	char *str;
	unsigned long int arg;
} format;

int _printf(const char *format, ...);
void getprinter(const char **, char **, va_list);
format format_config(const char **);
num_t *num_config(char c);
char *p_c(format settings, va_list list);
char *p_s(format);
char *p_num(format);
char *p_uidc(format);
size_t _strlen(char *s);
unsigned long int get_max(int spec, int len);

#endif
