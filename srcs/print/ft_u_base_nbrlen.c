/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_u_base_nbrlen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 16:23:21 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 15:29:33 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The ft_u_base_nbrlen function calculates the length of an unsigned integer
	when represented as a string in a given base.

	Parameters:
	n - The input unsigned integer value for which the length is calculated.
	base - The base in which the number will be represented as a string.

	Return:
	The length of the number when represented as a string in the specified base.

	Description:
	The ft_u_base_nbrlen function calculates the length of the input unsigned
	integer n when represented as a string in the specified base. It uses a loop
	to repeatedly divide n by the base until n becomes less than the base. It
	increments a counter for each division operation, representing the number of
	digits required to represent n in the given base. The function returns the
	final count, which is the length of the number in the specified base.

	Example:
	ft_u_base_nbrlen(12345, 10);
	returns 5
	ft_u_base_nbrlen(255, 16);
	returns 2
	ft_u_base_nbrlen(0, 8);
	returns 1
*/
size_t	ft_u_base_nbrlen(unsigned long long int n, size_t base)
{
	size_t	i;

	i = 1;
	while (n >= (unsigned long long int)base)
	{
		n /= base;
		i++;
	}
	return (i);
}
