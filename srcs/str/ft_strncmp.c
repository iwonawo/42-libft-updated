/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 17:01:03 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 17:35:09 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The ft_strncmp function compares two strings up to a specified length.

	Parameters:
	s1 - A pointer to the first string.
	s2 - A pointer to the second string.
	n - The maximum number of characters to compare.

	Return:
	If the strings are equal, 0 is returned.
	If s1 is less than s2, a negative value is returned.
	If s1 is greater than s2, a positive value is returned.

	Description:
	The ft_strncmp function compares the contents of two strings 's1' and 's2'
	up to a specified maximum length 'n'. It returns an integer value that
	indicates the relationship between the two strings. If 'n' is 0 the function
	returns 0 to indicate that the strings are equal. Otherwise, it compares
	characters from 's1' and 's2' up to 'n' characters or until null-terminator
	is encountered in either string. The comparison is done using unsigned char
	to ensure correct handling of special characters and to avoid signedness
	issues.

	Example:
	char str1[] = "Hello";
	char str2[] = "World";
	int result = ft_strncmp(str1, str2, sizeof(str1));
	(The function compares the strings "Hello" and "World" up to the length of
	str1. Since the first characters ('H' and 'W') are different, it returns a
	negative value)

	char str1[] = "Hello";
	char str2[] = "Hella";
	int result = ft_strncmp(str1, str2, sizeof(str1));
	(The function compares the strings "Hello" and "Hella" up to the length of
	str1. Since the fifth character ('o') is greater than the corresponding
	character ('a'), it returns a positive value)
*/
int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while ((unsigned char)s1[i] == (unsigned char)s2[i]
		&& s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
	{
		i++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
