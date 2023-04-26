#include <stdio.h>
#include "main.h"

int main()
{
	int len_1, len_2;

	/* ===========> %d <=========== */
	/*Test case for positive integer with precision less than the number of digits*/
	len_1 = printf("Expected output: %.3d\n", 123);
	len_2 = _printf("Current output: %.3d\n", 123);
	printf("Expected length: [%d]\n", len_1);
	printf("Current length: [%d]\n", len_2);

	/*Test case for positive integer with precision greater than the number of digits*/
	len_1 = printf("Expected output: %.10d\n", 123);
	len_2 = _printf("Current output: %.10d\n", 123);
	printf("Expected length: [%d]\n", len_1);
	printf("Current length: [%d]\n", len_2);

	/*Test case for negative integer with precision less than the number of digits:*/
	len_1 = printf("Expected output: %.3d\n", -123);
	len_2 = _printf("Current output: %.3d\n", -123);
	printf("Expected length: [%d]\n", len_1);
	printf("Current length: [%d]\n", len_2);

	/*Test case for negative integer with precision greater than the number of digits:*/
	len_1 = printf("Expected output: %.10d\n", -123);
	len_2 = _printf("Current output: %.10d\n", -123);
	printf("Expected length: [%d]\n", len_1);
	printf("Current length: [%d]\n", len_2);

	/* ===========> %x <=========== */
	/*Test case for hexadecimal with precision less than the number of digits:*/
	len_1 = printf("Expected output: %.3x\n", 0xabc);
	len_2 = _printf("Current output: %.3x\n", 0xabc);
	printf("Expected length: [%d]\n", len_1);
	printf("Current length: [%d]\n", len_2);

	/*Test case for hexadecimal with precision greater than the number of digits:*/
	len_1 = printf("Expected output: %.10x\n", 0xabc);
	len_2 = _printf("Current output: %.10x\n", 0xabc);
	printf("Expected length: [%d]\n", len_1);
	printf("Current length: [%d]\n", len_2);

	return (0);
}
