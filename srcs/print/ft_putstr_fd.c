/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:17:04 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 15:27:25 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The ft_putstr_fd function writes a string to a specified file descriptor.

	Parameters:
	s - A pointer to the string to be written.
	fd - The file descriptor where the string will be written.

	Return:
	None.

	Description:
	The ft_putstr_fd function writes the contents of a string to the specified
	file descriptor. It uses the ft_putchar_fd function to write the string to
	the file descriptor. The function assumes that the write operation will be
	successful and does not include explicit error handling.

	Note:
	It's important to ensure that the file descriptor is valid and open for
	writing before calling this function to avoid unexpected behavior or errors.

	Example:
	char str[] = "Hello, World!";
	ft_putstr_fd(str, 1);
	The string "Hello, World!" will be written to the standard output
	(STDOUT_FILENO).

	char error[] = "Error: File not found";
	ft_putstr_fd(error, 2);
	The string "Error: File not found" will be written to the standard error
	(STDERR_FILENO).

	ft_putstr_fd("Hello", 0);
	The string "Hello" will be written to the standard input (STDIN_FILENO).
	(Note: The string will not be visible on the terminal since it is an input
	stream)
*/
void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			ft_putchar_fd(s[i], fd);
			i++;
		}
	}
}
