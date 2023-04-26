#include "main.h"

int whitespaces(const char *format, int *i);

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
	va_list args, args_copy;
	flags_t flags = {0};
	int (*pfn)(va_list, int);
	int i = 0, j, printed = 0, num, field_width;

	if (!format)
		return (-1);
	va_start(args, format);
	va_copy(args_copy, args);
	for (; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[++i] == '\0')
				return (-1);
			/* flag handler */
			num = va_arg(args_copy, long);
			parse_flags(format, &flags, num, &printed, &i);
			/* handle field width */
			if (_isdigit(format[i]))
			{
				field_width = format[i] - '0';
				for (j = i + 1; _isdigit(format[j]); j++)
					field_width = field_width * 10 + (format[j] - '0');
				i = j;
			}
			if (!whitespaces(format, &i))
				return (-1);
			pfn = get_print(&format[i]);
			/* for invalid formats: print as is */
			printed += pfn
					? pfn(args, field_width)
					: _putchar('%') + _putchar(format[i]);
		}
		else
			printed += _putchar(format[i]);
	}
	va_end(args);
	va_end(args_copy);
	return (printed);
}

/**
 * whitespaces - Skip whitespaces in a string
 * @format: The string to be evaluated
 * @i: Pointer to the index of the character being evaluated
 * Return: 1 if valid specifer, 0 otherwise
 */
int whitespaces(const char *format, int *i)
{
	for (; format[*i] == ' '; (*i)++)
		if (format[*i + 1] == '\0')
			return (0);
	if (format[*i] == ' ')
		(*i)++;
	return (1);
}
