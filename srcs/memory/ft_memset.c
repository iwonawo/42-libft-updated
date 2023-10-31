/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:16:30 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 13:29:09 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The ft_memset function fills a block of memory with a specified value.

	Parameters:
	dest - A pointer to the block of memory to be filled.
	c - The value to be set.
	n - The number of bytes to be set.

	Return:
	A pointer to the memory block after it has been filled.

	Description:
	The ft_memset function takes three parameters: dest, c, and n. It starts by
	assigning the value of dest to a variable ptr_dest to keep track of the
	original pointer. It enters a loop that iterates n times, decrementing n in
	each iteration. The purpose of this loop is to fill each byte of the memory
	block with the value c. Inside the loop, it casts the dest pointer to an
	unsigned char pointer to ensure correct assignment on a byte-by-byte basis.
	It assigns the value of c to the current byte by dereferencing the pointer.
	It then increments the dest pointer to move to the next byte. After filling
	all the bytes, it returns the dest, which now points to the memory block
	after it has been filled with the specified value.
	This function is commonly used to initialize memory or set memory regions
	to a specific value, such as setting an array of characters to null
	terminators or setting an array of integers to zeros.

	Example:
	char str[] = "Hello World!";
	ft_memset(str + 3, '.', 6*sizeof(char));
	(result: Hel......ld!)

	int numbers[5];
	ft_memset(numbers, 0, sizeof(numbers));
	(The function fills the numbers array with zeros, resulting in
	[0, 0, 0, 0, 0])
*/
void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*ptr_dest;

	ptr_dest = dest;
	while (n--)
		*ptr_dest++ = (unsigned char)c;
	return (dest);
}
