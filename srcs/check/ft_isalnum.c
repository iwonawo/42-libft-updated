/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:10:46 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 12:52:18 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The ft_isalnum function checks if a given character is an alphanumeric
	character (A-Z, a-z, or 0-9).

	Parameters:
	c - The character to be checked.

	Return:
	If the character is an alphanumeric character, the function returns 1,
	otherwise it returns 0.

	Description:
	The ft_isalnum function takes an integer 'c' representing a character's
	ASCII value. It checks if the character's ASCII value is not within the
	range of digits, lowercase letters, or uppercase letters.
	If the condition is met, it returns 0. Otherwise, returns 1 indicating
	that the character is an alphanumeric character.

	Example:
	int result = ft_isalnum('C'); // Returns 1
	int result2 = ft_isalnum('$'); // Returns 0
*/
int	ft_isalnum(int c)
{
	if ((c < '0' || c > '9') && ((c < 'a' || c > 'z') && (c < 'A' || c > 'Z')))
		return (0);
	else
		return (1);
}
