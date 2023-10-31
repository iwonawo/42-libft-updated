/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:16:18 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 14:03:12 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The ft_memcpy function copies a block of memory from the source to the
	destination.

	Parameters:
	dest - A pointer to the destination memory block.
	src - A pointer to the source memory block.
	n - The number of bytes to copy.

	Return:
	A pointer to the destination memory block.

	Description:
	The ft_memcpy function takes a pointer to the destination memory block
	(dest), a pointer to the source memory block (src), and the number of bytes
	to copy (n). It starts by assigning the value of 'dest' and 'src' to
	'ptr_dest' and 'ptr_src' to	keep track of the original destination and
	source pointers. 'i' variable is used to keep track of the current index
	during the copy operation.
	Then, it checks if both 'dest' and 'src' pointers are not NULL. This check
	ensures that the function does not attempt to copy data from or to NULL
	pointers. If either of them is NULL, it returns the 'dest' pointer as it
	indicates an invalid operation.
	Otherwise, it enters a loop that iterates 'n' times, copying each
	byte from the source to the destination.
	Inside the loop, it copies one byte at a time from src to dest by assigning
	ptr_src[i] to ptr_dest[i]. This effectively copies n bytes of data from the
	source to the destination memory.
	After the loop has completed, the function returns dest, which now holds
	the copied data.

	Example:
	char src[] = "Hello";
	char dest[6];
	ft_memcpy(dest, src, sizeof(src));
	(The contents of 'src' are copied to 'dest')

	int numbers[] = {1, 2, 3, 4, 5};
	int copy[5];
	ft_memcpy(copy, numbers, 5 * sizeof(int));
	(The contents of 'numbers' array are copied to 'copy' array)
*/
void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*ptr_dest;
	const unsigned char	*ptr_src;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (const unsigned char *)src;
	i = 0;
	if (!dest && !src)
		return (dest);
	while (i < n)
	{
		ptr_dest[i] = ptr_src[i];
		i++;
	}
	return (dest);
}
