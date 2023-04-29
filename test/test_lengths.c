#include <stdio.h>
#include <limits.h>
#include "main.h"

int main(void)
{
	int len_1, len_2;

	len_1 = _printf("%ld\n", 123L);
	len_2 = printf("%ld\n", 123L);
	printf("Current length:     [%d]\n", len_1);
	printf("Expected length:    [%d]\n", len_2);

	len_1 = _printf("%ld\n", -123L);
	len_2 = printf("%ld\n", -123L);
	printf("Current length:     [%d]\n", len_1);
	printf("Expected length:    [%d]\n", len_2);

	len_1 = _printf("%ld\n", 0L);
	len_2 = printf("%ld\n", 0L);
	printf("Current length:     [%d]\n", len_1);
	printf("Expected length:    [%d]\n", len_2);

	len_1 = _printf("%ld\n", LONG_MAX);
	len_2 = printf("%ld\n", LONG_MAX);
	printf("Current length:     [%d]\n", len_1);
	printf("Expected length:    [%d]\n", len_2);

	len_1 = _printf("%hd\n", SHRT_MAX);
	len_2 = printf("%hd\n", SHRT_MAX);
	printf("Current length:     [%d]\n", len_1);
	printf("Expected length:    [%d]\n", len_2);

	len_1 = _printf("%lu\n", ULONG_MAX);
	len_2 = printf("%lu\n", ULONG_MAX);
	printf("Current length:     [%d]\n", len_1);
	printf("Expected length:    [%d]\n", len_2);

	len_1 = _printf("%hd\n", 0UL);
	len_2 = printf("%hd\n", 0UL);
	printf("Current length:     [%d]\n", len_1);
	printf("Expected length:    [%d]\n", len_2);

	len_1 = _printf("%lo\n", ULONG_MAX);
	len_2 = printf("%lo\n", ULONG_MAX);
	printf("Current length:     [%d]\n", len_1);
	printf("Expected length:    [%d]\n", len_2);

	len_1 = _printf("%ho\n", 0UL);
	len_2 = printf("%ho\n", 0UL);
	printf("Current length:     [%d]\n", len_1);
	printf("Expected length:    [%d]\n", len_2);

	len_1 = _printf("%lx\n", ULONG_MAX);
	len_2 = printf("%lx\n", ULONG_MAX);
	printf("Current length:     [%d]\n", len_1);
	printf("Expected length:    [%d]\n", len_2);

	len_1 = _printf("%hx\n", 0UL);
	len_2 = printf("%hx\n", 0UL);
	printf("Current length:     [%d]\n", len_1);
	printf("Expected length:    [%d]\n", len_2);

	len_1 = _printf("%lX\n", ULONG_MAX);
	len_2 = printf("%lX\n", ULONG_MAX);
	printf("Current length:     [%d]\n", len_1);
	printf("Expected length:    [%d]\n", len_2);

	len_1 = _printf("%hX\n", 0UL);
	len_2 = printf("%hX\n", 0UL);
	printf("Current length:     [%d]\n", len_1);
	printf("Expected length:    [%d]\n", len_2);

	return (0);
}
