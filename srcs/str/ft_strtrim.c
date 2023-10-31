/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:18:49 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 17:33:56 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The ft_strtrim function trims leading and trailing characters from a string
	based on a given set of characters.

	Parameters:
	s1 - A pointer to the string to be trimmed.
	set - A pointer to the set of characters to be trimmed.

	Return:
	If memory allocation is successful and the resulting trimmed string is not
	empty, a pointer to the trimmed string is returned.
	If s1 or set is NULL, or if memory allocation fails, or if the resulting
	trimmed string is empty, NULL is returned.

	Description:
	The ft_strtrim function creates a new string by removing leading and
	trailing characters specified in the 'set' string from the 's1' string.
	The 'set' string defines the characters to be trimmed. The function first
	identifies the start and end positions of the trimmed string by skipping
	over characters in 's1' that are in 'set'. It then allocates memory for the
	new string and copies the trimmed portion of 's1' into the new string. The
	new string is null-terminated. If 's1' or 'set' is NULL, the function
	returns NULL. If no characters need to be trimmed, a new string is created
	with the same content as 's1'.

	Example:
	char str[] = " Hello, World! ";
	char set[] = " ";
	char *trimmed = ft_strtrim(str, set);
	(The function trims leading and trailing spaces from the string " Hello,
	World! ")
	(The resulting trimmed string is "Hello, World!")

	char str[] = " \t\t Welcome to the Jungle \t ";
	char set[] = " \t";
	char *trimmed = ft_strtrim(str, set);
	(The function trims leading and trailing spaces and tabs from the string "
	\t\t Welcome to the Jungle \t ")
	(The resulting trimmed string is "Welcome to the Jungle")

	char str[] = "NoTrimmingNeeded";
	char set[] = " ";
	char *trimmed = ft_strtrim(str, set);
	(The function does not perform any trimming as there are no leading or
	trailing spaces in the string "NoTrimmingNeeded")
	(The resulting trimmed string is the same as the original string
	"NoTrimmingNeeded")
*/
static	size_t	find_char(char const *str, char const c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (i < ft_strlen(str))
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	start;
	size_t	end;
	size_t	len;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] != '\0' && find_char(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > start && find_char(set, s1[end - 1]))
		end--;
	len = end - start;
	trimmed = (char *)malloc(sizeof(char) * len + 1);
	if (!trimmed)
		return (NULL);
	ft_strlcpy(trimmed, s1 + start, len + 1);
	return (trimmed);
}
