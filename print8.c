#include "main.h"
/**
 * prinlunt - prints a long unsigned integer
 * @arguments: number to print
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed.
 */
int prinlunt(va_list arguments, char *buf, unsigned int ibuf)
{
	unsigned long int int_in, int_temp, i, div;

	int_in = va_arg(arguments, unsigned long int);
	int_temp = int_in;
	div = 1;
	while (int_temp > 9)
	{
		div *= 10;
		int_temp /= 10;
	}
	for (i = 0; div > 0; div /= 10, i++)
	{
		ibuf = handl_buf(buf, ((int_in / div) % 10) + '0', ibuf);
	}
	return (i);
}

/**
 * prinlupx - prints a long decimal in hexadecimal
 * @arguments: The character to print
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int prinlupx(va_list arguments, char *buf, unsigned int ibuf)
{
	long int int_input, i, isneg, count, first_;
	char *hexa, *bina;

	int_input = va_arg(arguments, long int);
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

	bina = malloc(sizeof(char) * (64 + 1));
	bina = fill_binary_array(bina, int_input, isneg, 64);
	hexa = malloc(sizeof(char) * (16 + 1));
	hexa = fill_hex_array(bina, hexa, 1, 16);
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
 * prinnhex - print number in hex begining with zero
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int prinnhex(va_list arguments, char *buf, unsigned int ibuf)
{
	int int_input, i, isneg, count, first_;
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
	ibuf = handl_buf(buf, '0', ibuf);
	ibuf = handl_buf(buf, 'x', ibuf);
	bina = malloc(sizeof(char) * (32 + 1));
	bina = fill_binary_array(bina, int_input, isneg, 32);
	hexa = malloc(sizeof(char) * (8 + 1));
	hexa = fill_hex_array(bina, hexa, 0, 8);
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
	return (count + 2);
}
