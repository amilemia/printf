#include "main.h"
#include <stdio.h>
#include <limits.h>
#include <assert.h>

int main()
{
	int len_1, len_2;

	/* ===========> %d <=========== */
	/*Test case for positive integer with width less than the number of digits:*/
	len_1 = printf("Expected output: %5d\n", 123);
	len_2 = _printf("Current output: %5d\n", 123);
	printf("Expected length: [%d]\n", len_1);
	printf("Current length: [%d]\n", len_2);

	/*Test case for positive integer with width greater than the number of digits:*/
	len_1 = printf("Expected output: %10d\n", 123);
	len_2 = _printf("Current output: %10d\n", 123);
	printf("Expected length: [%d]\n", len_1);
	printf("Current length: [%d]\n", len_2);

	/*Test case for negative integer with width less than the number of digits:*/
	len_1 = printf("Expected output: %5d\n", -123);
	len_2 = _printf("Current output: %5d\n", -123);
	printf("Expected length: [%d]\n", len_1);
	printf("Current length: [%d]\n", len_2);

	/*Test case for negative integer with width greater than the number of digits:*/
	len_1 = printf("Expected output: %10d\n", -123);
	len_2 = _printf("Current output: %10d\n", -123);
	printf("Expected length: [%d]\n", len_1);
	printf("Current length: [%d]\n", len_2);

	/* ===========> %x <=========== */
	/*Test case for hexadecimal with width less than the number of digits:*/
	len_1 = printf("Expected output: %5x\n", 0xabc);
	len_2 = _printf("Current output: %5x\n", 0xabc);
	printf("Expected length: [%d]\n", len_1);
	printf("Current length: [%d]\n", len_2);

	/*Test case for hexadecimal with width greater than the number of digits:*/
	len_1 = printf("Expected output: %10x\n", 0xabc);
	len_2 = _printf("Current output: %10x\n", 0xabc);
	printf("Expected length: [%d]\n", len_1);
	printf("Current length: [%d]\n", len_2);

	return (0);
}
