#include "main.h"
/**
 * print_unt - prints  unsigned int
 * @arguments: the number to print
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed.
 */
int print_unt(va_list arguments, char *buf, unsigned int ibuf)
{
	unsigned int int_in, int_t, i, div;

	int_in = va_arg(arguments, unsigned int);
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
	return (i);
}

/**
 * print_upx - prints a decimal in hexadecimal
 * @arguments: The character to print
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int print_upx(va_list arguments, char *buf, unsigned int ibuf)
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
	return (count);
}

/**
 * print_usr - prints a string and values of
 * non-printed chars
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int print_usr(va_list arguments, char *buf, unsigned int ibuf)
{
	unsigned char *str;
	char *hexa, *bina;
	unsigned int i, sum, op;

	str = va_arg(arguments, unsigned char *);
	bina = malloc(sizeof(char) * (32 + 1));
	hexa = malloc(sizeof(char) * (8 + 1));
	for (sum = i = 0; str[i]; i++)
	{
		if (str[i] < 32 || str[i] >= 127)
		{
			ibuf = handl_buf(buf, '\\', ibuf);
			ibuf = handl_buf(buf, 'x', ibuf);
			op = str[i];
			bina = fill_binary_array(bina, op, 0, 32);
			hexa = fill_hex_array(bina, hexa, 1, 8);
			ibuf = handl_buf(buf, hexa[6], ibuf);
			ibuf = handl_buf(buf, hexa[7], ibuf);
			sum += 3;
		}
		else
			ibuf = handl_buf(buf, str[i], ibuf);
	}
	free(bina);
	free(hexa);
	return (i + sum);
}
