#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct fmt - Struct for formatting data.
 * @sym: *sym: Pointer to a character string.
 * @fn: func pointer to a function that takes a va_list as an arg.
 */
typedef struct fmt
{
	char *sym;
	int (*fn)(va_list);
} fmt_t;

/* main */
int _printf(const char *format, ...);

/* print handler */
int (*get_print(const char *format))(va_list);

/* print_chars */
int print_char(va_list list);
int print_str(va_list list);
int print_perc(va_list list);

/* print_numbers */
int print_int(va_list list);
int print_unsigned(va_list list);

/* print_bases */
int print_binary(va_list list);
int print_octal(va_list list);
int print_hex(va_list list);
int print_HEX(va_list list);
int print_addrs(va_list list);

/* print_customs */
int print_STR(va_list list);
int print_rev(va_list list);

/* utilities */
unsigned int _strlen(char *s);
void reverse_str(char s[]);
void _itoa(long n, char s[]);
int to_base_n(unsigned long num, int base, char s[]);
int _isdigit(int c);

/* writes */
int _putchar(char c);
int _puts(char *str);

#endif
