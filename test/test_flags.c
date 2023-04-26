#include <stdio.h>
#include <limits.h>
#include "main.h"

int main(void)
{
	int len_1, len_2;

	/* Test the (+) flag with positive and negative integers */
	len_1 = _printf("%+d\n", 123);
	len_2 = printf("%+d\n", 123);
	printf("Expected length:    [%d]\n", len_1);
	printf("Current length:     [%d]\n", len_2);

	len_1 = _printf("%+d\n", -123);
	len_2 = printf("%+d\n", -123);
	printf("Expected length:    [%d]\n", len_1);
	printf("Current length:     [%d]\n", len_2);

	/* Test the (space) flag with positive and negative integers */
	len_1 = _printf("% d\n", 123);
	len_2 = printf("% d\n", 123);
	printf("Expected length:    [%d]\n", len_1);
	printf("Current length:     [%d]\n", len_2);

	len_1 = _printf("% d\n", -123);
	len_2 = printf("% d\n", -123);
	printf("Expected length:    [%d]\n", len_1);
	printf("Current length:     [%d]\n", len_2);

	/* Test the (#) flag with [o, x, X ] conversion specifiers */
	len_1 = _printf("%#o\n", 123);
	len_2 = printf("%#o\n", 123);
	printf("Expected length:    [%d]\n", len_1);
	printf("Current length:     [%d]\n", len_2);

	len_1 = _printf("%#x\n", 123);
	len_2 = printf("%#x\n", 123);
	printf("Expected length:    [%d]\n", len_1);
	printf("Current length:     [%d]\n", len_2);

	len_1 = printf("%#x", 0);
	printf("\n");
	len_2 = _printf("%#x", 0);
	printf("\n");
	printf("Expected length:    [%d]\n", len_1);
	printf("Current length:     [%d]\n", len_2);

	len_1 = _printf("%#X\n", 123);
	len_2 = printf("%#X\n", 123);
	printf("Expected length:    [%d]\n", len_1);
	printf("Current length:     [%d]\n", len_2);

	len_1 = printf("%#X", 0);
	printf("\n");
	len_2 = _printf("%#X", 0);
	printf("\n");
	printf("Expected length:    [%d]\n", len_1);
	printf("Current length:     [%d]\n", len_2);

	/* Test combinations of flags */
	len_1 = _printf("% +d\n", 123);
	len_2 = printf("% +d\n", 123);
	printf("Expected length:    [%d]\n", len_1);
	printf("Current length:     [%d]\n", len_2);

	/* Test the (0) flag with positive and negative integers */
	len_1 = _printf("%010d\n", 123);
	len_2 = printf("%010d\n", 123);
	printf("Expected length:    [%d]\n", len_1);
	printf("Current length:     [%d]\n", len_2);

	len_1 = _printf("%010d\n", -123);
	len_2 = printf("%010d\n", -123);
	printf("Expected length:    [%d]\n", len_1);
	printf("Current length:     [%d]\n", len_2);

	/* Test the (-) flag with positive and negative integers */
	len_1 = _printf("%-10d\n", 123);
	len_2 = printf("%-10d\n", 123);
	printf("Expected length:    [%d]\n", len_1);
	printf("Current length:     [%d]\n", len_2);

	len_1 = _printf("%-10d\n", -123);
	len_2 = printf("%-10d\n", -123);
	printf("Expected length:    [%d]\n", len_1);
	printf("Current length:     [%d]\n", len_2);

	/* Test combinations of flags */
	/*len_1 = _printf("%0+10d\n", 123);
	len_2 = printf("%0+10d\n", 123);
	printf("Expected length:    [%d]\n", len_1);
	printf("Current length:     [%d]\n", len_2);

	len_1 = _printf("%0+10d\n", -123);
	len_2 = printf("%0+10d\n", -123);
	printf("Expected length:    [%d]\n", len_1);
	printf("Current length:     [%d]\n", len_2);

	len_1 = _printf("%-+10d\n", 123);
	len_2 = printf("%-+10d\n", 123);
	printf("Expected length:    [%d]\n", len_1);
	printf("Current length:     [%d]\n", len_2);

	len_1 = _printf("%-+10d\n", -123);
	len_2 = printf("%-+10d\n", -123);
	printf("Expected length:    [%d]\n", len_1);
	printf("Current length:     [%d]\n", len_2);*/

	/* */
	len_1 = _printf("% ");
	len_2 = printf("% ");
	printf("Expected length:    [%d]\n", len_1);
	printf("Current length:     [%d]\n", len_2);
	len_1 = _printf("% % % % ");
	printf("\n");
	len_2 = printf("% % % % ");
	printf("\n");
	printf("Expected length:    [%d]\n", len_1);
	printf("Current length:     [%d]\n", len_2);

	len_1 = _printf("% +d + %+ d = % +i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	printf("\n");
	len_2 = _printf("% +d + %+ d = % +i\n", INT_MIN, INT_MAX, (INT_MIN + INT_MAX));
	printf("\n");
	printf("Expected length:    [%d]\n", len_1);
	printf("Current length:     [%d]\n", len_2);

	return (0);
}
