/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:31:08 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 16:47:41 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The ft_atoi function converts a string representation of an integer to
	its corresponding integer value.

	Parameters:
	str - A pointer to the input string.

	Return:
	The integer value obtained from the input string.

	Description:
	The ft_atoi function scans the input string and converts it to an
	integer. It skips any leading whitespace characters by advancing the
	pointer. If a plus (+) or minus (-) sign is encountered, it determines
	the sign of the number and advances the pointer. Then, it processes
	each digit character and calculates the corresponding integer value.
	It performs checks to prevent overflow by comparing the current value
	with the previous value multiplied by the sign. If an overflow occurs,
	it returns 0 if the sign is positive or -1 if the sign is negative.
	Finally, it returns the resulting integer value.

	Example:
	ft_atoi("12345");
	returns 12345

	ft_atoi("-456");
	returns -456

	ft_atoi("2147483647");
	returns 2147483647 (maximum value of int)

	ft_atoi("99999999999999999999");
	returns -1 (exceeds 20 digits with positive sign)
*/
static void	ft_sign(const char c, int *sign)
{
	if (c == '-')
		*sign = *sign * -1;
}

static long long int	ft_result(const char *str, long long int i, int sign)
{
	long long int	res;
	long long int	temp;

	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = res;
		res = (res * 10) + sign * (str[i] - '0');
		if (res > temp && sign < 0)
			return (0);
		if (res < temp && sign > 0)
			return (-1);
		i++;
	}
	return (res);
}

long	ft_atoi(const char *str)
{
	long long int	i;
	int				sign;
	long long int	result;

	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		ft_sign(str[i], &sign);
		i++;
	}
	while (str[i] == '0')
		i++;
	result = ft_result(str, i, sign);
	return (result);
}
