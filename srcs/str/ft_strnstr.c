/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:18:29 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 17:34:27 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The ft_strnstr function searches for the first occurrence of a substring
	within a given string, up to a specified length.

	Parameters:
	s1 - A pointer to the string to be searched.
	s2 - A pointer to the substring to search for.
	n - The maximum number of characters to search.

	Return:
	If the substring is found, a pointer to the first occurrence of the
	substring within the string is returned.
	If the substring is not found or if n is zero, NULL is returned.

	Description:
	The ft_strnstr function searches for the first occurrence of the substring
	's2' within the string 's1' up to a specified maximum length 'n'. If 's2' is
	an empty string, the function returns a pointer to the start of 's1'. If 'n'
	is 0 or if 's1' is an empty string the function returns NULL. If 's2' is not
	found within 's1' up to 'n' characters, the function returns NULL. Otherwise
	it returns a pointer to the first occurrence of 's2' within 's1' (up to 'n'
	characters).

	Note: The function searches for a substring within the first 'n' characters
	of the s1 string. If 'n' is greater than the length of the s1,
	it will search the entire s1 string.

	Example:
	char str[] = "Hello, World!";
	char sub[] = "World";
	char *result = ft_strnstr(str, sub, sizeof(str));
	(The function searches for the substring "World" within the string "Hello,
	World!". Since the substring is found, it returns a pointer to the position
	"World!" within the s1)

	char str[] = "Hello, World!";
	char sub[] = "Foo";
	char *result = ft_strnstr(str, sub, sizeof(str));
	(The function searches for the substring "Foo" within the string "Hello,
	World!". Since the substring is not found, it returns NULL)
*/
char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (s2[0] == '\0')
		return ((char *)s1);
	if (n == 0 || s1[i] == '\0')
		return (NULL);
	while (s1[i] != '\0' && i < n)
	{
		j = 0;
		while (s1[i + j] == s2[j] && s1[i + j] != '\0' && (i + j) < n)
		{
			if (s2[j + 1] == '\0')
				return ((char *)&s1[i]);
			j++;
		}
		i++;
	}
	return (NULL);
}
