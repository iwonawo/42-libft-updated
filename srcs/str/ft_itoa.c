/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 15:06:00 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 16:48:13 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The ft_itoa function converts an integer to a string representation.

	Parameters:
	n - The integer to be converted.

	Return:
	A dynamically allocated string representing the converted integer.
	NULL is returned if memory allocation fails.

	Description:
	The ft_itoa function converts the given integer into string representation.
	It first determines the sign of the number by checking if it is negative.
	It calculates the length of the resulting string by counting the number
	of digits in the absolute value of the integer. Memory is allocated to store
	the resulting string, including space for the sign and the null-terminator.
	The conversion is performed by iteratively extracting the digits from the
	integer using modulo and division operations. The digits are then converted
	to characters by adding the ASCII value of '0'. The digits are added to the
	string in reverse order to ensure the correct representation of the number.
	Finally, the sign is added if necessary, the null-terminator is appended,
	and the resulting string is returned.

	Note: The caller is responsible for freeing the dynamically allocated memory
	for the returned string when it is no longer needed.

	Example:
	ft_itoa(12345);
	returns "12345"

	ft_itoa(-456);
	returns "-456"

	ft_itoa(0);
	returns "0"

	ft_itoa(2147483647);
	returns "2147483647" (maximum value of int)

	ft_itoa(-2147483648);
	returns "-2147483648" (minimum value of int)
*/
static int	ft_nbrlen(int n)
{
	int	i;

	i = 1;
	while (n / 10 != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

static char	*ft_strrev_sign(char *s, int sign)
{
	int		start;
	int		end;
	char	temp;

	start = sign;
	end = ft_strlen(s) - 1;
	while (start < end)
	{
		temp = s[start];
		s[start] = s[end];
		s[end] = temp;
		start++;
		end--;
	}
	return (s);
}

static long long	ft_abs(long long n)
{
	long long	nbr;

	nbr = 1;
	if (n < 0)
		nbr *= -n;
	else
		nbr *= n;
	return (nbr);
}

char	*ft_itoa(int n)
{
	char			*res;
	int				i;
	int				size;
	int				sign;
	unsigned int	nbr;

	i = 0;
	sign = 0;
	if (n < 0)
		sign = 1;
	size = ft_nbrlen(n);
	res = (char *)malloc(sizeof(char) * (size + sign + 1));
	if (!res)
		return (NULL);
	nbr = ft_abs(n);
	if (sign)
		res[i++] = '-';
	while (i < size + sign)
	{
		res[i++] = nbr % 10 + '0';
		nbr = nbr / 10;
	}
	res[i] = '\0';
	ft_strrev_sign(res, sign);
	return (res);
}
