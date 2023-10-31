/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:15:19 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 13:37:18 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The ft_calloc function allocates and initializes memory for an array of
	elements.

	Parameters:
	count - The number of elements to allocate.
	size - The size of each element.

	Return:
	If memory allocation is successful, a pointer to the allocated memory block
	is returned. If either count or size is zero or if memory allocation fails,
	NULL is returned.

	Description:
	The ft_calloc function takes two parameters: count and size. It first
	performs a check to ensure that the product of count and size does not
	overflow the size_t type. If the check fails, it returns NULL to indicate
	an error.
	Next it calls the malloc function to allocate memory for count * size bytes.
	If memory allocation fails, malloc returns NULL, and ft_calloc also returns
	NULL to indicate an error. If memory allocation is successful, it calls the
	ft_memset function to initialize the allocated memory block to all zeros.
	The ft_memset function is defined as a static function in the code and sets
	each byte of the memory block to zero. Finally, ft_calloc returns the
	pointer to the allocated and initialized memory block.
	This function is useful when you need to allocate memory for an array and
	initialize it to a specific value, such as zeroing out a buffer or
	allocating memory for an array of structures.

	Example:
	int *numbers = ft_calloc(5, sizeof(int));
	(The function allocates memory for an array of 5 integers and initializes
	the memory to zeros)

	char *buffer = ft_calloc(10, sizeof(char));
	(The function allocates memory for a buffer of 10 characters and initializes
	the memory to zeros)

	int *empty_array = ft_calloc(0, sizeof(int));
	(The function returns NULL as count is zero, indicating an error)
*/
void	*ft_calloc(size_t count, size_t size)
{
	void	*res;

	if (size && (count > SIZE_MAX / size))
		return (NULL);
	res = (void *)malloc(count * size);
	if (!res)
		return (NULL);
	ft_memset(res, 0, count * size);
	return (res);
}
