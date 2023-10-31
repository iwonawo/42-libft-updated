/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 09:51:05 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 12:54:07 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The ft_isalpha function checks if a given character is an alphabetic
	character (A-Z, a-z).

	Parameters:
	c - The character to be checked.

	Return:
	If the character is an alphabetic character, the function returns 1,
	otherwise it returns 0.

	Description:
	The ft_isalpha function takes an integer 'c' representing a character's
	ASCII value. It checks if the character's ASCII value is not within the
	range of lowercase letters, or uppercase letters.
	If the condition is met, it returns 0. Otherwise, returns 1 indicating
	that the character is an alphabetic character.

	Example:
	int result = ft_isalpha('C'); // Returns 1
	int result2 = ft_isalpha('3'); // Returns 0
*/
int	ft_isalpha(int c)
{
	if ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z'))
		return (0);
	else
		return (1);
}
