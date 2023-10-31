/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 15:14:35 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 14:26:35 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The ft_printf function prints formatted output to the standard output.

	Parameters:
	str - The input null-terminated string containing the format specifier.
	... - Optional arguments to be formatted based on the format specifier.

	Return:
	The total number of characters written to the standard output.

	Description:
	The ft_printf function prints formatted output to the standard output
	according to the format specifier in the input string str. It supports
	several format specifiers:

	Format Specifiers:
	- %c: Print a single character.
	- %s: Print a null-terminated string.
	- %d or %i: Print a signed integer.
	- %X or %x: Print an unsigned integer in hexadecimal format.
	- %p: Print the address of a pointer in hexadecimal format.
	- %u: Print an unsigned integer in decimal format.
	- %%: Print a percent sign '%'.

	The function uses a variable number of arguments indicated by '...'. The
	format specifier is used to determine the type of each argument to be
	printed.
	For example, %d expects an integer argument, %s expects a string argument,
	etc.

	The function processes the format specifier and corresponding arguments
	and prints the formatted output to the standard output using the specified
	file descriptor. It returns the total number of characters written to the
	standard output.

	Example:
	ft_printf("Hello, %s!", "world");
	prints "Hello, world!" to the standard output.
	ft_printf("The value is %d and the address is %p", 42, &variable);
	prints "The value is 42 and the address is 0x7fffd96e6e68" (address may  be
	different - specific to systems).
	ft_printf("Hexadecimal: %X, Decimal: %u", 255, 12345);
	prints "Hexadecimal: FF, Decimal: 12345" to the standard output.
*/
static int	ft_formatcheck(va_list args, const char format)
{
	unsigned long long int	ptr;

	if (format == 'c')
		return (ft_putchar_pf(va_arg(args, int)));
	else if (format == 's')
		return (ft_putstr_pf(va_arg(args, char *)));
	else if (format == 'd' || format == 'i')
		return (ft_putnbr_pf(va_arg(args, int)));
	else if (format == 'X' || format == 'x')
		return (ft_u_puthexa_pf(va_arg(args, unsigned int), format));
	else if (format == 'p')
	{
		ptr = va_arg(args, unsigned long);
		if (ptr)
			return (ft_u_puthexa_pf(ptr, format));
		return (ft_putstr("0x0"));
	}
	else if (format == 'u')
		return (ft_u_base_putnbr_pf(va_arg(args, unsigned int), "0123456789"));
	else if (format == '%')
		return (ft_putchar_pf('%'));
	else
		return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		length;

	i = 0;
	length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr_pf("cspdiuxX%", str[i + 1]) != 0)
		{
			length += ft_formatcheck(args, str[i + 1]);
			i++;
		}
		else
			length += ft_putchar_pf(str[i]);
		i++;
	}
	va_end(args);
	return (length);
}
