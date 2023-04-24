#include "main.h"
#include <stdio.h>
#include <limits.h>
#include <assert.h>

int main()
{
	int x = 0;
	int *p = &x;
	int len_1, len_2;

	/* ===========> %b <=========== */
	printf("----------------------\n");
	printf("---> BINARY CASES <---\n");
	printf("----------------------\n");
	len_1 = printf("%b\n", 0);
	len_2 = _printf("%b\n", 0);
	assert(len_1 == len_2);

	len_2 = printf("%b\n", 255);
	len_1 = _printf("%b\n", 255);
	assert(len_1 == len_2);

	len_1 = printf("%b\n", UINT_MAX);
	len_2 = _printf("%b\n", UINT_MAX);
	assert(len_1 == len_2);

	/* ===========> %o <=========== */
	printf("----------------------\n");
	printf("----> OCTAL CASES <---\n");
	printf("----------------------\n");
	len_1 = printf("%o\n", 0);
	len_2 = _printf("%o\n", 0);
	assert(len_1 == len_2);

	len_2 = printf("%o\n", 255);
	len_1 = _printf("%o\n", 255);
	assert(len_1 == len_2);

	len_1 = printf("%o\n", UINT_MAX);
	len_2 = _printf("%o\n", UINT_MAX);
	assert(len_1 == len_2);

	/* ===========> %x <=========== */
	printf("----------------------\n");
	printf("-----> hex CASES <----\n");
	printf("----------------------\n");
	len_1 = printf("%x\n", 0);
	len_2 = _printf("%x\n", 0);
	assert(len_1 == len_2);

	len_2 = printf("%x\n", 255);
	len_1 = _printf("%x\n", 255);
	assert(len_1 == len_2);

	len_1 = printf("%x\n", UINT_MAX);
	len_2 = _printf("%x\n", UINT_MAX);
	assert(len_1 == len_2);

	/* ===========> %X <=========== */
	printf("----------------------\n");
	printf("-----> HEX CASES <----\n");
	printf("----------------------\n");
	len_1 = printf("%X\n", 0);
	len_2 = _printf("%X\n", 0);
	assert(len_1 == len_2);

	len_2 = printf("%X\n", 255);
	len_1 = _printf("%X\n", 255);
	assert(len_1 == len_2);

	len_1 = printf("%X\n", UINT_MAX);
	len_2 = _printf("%X\n", UINT_MAX);
	assert(len_1 == len_2);

	/* ===========> %p <=========== */
	printf("----------------------\n");
	printf("----> ADDRS CASES <---\n");
	printf("----------------------\n");

	len_1 = printf("%p\n", p);
	len_2 = _printf("%p\n", p);
	assert(len_1 == len_2);

	len_1 = printf("%p\n", (void *)0);
	len_2 = _printf("%p\n", (void *)0);
	assert(len_1 == len_2);

	return (0);
}
