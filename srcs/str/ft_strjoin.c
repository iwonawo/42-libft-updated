/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:49:10 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 17:11:29 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The ft_strjoin function concatenates two strings into a new string.

	Parameters:
	buffer - A pointer to the first string.
	content - A pointer to the second string.

	Return:
	If memory allocation is successful, a pointer to the concatenated string is
	returned.
	If buffer or content is NULL or if memory allocation fails NULL is returned.

	Description:
	The ft_strjoin function takes two parameters: buffer and content. It first
	checks if either buffer or content is NULL. If true, it means one of the
	strings is missing, and the function returns NULL to indicate an error.
	Next, it calls the ft_strnew function to allocate memory for the
	concatenated string. The ft_strnew function is defined as static in the code
	and is responsible for allocating memory.
	If memory allocation fails, ft_strnew returns NULL, and
	ft_strjoin also returns NULL to indicate an error. If memory allocation is
	successful,ft_strjoin assigns the returned pointer to the str variable and
	increments the str_ptr variable to keep track of the beginning of the
	concatenated string. It then enters a loop that copies characters from s1
	to the new string until a null terminator is encountered in s1. Inside the
	loop, it assigns the value of the current character in s1 to the memory
	location pointed to by str and increments both pointers to move to the next
	character. The loop continues until the end of s1. After copying s1,
	ft_strjoin enters another loop to copy characters from content to the new
	string.
	It performs the same character copying process as in the previous loop. Once
	the end of content is reached, it adds a null terminator at the end of the
	concatenated string to ensure proper termination. Finally, ft_strjoin
	returns the str_ptr pointer, which points to the beginning of the
	concatenated string. The function is useful when you need to combine two
	strings into a new string.

	Example:
	char str1[] = "Hello, ";
	char str2[] = "World!";
	char *result = ft_strjoin(str1, str2);
	(The function concatenates "Hello, " and "World!" into a new string "Hello,
	World!")

	char *missing_string = ft_strjoin(NULL, str2);
	(The function returns NULL as one of the strings is missing)
*/
char	*ft_strjoin(char *buffer, char *content)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!buffer)
		return (ft_strdup(content));
	if (!content)
		return (ft_strdup(buffer));
	i = 0;
	result = (char *)malloc(sizeof(char) * (ft_strlen(buffer)
				+ ft_strlen(content)) + 1);
	if (!result)
		return (NULL);
	while (buffer && buffer[i])
	{
		result[i] = buffer[i];
		i++;
	}
	j = 0;
	while (content && content[j])
		result[i++] = content[j++];
	result[i] = '\0';
	free(buffer);
	return (result);
}
