/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:17:54 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 17:14:47 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The ft_strlcat function appends a string from the source to the destination
	with a specified size limit, ensuring proper null termination.

	Parameters:
	dest - A pointer to the destination string.
	src - A pointer to the source string.
	size - The size limit of the destination buffer.

	Return:
	The total length of the concatenated string.

	Description:
	The ft_strlcat function takes a pointer to the destination string (dest),
	a pointer to the source string (src), and the size limit of the
	destination buffer (size).

	The ft_strlcat function concatenates the contents of the source string
	'src' to the destination string 'dest' while ensuring that the total
	resulting string length does not exceed the specified 'size'. It
	appends as much of 'src' as will fit in 'dest', and always null-terminates
	the result. If 'size' is 0 or 'dest' already contains more than or equal
	to 'size' characters, the function returns 'size + ft_strlen(src)' without
	modifying 'dest'.

	Note: The function assumes that the destination buffer has enough space to
	accommodate at least 'n' characters plus the null terminator. Otherwise, it
	may lead to buffer overflow.

	Example:
	char dest[10] = "Hello";
	char src[] = " World";
	ft_strlcat(dest, src, sizeof(dest));
	(The strings "Hello" and " World" are concatenated, resulting in "Hello
	Worl" with proper null termination)

	char dest[5] = "Test";
	char src[] = "12345";
	ft_strlcat(dest, src, sizeof(dest));
	(The strings "Test" and "12345" are concatenated, but only "Test" is stored
	due to size limit, resulting in "Test" with proper null termination)
*/
size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	src_len;

	src_len = ft_strlen(src);
	if (!dest && !size)
		return (src_len);
	dest_len = ft_strlen(dest);
	if (size == 0 || dest_len >= size)
		return (size + src_len);
	i = 0;
	while (src[i] != '\0' && i < size - dest_len - 1)
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
