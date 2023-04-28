#include <stdio.h>
#include <limits.h>
#include "main.h"

int main(void)
{
	int len_1, len_2;

	/* Test the (+) with positive and negative integers */
	printf("----------------------\n");
	printf("-----> (+) FLAG <-----\n");
	printf("----------------------\n");
	len_1 = _printf("%+d\n", 123);
	len_2 = printf("%+d\n", 123);
	printf("Current length:     [%d]\n", len_1);
	printf("Expected length:    [%d]\n", len_2);

	len_1 = _printf("%+d\n", -123);
	len_2 = printf("%+d\n", -123);
	printf("Current length:     [%d]\n", len_1);
	printf("Expected length:    [%d]\n", len_2);

	/* Test the (space) with positive and negative integers */
	printf("----------------------\n");
	printf("----> (' ') FLAG <----\n");
	printf("----------------------\n");
	len_1 = _printf("% d\n", 123);
	len_2 = printf("% d\n", 123);
	printf("Current length:     [%d]\n", len_1);
	printf("Expected length:    [%d]\n", len_2);

	len_1 = _printf("% d\n", -123);
	len_2 = printf("% d\n", -123);
	printf("Current length:     [%d]\n", len_1);
	printf("Expected length:    [%d]\n", len_2);

	len_1 = _printf("% ");
	len_2 = printf("% ");
	printf("Current length:     [%d]\n", len_1);
	printf("Expected length:    [%d]\n", len_2);
	len_1 = _printf("% % % % ");
	printf("\n");
	len_2 = printf("% % % % ");
	printf("\n");
	printf("Current length:     [%d]\n", len_1);
	printf("Expected length:    [%d]\n", len_2);

	/* Test the (#) flag with [o, x, X ] conversion specifiers */
	printf("----------------------\n");
	printf("-----> (#) FLAG <-----\n");
	printf("----------------------\n");
	len_1 = _printf("%#o\n", 123);
	len_2 = printf("%#o\n", 123);
	printf("Current length:     [%d]\n", len_1);
	printf("Expected length:    [%d]\n", len_2);

	len_1 = _printf("%#o\n", 0);
	len_2 = printf("%#o\n", 0);
	printf("Current length:     [%d]\n", len_1);
	printf("Expected length:    [%d]\n", len_2);

	len_1 = _printf("%#x\n", 123);
	len_2 = printf("%#x\n", 123);
	printf("Current length:     [%d]\n", len_1);
	printf("Expected length:    [%d]\n", len_2);

	len_1 = printf("%#x", 0);
	printf("\n");
	len_2 = _printf("%#x", 0);
	printf("\n");
	printf("Current length:     [%d]\n", len_1);
	printf("Expected length:    [%d]\n", len_2);

	len_1 = _printf("%#X\n", 123);
	len_2 = printf("%#X\n", 123);
	printf("Current length:     [%d]\n", len_1);
	printf("Expected length:    [%d]\n", len_2);

	len_1 = printf("%#X", 0);
	printf("\n");
	len_2 = _printf("%#X", 0);
	printf("\n");
	printf("Current length:     [%d]\n", len_1);
	printf("Expected length:    [%d]\n", len_2);

	/* Test combination of (space) & (+) with positive / negative int's */
	printf("----------------------\n");
	printf("-> (' ') & (+) FLAG <-\n");
	printf("----------------------\n");
	len_1 = _printf("% +d\n", 123);
	len_2 = printf("% +d\n", 123);
	printf("Current length:     [%d]\n", len_1);
	printf("Expected length:    [%d]\n", len_2);

	len_1 = _printf("% +d + %+ d = % +i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	printf("\n");
	len_2 = _printf("% +d + %+ d = % +i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	printf("\n");
	printf("Current length:     [%d]\n", len_1);
	printf("Expected length:    [%d]\n", len_2);

	return (0);
}
