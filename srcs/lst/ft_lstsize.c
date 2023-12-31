/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:00:14 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 17:45:27 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The ft_lstsize function counts the number of elements in a linked
	list.

	Parameters:
	lst - A pointer to the first element of the linked list.

	Return:
	The number of elements in the linked list.

	Description:
	The ft_lstsize function takes a pointer to the first element of a
	linked list (lst). It starts by initializing a variable 'i' to 0.
	This variable will be used to keep track of the number of elements
	in the list.

	The function then enters a while loop that iterates through the
	linked list. During each iteration, it checks if the 'lst' pointer
	is not NULL. If 'lst' is not NULL, it means there is at least one
	more element in the list, so the function advances to the next
	element by updating 'lst' to lst->next. At the same time, it
	increments the 'i' variable by 1, indicating that one more element
	has been counted.

	The loop continues until the 'lst' pointer becomes NULL, which
	means the end of the list has been reached. At this point, the
	function has counted the total number of elements in the list, and
	it returns the value of 'i', which represents the size of the
	linked list.

	Example:
	t_list *lst = ft_lstnew("Hello");
	ft_lstadd_back(&lst, ft_lstnew("World"));
	int size = ft_lstsize(lst);
	(The size variable will be 2, as there are two elements in the linked list)

	t_list *empty_list = NULL;
	int size = ft_lstsize(empty_list);
	(The size variable will be 0, as the linked list is empty (NULL))
*/
int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
