#include "main.h"
#include <stdio.h>
#include <limits.h>
#include <assert.h>

int main()
{
	int len_1, len_2;

	len_1 = printf("Expected output: %6d\n", 102498402);
	len_2 = _printf("Current output:  %6d\n", 102498402);
	printf("Expected length: [%d]\n", len_1);
	printf("Current length:  [%d]\n", len_2);

	len_1 = printf("Expected output: %6d\n", 123);
	len_2 = _printf("Current output:  %6d\n", 123);
	printf("Expected length: [%d]\n", len_1);
	printf("Current length:  [%d]\n", len_2);

	len_1 = printf("Expected output: %6u\n", 123);
	len_2 = _printf("Current output:  %6u\n", 123);
	printf("Expected length: [%d]\n", len_1);
	printf("Current length:  [%d]\n", len_2);

	len_1 = printf("Expected output: %6o\n", 123);
	len_2 = _printf("Current output:  %6o\n", 123);
	printf("Expected length: [%d]\n", len_1);
	printf("Current length:  [%d]\n", len_2);

	len_1 = printf("Expected output: %6x\n", 123);
	len_2 = _printf("Current output:  %6x\n", 123);
	printf("Expected length: [%d]\n", len_1);
	printf("Current length:  [%d]\n", len_2);

	len_1 = printf("Expected output: %6X\n", 123);
	len_2 = _printf("Current output:  %6X\n", 123);
	printf("Expected length: [%d]\n", len_1);
	printf("Current length:  [%d]\n", len_2);

	len_1 = printf("Expected output: %6c\n", 'A');
	len_2 = _printf("Current output:  %6c\n", 'A');
	printf("Expected length: [%d]\n", len_1);
	printf("Current length:  [%d]\n", len_2);

	len_1 = printf("Expected output: %6s", "Hi\n");
	len_2 = _printf("Current output:  %6s", "Hi\n");
	printf("Expected length: [%d]\n", len_1);
	printf("Current length:  [%d]\n", len_2);

	len_1 = printf("Expected output: %6d\n", -102498402);
	len_2 = _printf("Current output:  %6d\n", -102498402);
	printf("Expected length: [%d]\n", len_1);
	printf("Current length:  [%d]\n", len_2);

	len_1 = printf("Expected output: %6d\n", 0);
	len_2 = _printf("Current output:  %6d\n", 0);
	printf("Expected length: [%d]\n", len_1);
	printf("Current length:  [%d]\n", len_2);

	len_1 = printf("Expected output: %6d\n", -1024);
	len_2 = _printf("Current output:  %6d\n", -1024);
	printf("Expected length: [%d]\n", len_1);
	printf("Current length:  [%d]\n", len_2);

	len_1 = printf("In the middle %6d of a sentence.\n", 1024);
	len_2 = _printf("In the middle %6d of a sentence.\n", 1024);
	printf("Expected length: [%d]\n", len_1);
	printf("Current length:  [%d]\n", len_2);

	printf("----------------------\n");
	printf("-----> (*) WIDTH <----\n");
	printf("----------------------\n");
	len_1 = printf("Expected output: %*d\n", 6, 123);
	len_2 = _printf("Current output:  %*d\n", 6, 123);
	printf("Expected length: [%d]\n", len_1);
	printf("Current length:  [%d]\n", len_2);

	len_1 = printf("Expected output: %*d\n", 6, -123);
	len_2 = _printf("Current output:  %*d\n", 6, -123);
	printf("Expected length: [%d]\n", len_1);
	printf("Current length:  [%d]\n", len_2);

	len_1 = printf("In the middle %*s of a sentence.\n", 6, "Hey");
	len_2 = _printf("In the middle %*s of a sentence.\n", 6, "Hey");
	printf("Expected length: [%d]\n", len_1);
	printf("Current length:  [%d]\n", len_2);

	return (0);
}
