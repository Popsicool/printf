#include "main.h"

/**
 * prinhunt - prints a short unsigned integer.
 * @arguments: number to print.
 * @buf: buffer pointer.
 * @ibuf: index for buffer pointer.
 * Return: number of chars printed.
 */
int prinhunt(va_list arguments, char *buf, unsigned int ibuf)
{
	unsigned short int int_in, int_t, i, div;

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
 * prinhupx - prints a short decimal in hexadecimal
 * @arguments: The character to print
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int prinhupx(va_list arguments, char *buf, unsigned int ibuf)
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
	hexa = fill_hex_array(bina, hexa, 1, 4);

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
 * prinsint - prints space starting int
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int prinsint(va_list arguments, char *buf, unsigned int ibuf)
{
	int int_input;
	unsigned int int_in, int_t, i, div;

	int_input = va_arg(arguments, int);
	if (int_input < 0)
	{
		int_in = int_input * -1;
		ibuf = handl_buf(buf, '-', ibuf);
	}
	else
	{
		int_in = int_input;
		ibuf = handl_buf(buf, ' ', ibuf);
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
	return (i + 1);
}

/**
 * print_str - print strings
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: On success 1.
 */
int print_str(va_list arguments, char *buf, unsigned int ibuf)
{
	char *str;
	unsigned int i;
	char nill[] = "(null)";

	str = va_arg(arguments, char *);
	if (str == NULL)
	{
		for (i = 0; nill[i]; i++)
			ibuf = handl_buf(buf, nill[i], ibuf);
		return (6);
	}
	for (i = 0; str[i]; i++)
		ibuf = handl_buf(buf, str[i], ibuf);
	return (i);
}
