/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:16:48 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 14:40:11 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The ft_putendl_fd function writes a string followed by a newline character
	to a specified file descriptor.

	Parameters:
	s - A pointer to the string to be written.
	fd - The file descriptor where the string will be written.

	Return:
	None.

	Description:
	The ft_putendl_fd function writes the contents of a string to the specified
	file descriptor, followed by a newline character ('\n'). It uses the write
	system call to write the string and newline character to the file
	descriptor. The function assumes that the write operation will be successful
	and does not include explicit error handling.

	Note:
	It's important to ensure that the file descriptor is valid and open for
	writing before calling this function to avoid unexpected behavior or errors.

	Example:
	char str[] = "Hello, World!";
	ft_putendl_fd(str, 1);
	The string "Hello, World!" followed by a newline character will be written
	to the standard output (STDOUT_FILENO).

	char error[] = "Error: File not found";
	ft_putendl_fd(error, 2);
	The string "Error: File not found" followed by a newline character will be
	written to the standard error (STDERR_FILENO).

	ft_putendl_fd("Hello", 0);
	The string "Hello" followed by a newline character will be written to the
	standard input (STDIN_FILENO).
	(Note: The string will not be visible on the terminal since it is an input
	stream)
*/
void	ft_putendl_fd(char *s, int fd)
{
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
