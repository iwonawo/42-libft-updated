/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:13:30 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 12:56:39 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The ft_isascii function checks if a given character is a valid ASCII
	character.

	Parameters:
	c - The character to be checked.

	Return:
	If the character is a valid ASCII character, the function returns 1,
	otherwise it returns 0.

	Description:
	The ft_isascii function takes an integer 'c' representing a character's
	ASCII value. It checks if the character's ASCII value is not within the
	valid ASCII range (0 - 127).
	If the condition is met, it returns 0. Otherwise, returns 1 indicating
	that the character is a valid ASCII character.

	Example:
	int result = ft_isascii('C'); // Returns 1
	int result2 = ft_isascii(137); // Returns 0
*/
int	ft_isascii(int c)
{
	if (c < 0 || c > 127)
		return (0);
	else
		return (1);
}
