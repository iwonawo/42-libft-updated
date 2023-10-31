/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 10:09:37 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 12:59:51 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The ft_isdigit function checks if a given character is a digit (0 - 9).

	Parameters:
	c - The character to be checked.

	Return:
	If the character is a digit, the function returns 1, otherwise it
	returns 0.

	Description:
	The ft_isdigit function takes an integer 'c' representing a character's
	ASCII value. It checks if the character's ASCII value is not within the
	range of digits.
	If the condition is met, it returns 0. Otherwise, returns 1 indicating
	that the character is a digit.

	Example:
	int result = ft_isdigit('6'); // Returns 1
	int result2 = ft_isdigit('b'); // Returns 0
*/
int	ft_isdigit(int c)
{
	if (c < '0' || c > '9')
		return (0);
	else
		return (1);
}
