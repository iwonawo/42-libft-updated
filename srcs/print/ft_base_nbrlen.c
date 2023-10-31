/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_base_nbrlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:23:21 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 14:28:43 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The ft_base_nbrlen function calculates the number of digits in an integer
	when represented in a given base.

	Parameters:
	n - The input integer value for which the number of digits is calculated.
	base - The base in which the number will be represented.

	Return:
	The number of digits required to represent the integer in the specified base

	Description:
	The ft_base_nbrlen function calculates the number of digits in the input
	integer n when represented in the specified base. It uses a loop to
	repeatedly divide n by the base until n becomes less than the base. It
	increments a counter for each division operation, representing the number of
	digits required to represent n in the given base. The function returns the
	final count, which is the number of digits in the integer when represented
	in the specified base.

	Example:
	ft_base_nbrlen(12345, 10);
	returns 5
	ft_base_nbrlen(-456, 10);
	returns 3
	ft_base_nbrlen(255, 16);
	returns 2
	ft_base_nbrlen(0, 8);
	returns 1
*/
size_t	ft_base_nbrlen(long long int n, size_t base)
{
	size_t	i;

	i = 1;
	while (n >= (long long int)base)
	{
		n /= base;
		i++;
	}
	return (i);
}
