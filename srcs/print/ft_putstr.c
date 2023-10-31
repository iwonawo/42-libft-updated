/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:17:04 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 15:28:55 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The ft_putstr function writes a null-terminated string to the standard
	output.

	Parameters:
	s - A pointer to the null-terminated string to be written.

	Return:
	The length of the number of characters printed.

	Description:
	The ft_putstr function takes a null-terminated string 's' as its
	parameter and writes it to the standard output (usually the console
	or terminal). It achieves this by calling the write function
	with the string 's' and file descriptor 1 (which corresponds to the
	standard output stream). The result is that the string is displayed
	on the screen.

	Example:
	ft_putstr("Hello, world!");
	Outputs "Hello, world!" to the terminal.
	ft_putstr("Text line 1");
	ft_putstr("Text line 2");
	Outputs "Text line 1" and "Text line 2" sequentially.
*/
int	ft_putstr(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
		i++;
	return (write(1, s, i));
}
