#include "main.h"

/**
 * print_char - prints a character from a va_list arg.
 * @list: va_list arg.
 * Return: count of characters printed.
 */

int print_char(va_list list)
{
	_putchar(va_arg(list, int));
	return (1);
}

/**
 * print_str - prints a string from a va_list.
 * @list: the va_list containing the string to be printed.
 * Return: count of characters printed.
 */

int print_str(va_list list)
{
	int i = 0;
	char *str;

	str = va_arg(list, char *);
	if (!str)
		str = "(null)";

	for (; str[i]; i++)
		_putchar(str[i]);

	return (i);
}

/**
 * print_perc - prints a percent sign.
 * @list: list of arguments (unused).
 * Return: count of characters printed.
 */

int print_perc(va_list list)
{
	(void)(list);
	_putchar('%');
	return (1);
}
