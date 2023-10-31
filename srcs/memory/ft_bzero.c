/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:15:06 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 13:10:58 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The ft_bzero function sets a block of memory to zero.

	Parameters:
	start - A pointer to the memory block.
	n - The number of bytes to set to zero.

	Return:
	This function does not return a value.

	Description:
	The ft_bzero function takes a pointer to a memory block and the number of
	bytes to set to zero. It treats the memory block as an array of unsigned
	characters (bytes) and iterates through each byte in the block until the
	entire memory block has been set to zero.
	The function modifies the memory directly, effectively zeroing out the
	specified number of bytes starting from the given memory address.

	Example:
	char buffer[10];
	ft_bzero(buffer, sizeof(buffer));
	(All bytes in 'buffer' are set to zero)

	int numbers[5];
	ft_bzero(numbers, 5 * sizeof(int));
	(All bytes in 'numbers' array are set to zero)
*/
void	ft_bzero(void *start, size_t n)
{
	ft_memset(start, 0, n);
}
