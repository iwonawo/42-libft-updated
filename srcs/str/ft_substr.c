/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:36:36 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 17:37:24 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The ft_substr function creates a substring from a given string.

	Parameters:
	s - A pointer to the source string.
	start - The starting index of the substring in the source string.
	len - The maximum length of the substring.

	Return:
	If memory allocation is successful or if len is zero, a pointer to the
	allocated substring is returned.
	If s is NULL or if memory allocation fails, NULL is returned.

	Description:
	The ft_substr function creates a new string (substring) from the input
	string 's'. The substring starts at the position specified by 'start' and
	has a maximum length of 'len'. If 's' is NULL, the function returns NULL.
	If 'start' is greater than or equal to the length of 's', an empty string
	is created. If 'len' is greater than the remaining characters in 's' from
	'start' to the end, the substring's length is adjusted accordingly. The new
	substring is null-terminated and dynamically allocated. The caller is
	responsible for freeing the memory allocated for the substring.

	Example:
	char str[] = "Hello, World!";
	char *substring = ft_substr(str, 7, 5);
	(The function creates a substring "World" starting from index 7 of the
	source string)

	char *empty_substring = ft_substr(NULL, 0, 10);
	(The function returns NULL as the source string is NULL)
*/
char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*substring;
	unsigned int	i;
	size_t			s_len;

	if (!s)
		return (NULL);
	i = 0;
	s_len = ft_strlen(s);
	if (start >= s_len)
		len = 0;
	else if (len > s_len - start)
		len = s_len - start;
	substring = (char *)malloc(sizeof(char) * (len + 1));
	if (!substring)
		return (NULL);
	while (i < len)
	{
		substring[i] = s[start];
		i++;
		start++;
	}
	substring[i] = '\0';
	return (substring);
}
