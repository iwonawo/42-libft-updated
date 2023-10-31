/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 19:17:30 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 16:56:02 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
	The ft_striteri function applies a function to each character of a string,
	providing the index and a pointer to the character.

	Parameters:
	s - A pointer to the string to be iterated over.
	f - The function to be applied to each character.
	It takes an unsigned integer (the index) and a pointer to a character
	as parameters, and performs some operation on the character.

	Return:
	None.

	Description:
	The ft_striteri function iterates over each character of the input string,
	passing the current index and a pointer to the character to the provided
	function. If the input string and function pointers are not NULL, the
	iteration begins. Inside the loop, the function is applied to each
	character, allowing the function to perform some operation or modification
	on the character. The index is incremented with each iteration, and the
	pointer to the character is incremented to move to the next character in the
	string. The iteration continues until the null-terminator of the string is
	reached. If either the input string or the function pointer is NULL, the
	function does nothing.

	Note:
	The function operates directly on the input string and modifies it in place.
	There is no return value.

	Example:
	void uppercase(unsigned int index, char *ch)
	{
	*ch = toupper(*ch);
	}

	char str[] = "hello";
	ft_striteri(str, uppercase);
	After the function call, the content of str will be "HELLO".
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	i = 0;
	if (s)
	{
		while (s[i] != '\0')
		{
			f(i, &s[i]);
			i++;
		}
	}
}
