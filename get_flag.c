#include "main.h"

/**
 * parse_flags - parses flags in a format string
 * @format: the format string
 * @flags: pointer to a flags_t struct
 * @num:  passed number in  va_list args
 * @printed: pointer to the count of characters printed
 * @i: pointer to the index of the format string
 *
 * This function parses flags in a format string and updates the flags_t struct
 * accordingly. It also handles the (+), (space), (#) flags.
 */
void parse_flags(const char *format, flags_t *flags,
				 int num, int *printed, int *i)
{
	int (*pfn)(va_list, int);

	for (flags->j = *i; format[flags->j]; flags->j++)
	{
		if (format[flags->j] == '+')
			flags->plus = 1;
		else if (format[flags->j] == '#')
			flags->hash = 1;
		else if (format[flags->j] == ' ')
		{
			/* if after % more than one space, return */
			if (format[flags->j + 1] == ' ')
				return;
			flags->space = 1;
		}
		else
			break;
	}
	*i = flags->j;

	if (flags->plus && flags->space)
		flags->space = 0;
	/* handle flag: (+) and (space) */
	if (flags->plus && num >= 0)
		*printed += _putchar('+');
	else if (flags->space && num >= 0)
		*printed += _putchar(' ');
	/* handle flag: (#) */
	if (flags->hash)
	{
		pfn = get_print(&format[*i]);
		if (pfn == print_octal)
			*printed += _putchar('0');
		else if (pfn == print_hex)
			*printed += _puts("0x");
		else if (pfn == print_HEX)
			*printed += _puts("0X");
	}
}
