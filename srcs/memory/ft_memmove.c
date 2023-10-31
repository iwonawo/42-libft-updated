/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:35:39 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 14:13:12 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The ft_memmove function copies a block of memory from the source
	to the destination, handling overlapping memory regions.

	Parameters:
	dest - A pointer to the destination memory block.
	src - A pointer to the source memory block.
	n - The number of bytes to copy.

	Return:
	A pointer to the destination memory block.

	Description:
	The ft_memmove function takes a pointer to the destination memory
	block (dest), a pointer to the source memory block (src), and the
	number of bytes to copy (n).
	- char *ptr_dest and const char *ptr_src: These are pointers to
	characters (bytes) that are used to handle the memory copying.
	- ptr_dest is cast from dest, and ptr_src is cast from src. This allows
	treating the memory as a sequence of bytes.

	The function begins by performing several checks:
	It checks if both dest and src are NULL pointers using the condition if
	(!dest && !src). If both are NULL, it returns dest, ensuring that the
	function does not attempt to copy data from or to NULL pointers.
	It checks if ptr_dest is equal to ptr_src, which would indicate that the
	source and destination memory regions are the same. If they are the same,
	it also returns dest, effectively doing nothing.
	If ptr_dest is greater than ptr_src, it implies that the destination memory
	is located after the source memory in the address space. In this case, it
	enters a while loop:
	The loop decrements n in each iteration and copies bytes from the end of the
	source memory to the end of the destination memory using pointer arithmetic.
	If ptr_dest is less than ptr_src, it implies that the destination memory is
	located before the source memory in the address space. In this case, it
	enters a while loop:
	The loop copies bytes from the beginning of the source memory to the
	beginning of the destination memory using pointer arithmetic. It also
	decrements n in each iteration.
	After either of the loop blocks, the function returns dest, which now holds
	the copied data.
	The approach in this code ensures that memory is copied safely even when
	source and destination memory regions overlap.

	Example:
	char src[] = "Hello";
	char dest[6];
	ft_memmove(dest, src, sizeof(src));
	(The contents of 'src' are copied to 'dest')

	int numbers[] = {1, 2, 3, 4, 5};
	ft_memmove(numbers + 1, numbers, 4 * sizeof(int));
	(The contents of 'numbers' array are shifted to the right by one position)
*/
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*ptr_dest;
	const char	*ptr_src;

	ptr_dest = (char *)dest;
	ptr_src = (const char *)src;
	if (!dest && !src)
		return (dest);
	if (ptr_dest == ptr_src)
		return (dest);
	if (ptr_dest > ptr_src)
	{
		while (n--)
			*(ptr_dest + n) = *(ptr_src + n);
	}
	else
	{
		while (n)
		{
			*ptr_dest++ = *ptr_src++;
			n--;
		}
	}
	return (dest);
}
