/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:45:47 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 17:20:49 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The ft_strlen function calculates the length of a string.

	Parameters:
	str - A pointer to the input string.

	Return:
	The length of the string as a size_t value.

	Description:
	The ft_strlen function takes a pointer to a null-terminated string as input
	and calculates its length. It initializes a variable 'i' to 0 and then
	enters a loop that continues until it encounters a null terminator character
	('\0'). In each iteration, it increments by one. Finally, it
	returns the value of 'i', which represents the length of the string.

	Example:
	ft_strlen("Hello");
	returns 5
	ft_strlen("");
	returns 0
	ft_strlen("12345");
	returns 5
	ft_strlen("This is a long string!");
	returns 22
*/

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}
