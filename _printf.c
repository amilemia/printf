#include "main.h"

int valid_precentage(const char *format, int *i);

/**
 * _printf - prints a formatted string to stdout, similar to printf.
 * @format: the format of the string to be printed.
 *
 * This function prints a formatted string to the stdout stream. It
 * accepts a format string as its first argument and any additional arguments
 * will be used to replace format specifiers in the format string. The function
 *
 * Return: the number of characters printed to the stdout stream.
 */
int _printf(const char *format, ...)
{
	va_list args, args_flags, args_width;
	flags_t flags = {0};
	width_t width = {0};
	int (*pfn)(va_list);
	int i = 0, printed = 0;

	if (!format)
		return (-1);
	va_start(args, format);
	(va_copy(args_flags, args), va_copy(args_width, args));
	for (; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (!valid_precentage(format, &i))
				return (-1);
			/* get conversion_index by getting [flags, width..] first */
			pfn = get_conversion(format, &i, args, &flags, &width);

			parse_flags(&flags, args_flags, pfn, &printed);
			parse_width(&width, args_width, pfn, &printed);
			parse_length(&flags, args, pfn, &printed);

			/* TODO: check length outside this func*/
			if (flags.h || flags.l)
				continue;
			/* for valid conversion call print_func, otherwise print as is*/
			printed += pfn
						   ? pfn(args)
						   : _putchar('%') + _putchar(format[i]);
		}
		else
			printed += _putchar(format[i]);
	}
	va_end(args);
	(va_end(args_flags), va_end(args_width));
	return (printed);
}

/**
 * valid_precentage - Self explain
 * @format: The string to be evaluated
 * @i: Pointer to the index of the character being evaluated
 * Return: 1 if valid specifer, 0 otherwise
 */
int valid_precentage(const char *format, int *i)
{
	int j;

	if (format[++(*i)] == '\0')
		return (0);
	j = *i;

	/* check if no caractere after '%', return false */
	for (; format[j] == ' '; j++)
	{
		if (format[*i + 1] == '\0')
			return (0);
		else if (format[*i + 1] == ' ')
			(*i)++;
		else
			break;
	}
	/* ignore extra valid_precentage between '%' and 'specefier' */
	return (1);
}
