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
	va_list args, args_copy;
	flags_t flags = {0};
	int (*pfn)(va_list);
	int i = 0, j, printed = 0, num, field_width;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	va_start(args, format);
	va_copy(args_copy, args);
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
			num = va_arg(args_copy, long);
			parse_flags(format, &flags, num, &printed, &i);
			pfn = get_print(&format[++i]);
			/* for invalid formats: print as is */
			printed += pfn ? pfn(args) : _putchar('%') + _putchar(format[i]);
		}
		else
			printed += _putchar(format[i]);
	}
	va_end(args);
	va_end(args_copy);
	return (printed);
}
