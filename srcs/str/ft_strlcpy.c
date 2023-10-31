/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:18:03 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 17:18:39 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The ft_strlcpy function copies a string from the source to the destination
	with a specified size limit.

	Parameters:
	dest - A pointer to the destination string.
	src - A pointer to the source string.
	n - The size limit of the destination buffer.

	Return:
	The length of the source string.

	Description:
	The ft_strlcpy function copies the contents of the source string 'src' to
	the destination string 'dest' while ensuring that the copy does not exceed
	the specified size 'n'. It copies as much of 'src' as will fit in 'dest'
	(up to 'n' - 1 characters), and always null-terminates the result. If 'n' is
	0, the function returns the length of 'src' without modifying 'dest'.

	Note: The function assumes that the destination buffer has enough space to
	accommodate at least 'n' characters plus the null terminator. Otherwise,
	it may lead to buffer overflow.

	Example:
	char src[] = "Hello";
	char dest[6];
	ft_strlcpy(dest, src, sizeof(dest));
	(The string "Hello" is copied to 'dest' with proper null termination)

	char src[] = "This is a very long string";
	char dest[10];
	ft_strlcpy(dest, src, sizeof(dest));
	(The string "This is " is copied to 'dest' with proper null termination due
	to size limit)
*/
size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t	i;
	size_t	srclen;

	i = 0;
	srclen = ft_strlen(src);
	if (n == 0)
		return (srclen);
	while (src[i] != '\0' && i < n - 1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (srclen);
}
