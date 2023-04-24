#include "main.h"

/**
 * print_STR - prints non printable characters.
 * @list: the va_list containing the string to be printed.
 * Return: count of characters printed.
 */
int print_STR(va_list list)
{
	int i = 0, non_printable = 1, count = 0;
	char *str;
	char buffer[3];

	str = va_arg(list, char *);
	if (!str)
		str = "(null)";

	for (; str[i]; i++)
	{
		non_printable = (str[i] > 0 && str[i] < 32) || (str[i] >= 127);

		if (non_printable)
		{
			(str[i] < 16) ? (count += _puts("\\x0")) : (count += _puts("\\x"));
			/* pass 'A' to to_base_n to get hex in uppercase  */
			buffer[0] = 'A';
			count += to_base_n(str[i], 16, buffer);
		}
		else
			count += _putchar(str[i]);
	}
	return (count);
}
