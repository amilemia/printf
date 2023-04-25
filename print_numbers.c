#include "main.h"

/**
 * print_int - prints integers from a va_list
 * @list: va_list of integers to be printed
 * Return: number of characters printed
 */
int print_int(va_list list, int field_width)
{
	int num = va_arg(list, int);
	char buffer[50];
	int len;
	int i;
	int count = 0;

	_itoa(num, buffer);
	len = _strlen(buffer);

	if (field_width > len)
	{
		for (i = 0; i < field_width - len; i++)
		count += _putchar(' ');
	}
	count += _puts(buffer);
	return (count);
}


/**
 * print_unsigned - prints unsigned integers from a va_list
 * @list: va_list of unsigned integers to be printed
 * Return: number of characters printed
 */
int print_unsigned(va_list list, int field_width)
{
	unsigned int num = va_arg(list, unsigned int);
	char buffer[50];
	(void)(field_width);

	_itoa(num, buffer);
	return (_puts(buffer));
}
