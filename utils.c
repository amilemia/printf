#include "main.h"

/**
 * _strlen - length of a given string
 * @s: the string
 * Return: the length of given string
 */

unsigned int _strlen(char *s)
{
	unsigned int len = 0;

	while (s[len])
		len++;

	return (len);
}

/**
 * reverse_str - reverses a given string
 * @s: the string to be reversed
 */

void reverse_str(char s[])
{
	unsigned int i = 0, len = 0;
	char temp;

	len = _strlen(s);

	for (; i < len / 2; i++)
	{
		temp = s[i];
		s[i] = s[len - i - 1];
		s[len - i - 1] = temp;
	}
}

/**
 * _itoa - Converts a long integer to a string
 *  @n: The long integer to convert
 *  @s: The character array to store the converted string in
 */

void _itoa(long n, char s[])
{
	long sign = n;
	unsigned int i = 0;

	if (sign < 0)
		n = -n;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
	if (sign < 0)
		s[i++] = '-';
	s[i] = '\0';
	reverse_str(s);
}

/**
 * to_base_n - convert a number to a base n
 * @num: the number to convert
 * @base: the base to convert to
 * @buffer: the character array that will hold the resulting string
 * Return: number of characters printed
 */
int to_base_n(unsigned long num, int base, char buffer[])
{
	int i = 0, rem;
	char hex_case = (buffer[0] == 'A') ? 'A' : 'a';

	(num == 0) && (buffer[i++] = '0');

	while (num > 0)
	{
		rem = num % base;

		if (rem < 10)
			buffer[i++] = rem + '0';
		else
			buffer[i++] = rem - 10 + hex_case;

		num /= base;
	}
	buffer[i] = '\0';
	reverse_str(buffer);
	return (_puts(buffer));
}

/**
 * num_len_base - Calculates the length of a number in a given base
 * @num: The number to calculate the length of
 * @base: The base to use for the calculation
 * Return: The length of the number in the given base
 */
int num_len_base(long num, int base)
{
	int count = 0;

	if (num == 0)
		return (1);
	while (num > 0)
	{
		num /= base;
		count++;
	}
	return (count);
}
