#include "main.h"

/**
 * get_print - func to return a pointer to the appropriate print func.
 * @format: format of the argument to be printed
 * Return: pointer to the appropriate print func, OR NULL if no match is found.
 */
pfn_t get_print(const char *format)
{
	int i = 0;
	fmt_t fmt_types[] = {
		{"c", print_char},
		{"s", print_str},
		{"%", print_perc},
		{"d", print_int},
		{"i", print_int},
		{"u", print_unsigned},
		{"b", print_binary},
		{"o", print_octal},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_addrs},
		{"S", print_STR},
		{"r", print_rev},
		{"R", print_rot13},
		{NULL, NULL}};

	for (; fmt_types[i].sym; i++)
	{
		if (*format == *(fmt_types[i].sym))
		{
			return (fmt_types[i].fn);
		}
	}
	return (NULL);
}
