/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/14 13:27:48 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 16:52:38 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The ft_split function splits a string into an array of substrings
	based on a given delimiter character.

	Parameters:
	s - A pointer to the null-terminated string to be split.
	c - The delimiter character used for splitting.

	Return:
	A dynamically allocated array of pointers to the resulting substrings,
	or NULL if memory allocation fails or 's' is NULL.

	Description:
	The ft_split function takes a null-terminated string 's' and a
	delimiter character 'c' as its parameters. It breaks down the string
	's' into multiple substrings using the delimiter 'c', and stores each
	substring in a dynamically allocated array. The resulting array is
	terminated with a NULL pointer to mark its end.

	The function first calculates the number of substrings to be created
	by calling the ft_words_count function. This function scans 's' to
	determine how many words (substrings) can be found, separated by 'c'.

	The function then dynamically allocates memory for an array of pointers
	to hold the substrings, using the words count plus one (for the NULL
	terminator). If memory allocation fails, the function returns NULL.

	The function then proceeds to populate the array with pointers to
	dynamically allocated substrings using the ft_words function. This
	function iterates through 's', creating substrings between 'c' delimiters
	and storing them in the array. If memory allocation fails during this
	process, the previously allocated memory is freed and NULL is returned.

	After all substrings have been processed and stored in the array, the
	last element of the array is set to NULL to mark the end.

	It's important to note that memory allocated for the substrings and
	the array should be freed by the user when they are no longer needed,
	using a loop to free each substring and then the array itself.

	Example:
	const char *str = "Hello,World,Split,Me";
	char **split_array = ft_split(str, ',');
	(The string "Hello,World,Split,Me" is split into substrings using ',' as
	the delimiter)
	(The resulting split_array will contain the substrings ["Hello", "World",
	"Split", "Me", NULL])
	(The last element of the array is set to NULL to indicate the end of the
	array)

	const char *str = "Lorem ipsum dolor sit amet";
	char **split_array = ft_split(str, ' ');
	(The string "Lorem ipsum dolor sit amet" is split into substrings using ' '
	(space) as the delimiter)
	(The resulting split_array will contain the substrings ["Lorem", "ipsum",
	"dolor", "sit", "amet", NULL])

	const char *str = "apple,banana,cherry,orange";
	char **split_array = ft_split(str, ',');
	(The string "apple,banana,cherry,orange" is split into substrings using ','
	as the delimiter)
	(The resulting split_array will contain the substrings ["apple", "banana",
	"cherry", "orange", NULL])

	const char *str = "123-456-789-0";
	char **split_array = ft_split(str, '-');
	(The string "123-456-789-0" is split into substrings using '-' as the
	delimiter)
	(The resulting split_array will contain the substrings ["123", "456", "789",
	"0", NULL])
*/
static size_t	ft_words_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != '\0' && s[i] != c)
				i++;
		}
		else if (s[i] == c)
			i++;
	}
	return (count);
}

static size_t	ft_word_len(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static void	free_array(size_t i, char **array)
{
	while (i > 0)
	{
		i--;
		free(array[i]);
	}
	free(array);
}

static char	**split(char const *s, char c, char **array, size_t words_count)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < words_count)
	{
		while (s[j] != '\0' && s[j] == c)
			j++;
		array[i] = ft_substr(s, j, ft_word_len(&s[j], c));
		if (!array[i])
		{
			free_array(i, array);
			return (NULL);
		}
		while (s[j] != '\0' && s[j] != c)
			j++;
		i++;
	}
	array[i] = NULL;
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;
	size_t	words_count;

	if (!s)
		return (NULL);
	words_count = ft_words_count(s, c);
	array = (char **)malloc(sizeof(char *) * (words_count + 1));
	if (!array)
		return (NULL);
	array = split(s, c, array, words_count);
	return (array);
}
