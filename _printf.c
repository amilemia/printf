#include "main.h"

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
	va_list args;
	int (*pfn)(va_list);
	int i = 0, j = 0, printed = 0;
	int field_width = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	for (; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			/* handle field width */
			if (_isdigit(format[i + 1]))
			{
				field_width = format[i + 1] - '0';
				for (j = i + 2; _isdigit(format[j]); j++)
					field_width = field_width * 10 + (format[j] - '0');
				i = j - 1;
			}
			/* if the string ends with a %, returns -1 */
			if (format[i + 1] == '\0')
				return (-1);
			/* skip spaces between the % and the format specifier ex: "%  s" */
			for (; format[i + 1] == ' '; i++)
				if (format[i + 2] == '\0')
					return (-1);

			pfn = get_print(&format[++i]);
			/* for invalid formats: print as is */
			printed += pfn ? pfn(args) : _putchar('%') + _putchar(format[i]);
		}
		else
			printed += _putchar(format[i]);
	}

	va_end(args);
	return (printed);
}
