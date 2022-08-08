#include "main.h"

/**
 * print_bnr - convert decimal to binary and print
 * @arguments: input string
 * @buf: pointer to buffer
 * @ibuf: buffer pointer index
 * Return: number of chars printed.
 */
int print_bnr(va_list arguments, char *buf, unsigned int ibuf)
{
	int int_input, count, i, first, isneg;
	char *binary;

	int_input = va_arg(arguments, int);
	isneg = 0;
	if (int_input == 0)
	{
		ibuf = handl_buf(buf, '0', ibuf);
		return (1);
	}
	if (int_input < 0)
	{
		int_input = (int_input * -1) - 1;
		isneg = 1;
	}
	binary = malloc(sizeof(char) * (32 + 1));
	binary = fill_binary_array(binary, int_input, isneg, 32);
	first = 0;
	for (count = i = 0; binary[i]; i++)
	{
		if (first == 0 && binary[i] == '1')
			first = 1;
		if (first == 1)
		{
			ibuf = handl_buf(buf, binary[i], ibuf);
			count++;
		}
	}
	free(binary);
	return (count);
}

/**
 * print_buf - prints buffer like _putchar
 * @buf: buffer pointer
 * @nbuf: number of bytes to print
 * Return: number of bytes printed.
 */
int print_buf(char *buf, unsigned int nbuf)
{
	return (write(1, buf, nbuf));
}

#include "main.h"
#include <stdio.h>
/**
 * print_chr - writes the character c to stdout
 * @arguments: input char
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: On success 1.
 */
int print_chr(va_list arguments, char *buf, unsigned int ibuf)
{
	char c;

	c = va_arg(arguments, int);
	handl_buf(buf, c, ibuf);

	return (1);
}
