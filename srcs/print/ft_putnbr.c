/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:16:55 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 15:24:38 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The ft_putnbr function writes an integer to the standard output.

	Parameters:
	n - The integer to be written.

	Return:
	None.

	Description:
	The ft_putnbr function writes the input long long integer n to the
	standard output fd. It uses a base of "0123456789" to convert the
	number to its string representation. The function first handles the special
	case where n is equal to LLONG_MIN (-9223372036854775808). In this case,
	it writes the string "-9223372036854775807" to the standard output and
	returns 20 (the length of the string).
	If n is negative, the function writes a '-' character to the standard output
	and calls itself recursively with the positive value of n. It keeps track of
	the number of characters written in nbr_len.
	If n is greater than or equal to 10, the function recursively calls itself
	with the quotient and remainder of n divided by 10 to write each digit
	individually.
	If n is a single digit (0 to 9), the function writes the corresponding
	character from the base character set to the standard output.

	Example:
	ft_putnbr(12345);
	Outputs "12345" to the terminal.
	ft_putnbr(-42);
	Outputs "-42" to the terminal.
*/
int	ft_putnbr(long long int n)
{
	const char	*base;
	int			nbr_len;

	nbr_len = 0;
	base = "0123456789";
	if (n == LLONG_MIN)
	{
		write(1, "-9223372036854775807", 20);
		return (20);
	}
	if (n < 0)
	{
		write(1, "-", 1);
		nbr_len += ft_putnbr(-n);
	}
	else if (n >= 10)
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
	else
		write(1, &base[n], 1);
	nbr_len += ft_base_nbrlen(n, ft_strlen(base));
	return (nbr_len);
}
