#include "main.h"

/**
 * _printf - function that convert and print
 * @format: inputted string
 * Return: number of stuffs printed
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, l = 0, buf = 0;
	va_list arguments;
	int (*function)(va_list, char *, unsigned int);
	char *buffer;

	va_start(arguments, format), buffer = malloc(sizeof(char) * 1024);
	if (!format || !buffer || (format[i] == '%' && !format[i + 1]))
		return (-1);
	if (!format[i])
		return (0);
	for (i = 0; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
			{	print_buf(buffer, buf), free(buffer), va_end(arguments);
				return (-1);
			}
			else
			{	function = get_print_func(format, i + 1);
				if (function == NULL)
				{
					if (format[i + 1] == ' ' && !format[i + 2])
						return (-1);
					handl_buf(buffer, format[i], buf), l++, i--;
				}
				else
				{
					l += function(arguments, buffer, buf);
					i += ev_print_func(format, i + 1);
				}
			} i++;
		}
		else
			handl_buf(buffer, format[i], buf), l++;
		for (buf = l; buf > 1024; buf -= 1024)
			;
	}
	print_buf(buffer, buf), free(buffer), va_end(arguments);
	return (l);
}
