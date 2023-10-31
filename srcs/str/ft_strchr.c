/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:47:08 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 16:53:21 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The ft_strchr function searches for the first occurrence of a specific
** character in a string.
**
** Parameters:
** str - A pointer to the input string.
** c - The character to be searched for.
**
** Return:
** A pointer to the first occurrence of the character in the string.
** NULL if the character is not found.
**
** Description:
** The ft_strchr function takes a pointer to the input string 'str' and an
** integer 'c' which represents a character. It enters a loop that iterates
** until it reaches the end of the string, identified by a null terminator
** character ('\0'). In each iteration, it checks if the current character
** in the string is equal to the character 'c' being searched for. If a match
** is found, it returns a pointer to that character in the string. If no match
** is found until the end of the string, it checks if the last character is
** equal to 'c'. This check is necessary because the loop exits before checking
** the last character. If the last character matches 'c', it returns a pointer
** to that character. If no match is found, it means the character 'c' is not
** present in the string, so it returns NULL.
**
** Example:
** char str[] = "Hello, World!";
** char *ptr = ft_strchr(str, 'W');
** (ptr points to the first occurrence of 'W' in the string "Hello, World!")
**
** char str[] = "Hello, World!";
** char *ptr = ft_strchr(str, 'Z');
** (ptr is NULL as 'Z' is not found in the string "Hello, World!")
*/
char	*ft_strchr(const char *str, int c)
{
	size_t	i;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}
