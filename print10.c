#include "main.h"

/**
 * prinnoct - print octa number from 0
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int prinnoct(va_list arguments, char *buf, unsigned int ibuf)
{
	int int_input, i, isneg, count, first_;
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
	ibuf = handl_buf(buf, '0', ibuf);
	bina = malloc(sizeof(char) * (32 + 1));
	bina = fill_binary_array(bina, int_input, isneg, 32);
	octal = malloc(sizeof(char) * (11 + 1));
	octal = fill_oct_array(bina, octal);
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
	return (count + 1);
}

/**
 * prinnupx - prints number in uppercase hex
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int prinnupx(va_list arguments, char *buf, unsigned int ibuf)
{
	int int_input, i, isneg, count, first_;
	char *hexa, *binary;

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
	ibuf = handl_buf(buf, 'X', ibuf);
	binary = malloc(sizeof(char) * (32 + 1));
	binary = fill_binary_array(binary, int_input, isneg, 32);
	hexa = malloc(sizeof(char) * (8 + 1));
	hexa = fill_hex_array(binary, hexa, 1, 8);
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
	free(binary);
	free(hexa);
	return (count + 2);
}

/**
 * print_oct - prints decimal number in octal
 * @arguments: input number
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed.
 */
int print_oct(va_list arguments, char *buf, unsigned int ibuf)
{
	int int_input, i, isneg, count, first_;
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
	bina = malloc(sizeof(char) * (32 + 1));
	bina = fill_binary_array(bina, int_input, isneg, 32);
	octal = malloc(sizeof(char) * (11 + 1));
	octal = fill_oct_array(bina, octal);
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
