/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:11:02 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 13:02:18 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The ft_isprint function checks if a given character is a printable
	character.

	Parameters:
	c - The character to be checked.

	Return:
	If the character is a printable character, the function returns 1,
	otherwise it returns 0.

	Description:
	The ft_isprint function takes an integer 'c' representing a character's
	ASCII value. It checks if the character's ASCII value is not within the
	printable characters (ASCII values 32 - 126).
	If the condition is met, it returns 0. Otherwise, returns 1 indicating
	that the character is a printable character.

	Example:
	int result = ft_isprint('C'); // Returns 1
	int result2 = ft_isprint('\n'); // Returns 0
*/
int	ft_isprint(int c)
{
	if (c < 32 || c > 126)
		return (0);
	else
		return (1);
}
