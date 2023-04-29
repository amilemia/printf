#include "main.h"

int _isdigit(int c);
int num_length(int (*pfn)(va_list), va_list args_copy);

/**
 * get_width - Retrieve the width of a field from a format string
 * @format: The format string
 * @width: pointer to a width_t struct containing the width found
 * @i: Pointer to the current index in the format string
 */
void get_width(const char *format, width_t *width, int *i)
{
	int j, field_width;

	if (format[*i] == '0')
	{
		width->is_zero = 1;
		(*i)++;
	}

	if (format[*i] == '*')
	{
		width->is_astreak = 1;
		(*i)++;
		return;
	}

	if (_isdigit(format[*i]))
	{
		field_width = format[*i] - '0';
		for (j = *i + 1; _isdigit(format[j]); j++)
			field_width = field_width * 10 + (format[j] - '0');

		width->value = field_width;
		*i = j;
	}
	else
		return;
}

/**
 * parse_width - parses width for printing
 * @width: pointer to a width_t struct containing the width found
 * @args_width: va_list of arguments
 * @pfn: pointer to returned func from get_print()
 * @printed: pointer to the count of characters printed
 */
void parse_width(width_t *width, va_list args_width,
				 pfn_t pfn, int *printed)
{
	int k, len = 0;
	char pad_char = width->is_zero ? '0' : ' ';

	if (!width->value && !width->is_astreak)
		return;

	/* if found (*) retrieve value from 1st arg in args_width */
	if (width->is_astreak)
		width->value = va_arg(args_width, int);

	len = num_length(pfn, args_width);

	if (width->value > len)
	{
		for (k = 0; k < width->value - len; k++)
			*printed += _putchar(pad_char);
	}
}

/**
 * _isdigit - checks if a character is a digit
 * @c: the character to check
 * Return: 1 is a digit, 0 otherwise
 */
int _isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

/**
 * num_length - Calculates the length of the argument
 * @pfn: Pointer to the function to check
 * @args_copy: Copy of the list of arguments
 * Return: The length of the argument
 */
int num_length(int (*pfn)(va_list), va_list args_copy)
{
	int num_int;
	unsigned int i = 0, len = 0, size, num_unsg;

	function_t functions[] = {
		{10, print_unsigned},
		{16, print_hex},
		{16, print_HEX},
		{16, print_addrs},
		{8, print_octal},
		{2, print_binary},
		{10, print_int}};

	size = sizeof(functions) / sizeof(functions[0]);

	if (pfn == print_char)
		len = 1;
	else if (pfn == print_str)
		len = _strlen(va_arg(args_copy, char *));
	else if (pfn == print_int)
	{
		num_int = va_arg(args_copy, int);

		if (num_int < 0)
			(num_int *= -1, len++);

		len += num_len_base(num_int, functions[i].base);
	}
	else
	{
		for (; i < size; i++)
			if (pfn == functions[i].pfn)
			{
				num_unsg = va_arg(args_copy, unsigned int);
				len = num_len_base(num_unsg, functions[i].base);
				break;
			}
	}
	return (len);
}
