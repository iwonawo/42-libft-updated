/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:19:06 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 17:38:17 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The ft_tolower function converts an uppercase character to its
	lowercase equivalent.

	Parameters:
	c - The character to be converted.

	Return:
	The lowercase equivalent of the input character, if it is an
	uppercase letter.
	The input character itself, if it is not an uppercase letter.

	Description:
	The ft_tolower function takes an input character 'c'.
	It checks if 'c' is in the range of uppercase letters, which corresponds
	to ASCII values from 65 to 90. If 'c' is an uppercase letter,
	it adds 32 to its ASCII value to convert it to the corresponding
	lowercase letter. This conversion is possible because the ASCII
	values for uppercase and lowercase letters have a difference of 32.
	Finally, it returns the converted lowercase letter if 'c' was an
	uppercase letter, or the input character itself if 'c' was not an
	uppercase letter.

	Example:
	ft_tolower('A');
	returns 'a'
	ft_tolower('b');
	returns 'b' (not an uppercase letter)
	ft_tolower('$');
	returns '$' (not a letter)
*/
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	else
		return (c);
}
