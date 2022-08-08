#include "main.h"

/**
 * handl_buf - merge the buffer characters
 * @buf: pointer to buffer
 * @c: charcter to merge
 * @ibuf: index of buffer pointer
 * Return: index of buffer pointer.
 */
unsigned int handl_buf(char *buf, char c, unsigned int ibuf)
{
	if (ibuf == 1024)
	{
		print_buf(buf, ibuf);
		ibuf = 0;
	}
	buf[ibuf] = c;
	ibuf++;
	return (ibuf);
}

/**
 * print_add - prints address
 * @arguments: input address.
 * @buf: pointer to buffer
 * @ibuf: index for buffer pointer.
 * Return: number of chars printed.
 */
int print_add(va_list arguments, char *buf, unsigned int ibuf)
{
	void *add;
	long int input1;
	int i, count, first_digit, isnegative;
	char *hexadecimal, *binary;
	char nill[] = "(nil)";

	add = (va_arg(arguments, void *));
	if (add == NULL)
	{
		for (i = 0; nill[i]; i++)
			ibuf = handl_buf(buf, nill[i], ibuf);
		return (5);
	}
	input1 = (intptr_t)add;
	isnegative = 0;
	if (input1 < 0)
	{
		input1 = (input1 * -1) - 1;
		isnegative = 1;
	}
	binary = malloc(sizeof(char) * (64 + 1));
	binary = fill_binary_array(binary, input1, isnegative, 64);
	hexadecimal = malloc(sizeof(char) * (16 + 1));
	hexadecimal = fill_hex_array(binary, hexadecimal, 0, 16);
	ibuf = handl_buf(buf, '0', ibuf);
	ibuf = handl_buf(buf, 'x', ibuf);
	for (first_digit = i = count = 0; hexadecimal[i]; i++)
	{
		if (hexadecimal[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			ibuf = handl_buf(buf, hexadecimal[i], ibuf);
			count++;
		}
	}
	free(binary);
	free(hexadecimal);
	return (count + 2);
}
