/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:16:55 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 15:23:46 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The ft_putnbr_fd function writes an integer to a given file descriptor.

	Parameters:
	n - The integer to be written.
	fd - The file descriptor to write the integer to.

	Return:
	None.

	Description:
	The ft_putnbr_fd function writes the input long long integer n to the
	specified file descriptor fd. It uses a base of "0123456789" to convert the
	number to its string representation. The function first handles the special
	case where n is equal to LLONG_MIN (-9223372036854775808). In this case,
	it writes the string "-9223372036854775807" to the file descriptor and
	returns 20 (the length of the string).
	If n is negative, the function writes a '-' character to the file descriptor
	and calls itself recursively with the positive value of n. It keeps track of
	the number of characters written in nbr_len.
	If n is greater than or equal to 10, the function recursively calls itself
	with the quotient and remainder of n divided by 10 to write each digit
	individually.
	If n is a single digit (0 to 9), the function writes the corresponding
	character from the base character set to the file descriptor.

	Example:
	ft_putnbr_fd(12345, 1);
	Writes "12345" to the standard output.
	int file_fd = open("output.txt", O_WRONLY);
	ft_putnbr_fd(-42, file_fd);
	Writes "-42" to the file "output.txt".
	close(file_fd);
*/
void	ft_putnbr_fd(long long int n, int fd)
{
	const char	*base;

	base = "0123456789";
	if (n == LLONG_MIN)
	{
		write(1, "-9223372036854775807", 20);
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = n * -1;
		ft_putnbr_fd(n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd((n / 10), fd);
		ft_putnbr_fd((n % 10), fd);
	}
	else
		write(fd, &base[n], 1);
}
