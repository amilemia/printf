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
	int i = 0, printed = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	for (; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			/* if the string ends with a %, returns -1 */
			if (format[i + 1] == '\0')
				return (-1);
			/* skip spaces between the % and the format specifier ex: "%  s" */
			while (format[i + 1] == ' ')
			{
				if (format[i + 2] == '\0')
					return (-1);
				i++;
			}
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
