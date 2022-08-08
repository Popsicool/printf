#include "main.h"

/**
 * prinhhex - short dec in hexadec
 * @arguments: string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int prinhhex(va_list arguments, char *buf, unsigned int ibuf)
{
	short int int_input, i, isneg, count, first_;
	char *hexa, *bina;

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

	bina = malloc(sizeof(char) * (16 + 1));
	bina = fill_binary_array(bina, int_input, isneg, 16);
	hexa = malloc(sizeof(char) * (4 + 1));
	hexa = fill_hex_array(bina, hexa, 0, 4);
	for (first_ = i = count = 0; hexa[i]; i++)
	{
		if (hexa[i] != '0' && first_ == 0)
			first_ = 1;
		if (first_)
		{
			ibuf = handl_buf(buf, hexa[i], ibuf);
			count++;
		}
	}
	free(bina);
	free(hexa);
	return (count);
}

/**
 * prinhint - prints a short int
 * @arguments: string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed.
 */
int prinhint(va_list arguments, char *buf, unsigned int ibuf)
{
	short int int_input;
	unsigned short int int_in, int_t, i, div, isneg;

	int_input = va_arg(arguments, int);
	isneg = 0;
	if (int_input < 0)
	{
		int_in = int_input * -1;
		ibuf = handl_buf(buf, '-', ibuf);
		isneg = 1;
	}
	else
	{
		int_in = int_input;
	}
	int_t = int_in;
	div = 1;
	while (int_t > 9)
	{
		div *= 10;
		int_t /= 10;
	}
	for (i = 0; div > 0; div /= 10, i++)
	{
		ibuf = handl_buf(buf, ((int_in / div) % 10) + '0', ibuf);
	}
	return (i + isneg);
}

/**
 * prinhoct - long decimal number in octal
 * @arguments: input number
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed.
 */
int prinhoct(va_list arguments, char *buf, unsigned int ibuf)
{
	short int int_input, i, isneg, count, first_;
	char *octal, *bina;

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

	bina = malloc(sizeof(char) * (16 + 1));
	bina = fill_binary_array(bina, int_input, isneg, 16);
	octal = malloc(sizeof(char) * (6 + 1));
	octal = fill_short_oct_array(bina, octal);
	for (first_ = i = count = 0; octal[i]; i++)
	{
		if (octal[i] != '0' && first_ == 0)
			first_ = 1;
		if (first_)
		{
			ibuf = handl_buf(buf, octal[i], ibuf);
			count++;
		}
	}
	free(bina);
	free(octal);
	return (count);
}
