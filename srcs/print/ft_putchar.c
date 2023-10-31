/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:16:39 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 14:36:17 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The ft_putchar function writes a single character to the standard output.

	Parameters:
	c - The character to be written.

	Return:
	None.

	Description:
	The ft_putchar function takes a character 'c' as its parameter and
	writes it to the standard output (usually the console or terminal).
	It achieves this by calling the write function with the	pointer to the
	character 'c' and file descriptor 1 (which corresponds to the standard
	output stream). The result is that the character is displayed on the
	screen.

	Example:
	ft_putchar('A');
	Outputs the character 'A' to the terminal.
	ft_putchar('\n');
	Outputs a newline character to move to the next line.
*/
void	ft_putchar(char c)
{
	write(1, &c, 1);
}
