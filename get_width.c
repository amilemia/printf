#include "main.h"

int _isdigit(int c);
int get_length(int (*pfn)(va_list), va_list args_copy);

/**
 * parse_width - parses the width of a field in a format string
 * @format: the format string
 * @args_copy: the va_list copy
 * @printed: pointer to the number of characters printed
 * @i: pointer to the current index in the format string
 */
void parse_width(const char *format, va_list args_copy, int *printed, int *i)
{
	int (*pfn)(va_list);
	int j, k, len, field_width;
	char pad_char = ' ';

	if (format[*i] == '0')
	{
		(pad_char = '0', (*i)++);
	}

	if (_isdigit(format[*i]))
	{
		field_width = format[*i] - '0';
		for (j = *i + 1; _isdigit(format[j]); j++)
			field_width = field_width * 10 + (format[j] - '0');
		*i = j;
	}
	else
		return;

	pfn = get_print(&format[*i]);
	len = get_length(pfn, args_copy);

	if (field_width > len)
	{
		for (k = 0; k < field_width - len; k++)
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
 * get_length - Calculates the length of the argument
 * @pfn: Pointer to the function to check
 * @args_copy: Copy of the list of arguments
 * Return: The length of the argument
 */
int get_length(int (*pfn)(va_list), va_list args_copy)
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

	if (pfn == print_char || pfn == print_str)
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
