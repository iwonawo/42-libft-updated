/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_base_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:26:41 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 15:30:28 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The ft_u_base_putnbr function prints an unsigned integer in a given base.

	Parameters:
	n - The input unsigned integer value to be printed.
	base - The base in which the number will be printed.
	fd - The file descriptor where the output will be written.

	Return:
	The total number of characters printed.

	Description:
	The ft_u_base_putnbr function recursively prints the input unsigned integer
	n in the specified base using the provided character set base. It calculates
	the length of the base using ft_strlen, and then checks if n is greater than
	or equal to the base length. If so, it recursively divides n by the base
	length and calls itself for the quotient and the remainder.
	If n is smaller than the base length, it writes the corresponding character
	from the base character set to the file descriptor using the write function.
	The function also calculates the number of characters printed in nbr_len
	by calling the ft_unbrlen_base function.
	Finally, it returns the total number of characters printed (nbr_len).

	Example:
	ft_u_base_putnbr(255, "0123456789ABCDEF", 1);
	prints "FF" to the standard output (assuming fd=1)
	ft_u_base_putnbr(12345, "0123456789", 2);
	prints "11000000111001" to the standard error (assuming fd=2)
*/
int	ft_u_base_putnbr(unsigned long long int n, const char *base)
{
	unsigned long long int	base_len;
	int						nbr_len;

	nbr_len = 0;
	base_len = ft_strlen(base);
	if (n >= base_len)
	{
		ft_u_base_putnbr(n / base_len, base);
		ft_u_base_putnbr(n % base_len, base);
	}
	else
		write(1, &base[n], 1);
	nbr_len += ft_u_base_nbrlen(n, base_len);
	return (nbr_len);
}
