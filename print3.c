#include "main.h"

/**
 * fill_oct_array - writes the character c to stdout
 * @bnr: binary array
 * @oct: octal array
 * Return: binary array.
 */
char *fill_oct_array(char *bnr, char *oct)
{
	int op, i, j, octa, lim;

	oct[11] = '\0';
	for (i = 31, octa = 10; i >= 0; i--, octa--)
	{
		if (i > 1)
			lim = 4;
		else
			lim = 2;
		for (op = 0, j = 1; j <= lim; j *= 2, i--)
			op = ((bnr[i] - '0') * j) + op;
		i++;
		oct[octa] = op + '0';
	}
	return (oct);
}


/**
 * fill_short_oct_array - calculates a short octal number
 * @bnr: array where is stored the binary.
 * @oct: array where is stored the octal.
 * Return: binary array.
 */
char *fill_short_oct_array(char *bnr, char *oct)
{
	int p, i, j, octa, lim;

	oct[6] = '\0';
	for (i = 15, octa = 5; i >= 0; i--, octa--)
	{
		if (i > 0)
			lim = 4;
		else
			lim = 1;
		for (p = 0, j = 1; j <= lim; j *= 2, i--)
			p = ((bnr[i] - '0') * j) + p;
		i++;
		oct[octa] = p + '0';
	}
	return (oct);
}
