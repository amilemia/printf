#include "main.h"

/**
 * print_binary - prints a binary representation of an unsigned int
 * @list: va_list of integers to be printed
 * Return: number of characters printed
 */
int print_binary(va_list list)
{
	char buffer[50];
	unsigned int num = va_arg(list, unsigned int);

	return (to_base_n(num, 2, buffer));
}

/**
 * print_octal - prints a octal representation of an unsigned int
 * @list: va_list of integers to be printed
 * Return: number of characters printed
 */
int print_octal(va_list list)
{
	char buffer[50];
	unsigned int num = va_arg(list, unsigned int);

	return (to_base_n(num, 8, buffer));
}

/**
 * print_hex - prints a hexadecimal representation of an unsigned int
 * @list: va_list of integers to be printed
 * Return: number of characters printed
 */
int print_hex(va_list list)
{
	char buffer[50];
	unsigned int num = va_arg(list, unsigned int);

	return (to_base_n(num, 16, buffer));
}
