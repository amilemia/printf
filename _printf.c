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
			/*  */
			pfn = get_print(&format[++i]);
			printed += pfn(args);
		}
		else
			printed += _putchar(format[i]);
	}

	va_end(args);
	return (printed);
}
