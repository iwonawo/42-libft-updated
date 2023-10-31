/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:18:37 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 17:34:15 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The ft_strrchr function searches for the last occurrence of a specific
	character in a string.

	Parameters:
	str - A pointer to the input string.
	c - The character to be searched for.

	Return:
	A pointer to the last occurrence of the character in the string.
	NULL if the character is not found.

	Description:
	The ft_strrchr function searches for the last occurrence of the character
	'c' in the string 'str'. It starts searching from the end of the string and
	works towards the beginning. If 'c' is found in 'str', a pointer to the last
	occurrence of 'c' is returned. If 'c' is not found in 'str', the function
	returns NULL. If 'c' is the null-terminator character ('\0'), the function
	returns a pointer to the null-terminator character at the end of 'str'.

	Example:
	char str[] = "Hello, World!";
	char *ptr = ft_strrchr(str, 'o');
	(ptr points to the last occurrence of 'o' in the string "Hello, World!")

	char str[] = "Hello, World!";
	char *ptr = ft_strrchr(str, 'Z');
	(ptr is NULL as 'Z' is not found in the string "Hello, World!")
*/
char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	i = len;
	while (i > 0)
	{
		i--;
		if (str[i] == (char)c)
			return ((char *)&str[i]);
	}
	if ((char)c == '\0')
		return ((char *)&str[len]);
	return (NULL);
}
