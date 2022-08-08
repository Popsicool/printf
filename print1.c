#include "main.h"

/**
 * fill_hex_array - writes the character c to stdout
 * @bnr: store binarry
 * @hex: store hexadecimal
 * @isupp: determine if its upper case
 * @limit: size of hex
 * Return: binary array.
 */
char *fill_hex_array(char *bnr, char *hex, int isupp, int limit)
{
	int p, i, j, to_let;

	hex[limit] = '\0';
	if (isupp)
		to_let = 55;
	else
		to_let = 87;
	for (i = (limit * 4) - 1; i >= 0; i--)
	{
		for (p = 0, j = 1; j <= 8; j *= 2, i--)
			p = ((bnr[i] - '0') * j) + p;
		i++;
		if (p < 10)
			hex[i / 4] = p + 48;
		else
			hex[i / 4] = p + to_let;
	}
	return (hex);
}

/**
 * fill_binary_array - prints decimal in binary
 * @binary: the pointer to the binary
 * @int_in: the number inputted
 * @isneg: for negative number
 * @limit: size of the binary
 * Return: return the number of chars printed.
 */
char *fill_binary_array(char *binary, long int int_in, int isneg, int limit)
{
	int i;

	for (i = 0; i < limit; i++)
		binary[i] = '0';
	binary[limit] = '\0';
	for (i = limit - 1; int_in > 1; i--)
	{
		if (int_in == 2)
			binary[i] = '0';
		else
			binary[i] = (int_in % 2) + '0';
		int_in /= 2;
	}
	if (int_in != 0)
		binary[i] = '1';
	if (isneg)
	{
		for (i = 0; binary[i]; i++)
			if (binary[i] == '0')
				binary[i] = '1';
			else
				binary[i] = '0';
	}
	return (binary);
}

/**
 * ev_print_func - check and returns amount of identifiers.
 * @s: argument indentifier
 * @index: index of argument identifier.
 * Return: amount of identifiers.
 */
int ev_print_func(const char *s, int index)
{
	print_t pr[] = {
		{"c", print_chr}, {"s", print_str}, {"i", print_int},
		{"d", print_int}, {"b", print_bnr}, {"u", print_unt},
		{"o", print_oct}, {"x", print_hex}, {"X", print_upx},
		{"S", print_usr}, {"p", print_add}, {"li", prinlint},
		{"ld", prinlint}, {"lu", prinlunt}, {"lo", prinloct},
		{"lx", prinlhex}, {"lX", prinlupx}, {"hi", prinhint},
		{"hd", prinhint}, {"hu", prinhunt}, {"ho", prinhoct},
		{"hx", prinhhex}, {"hX", prinhupx}, {"#o", prinnoct},
		{"#x", prinnhex}, {"#X", prinnupx}, {"#i", print_int},
		{"#d", print_int}, {"#u", print_unt}, {"+i", prinpint},
		{"+d", prinpint}, {"+u", print_unt}, {"+o", print_oct},
		{"+x", print_hex}, {"+X", print_upx}, {" i", prinsint},
		{" d", prinsint}, {" u", print_unt}, {" o", print_oct},
		{" x", print_hex}, {" X", print_upx}, {"R", print_rot},
		{"r", print_rev}, {"%", print_prg}, {"l", print_prg},
		{"h", print_prg}, {" +i", prinpint}, {" +d", prinpint},
		{"+ i", prinpint}, {"+ d", prinpint}, {" %", print_prg},
		{NULL, NULL},
	};
	int i = 0, j = 0, index1;

	index1 = index;
	while (pr[i].type_arg)
	{
		if (s[index] == pr[i].type_arg[j])
		{
			if (pr[i].type_arg[j + 1] != '\0')
				index++, j++;
			else
				break;
		}
		else
		{
			j = 0;
			i++;
			index = index1;
		}
	}
	return (j);
}
#include "main.h"

/**
 * fill_long_oct_array - long octa number calculation
 * @bnr: stores binary
 * @oct: stores octa
 * Return: binary array.
 */
char *fill_long_oct_array(char *bnr, char *oct)
{
	int op, i, j, octa, limit;

	oct[22] = '\0';
	for (i = 63, octa = 21; i >= 0; i--, octa--)
	{
		if (i > 0)
			limit = 4;
		else
			limit = 1;
		for (op = 0, j = 1; j <= limit; j *= 2, i--)
			op = ((bnr[i] - '0') * j) + op;
		i++;
		oct[octa] = op + '0';
	}
	return (oct);
}
