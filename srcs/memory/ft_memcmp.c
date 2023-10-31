/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:16:07 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 13:50:31 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The ft_memcmp function compares two memory areas and returns the difference
	between the first differing byte, if any, or 0 if the memory areas are
	equal.

	Parameters:
	buf1 - A pointer to the first memory area.
	buf2 - A pointer to the second memory area.
	n - The number of bytes to compare.

	Return:
	An integer value indicating the comparison result.
	0 if the memory areas are equal.
	A positive value if the first differing byte in buf1 is greater than the
	corresponding byte in buf2. A negative value if the first differing byte
	in buf1 is less than the corresponding byte in buf2.

	Description:
	The ft_memcmp function takes two pointers, buf1 and buf2, which point to the
	memory areas to be compared, and the number of bytes to compare, n. It
	enters a loop that iterates n times, incrementing each time to reach n
	iterations.
	The purpose of this loop is to compare each byte in the memory areas.
	Inside the loop, it checks if the value at the current byte of
	buf1 is different from the value at the current byte of buf2. If a
	difference is found, it returns the difference between the two bytes.
	Since the return type is int, the difference is calculated by subtracting
	the value at the current byte of buf2 from the value at the current byte
	of buf1. By casting the	pointers to const unsigned char, the function
	ensures that the comparison is done	on a byte-by-byte basis without any sign
	extension issues. After comparing each byte, if no differences are found,
	it means the memory areas are equal, so it returns 0.
	This function can be used to compare arrays, strings, or any other memory
	areas in a generic manner.

	Example:
	char arr1[] = {1, 2, 3};
	char arr2[] = {1, 2, 4};
	int result = ft_memcmp(arr1, arr2, sizeof(arr1));
	(The function compares each byte in arr1 and arr2. Since the third byte is
	different (3 vs. 4), the function returns -1)

	int a = 123;
	int b = 123;
	int result = ft_memcmp(&a, &b, sizeof(int));
	(The function compares the memory area of 'a' and 'b'. Since they have the
	same value, the function returns 0)
*/
int	ft_memcmp(const void *buf1, const void *buf2, size_t n)
{
	size_t				i;
	const unsigned char	*ptr_buf1;
	const unsigned char	*ptr_buf2;

	ptr_buf1 = (const unsigned char *)buf1;
	ptr_buf2 = (const unsigned char *)buf2;
	i = 0;
	while (i < n)
	{
		if (ptr_buf1[i] != ptr_buf2[i])
			return (ptr_buf1[i] - ptr_buf2[i]);
		i++;
	}
	return (0);
}
