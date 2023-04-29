#include "main.h"

/**
 * get_flags - Get the flags from a format string
 * @format: The format string
 * @flags: Pointer to a flags_t struct containing any flags found
 * @i: Pointer to the current index in the format string
 */
void get_flags(const char *format, flags_t *flags, int *i)
{
	for (flags->j = *i; format[flags->j]; flags->j++)
	{
		if (format[flags->j] == '+')
			flags->plus = 1;
		else if (format[flags->j] == '#')
			flags->hash = 1;
		else if (format[flags->j] == ' ')
		{
			if (format[flags->j + 1] == '%')
				(*i)++;
			else
				flags->space = 1;
		}
		else
			break;
	}
	*i = flags->j;
}

/**
 * parse_flags - parses flags for printing
 * @flags: pointer to a flags_t struct containing the flags found
 * @args_flags: va_list of arguments
 * @pfn: pointer to returned func from get_print()
 * @printed: pointer to the count of characters printed
 */
void parse_flags(flags_t *flags, va_list args_flags,
				 pfn_t pfn, int *printed)
{
	int num;
	unsigned long l_unum;

	if (pfn == print_int)
		num = va_arg(args_flags, long);
	else
		l_unum = va_arg(args_flags, long);

	if (flags->plus && flags->space)
		flags->space = 0;
	/* handle flag: (+) and (space) */
	if (flags->plus && num >= 0)
		*printed += _putchar('+');
	else if (flags->space && num >= 0 && pfn == print_int)
		*printed += _putchar(' ');
	/* handle flag: (#) */
	if (flags->hash)
	{
		if (pfn == print_octal && l_unum > 0)
			*printed += _putchar('0');
		else if (pfn == print_hex && l_unum > 0)
			*printed += _puts("0x");
		else if (pfn == print_HEX && l_unum > 0)
			*printed += _puts("0X");
	}
}
