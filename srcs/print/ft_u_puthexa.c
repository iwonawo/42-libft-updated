/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_puthexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 11:26:41 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 15:32:36 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The ft_u_puthexa function writes an unsigned long long integer
	in hexadecimal format to a standard output.

	Parameters:
	n - The input unsigned long long integer value to be written.
	format - The format character.

	Return:
	The total number of characters written to the standard output.

	Description:
	The ft_u_puthexa function writes the input unsigned long long integer n
	in hexadecimal format to the specified standard output fd. The format
	character determines whether the output should be in uppercase or lowercase.
	If the format is 'p', the function writes the prefix "0x" to the file
	descriptor and increments the count of characters written by 2 (nbr_len).
	If the format is 'X', the function uses the base "0123456789ABCDEF" for
	uppercase hexadecimal conversion. For lowercase format, it uses the base
	"0123456789abcdef". The base length is calculated using ft_strlen.
	If n is greater than or equal to 16, the function recursively calls itself
	with the quotient and remainder of n divided by 16 to write each digit
	individually.
	If n is less than 16, the function writes the corresponding character from
	the base character set to the standard output.
	The function also calculates the number of characters written in nbr_len
	by calling the ft_unbrlen_base function.
	Finally, it returns the total number of characters written (nbr_len).

	Example:
	ft_u_puthexa(255, 'x', 1);
	writes "ff" to the standard output (assuming fd=1)
	ft_u_puthexa(12345, 'X', 2);
	writes "3039" to the standard error (assuming fd=2)
	ft_u_puthexa(0xABCDEF, 'p', 1);
	writes "0xABCDEF" to the standard output (assuming fd=1)
*/
int	ft_u_puthexa(unsigned long long int n, char format)
{
	char			*base;
	int				nbr_len;
	unsigned int	base_len;

	nbr_len = 0;
	if (format == 'p')
	{
		write(1, "0x", 2);
		nbr_len += 2;
	}
	if (format == 'X')
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	base_len = ft_strlen(base);
	if (n >= base_len)
	{
		ft_u_base_putnbr(n / 16, base);
		ft_u_base_putnbr(n % 16, base);
	}
	else
		write(1, &base[n], 1);
	nbr_len += ft_u_base_nbrlen(n, base_len);
	return (nbr_len);
}
