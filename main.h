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

/**
 * struct flags - A structure for storing the status of different flag options.
 * @j: Integer that indicates the maximum number of characters to print.
 * @plus: Integer that represents the plus sign option.
 * @space: Integer that represents the space option.
 * @hash: Integer that represents the hash option.
 **/

typedef struct flags
{
	int j;
	int plus;
	int space;
	int hash;
	int l;
	int h;
} flags_t;

typedef struct width
{
	int value;
	int is_zero;
	int is_astreak;
} width_t;

/**
 * struct function_t - Holds a function pointer and its base value.
 * @base: The base value for the function.
 * @pfn: Pointer to the function.
 **/
typedef struct
{
	int base;
	int (*pfn)(va_list);
} function_t;

/* main */
int _printf(const char *format, ...);

/* getters */
typedef int (*pfn_t)(va_list);
void get_flags(const char *format, flags_t *flags, int *i);
void get_width(const char *format, width_t *width, int *i);
void get_length(const char *format, flags_t *flags, int *i);
pfn_t get_print(const char *format);
pfn_t get_conversion(const char *format, int *i, va_list args,
					 flags_t *flags, width_t *width);

/* handlers */
void parse_flags(flags_t *flags, va_list args_flags,
				 pfn_t pfn, int *printed);
void parse_width(width_t *width, va_list args_width,
				 pfn_t pfn, int *printed);
void parse_length(flags_t *flags, va_list args_flags,
				  pfn_t pfn, int *printed);

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
int print_rot13(va_list list);

/* utilities */
unsigned int _strlen(char *s);
void reverse_str(char s[]);
void _itoa(long n, char s[]);
int to_base_n(unsigned long num, int base, char s[]);
int num_len_base(long num, int base);

/* writes */
int _putchar(char c);
int _puts(char *str);

#endif
