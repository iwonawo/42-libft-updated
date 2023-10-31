/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/12 14:42:01 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/31 17:40:03 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
	The ft_lstadd_back function adds a new element to the end of a linked
	list.

	Parameters:
	lst - A pointer to the pointer to the first element of the list.
	new - A pointer to the new element to be added to the list.

	Return:
	None.

	Description:
	The ft_lstadd_back function takes a pointer to the pointer to the
	first element of a linked list (lst) and a pointer to a new element
	(new) that is to be added to the list. If either the 'lst' pointer
	or the 'new' pointer is NULL, the function returns immediately,
	indicating an invalid operation.

	If the list is empty (i.e., the 'lst' pointer is NULL), the function
	simply updates the 'lst' pointer to point to the new element,
	making it the first element of the list.

	If the list is not empty, the function traverses the list to find
	the last element:

	1. A pointer 'temp' is initialized to point to the first element of
	the list.
	2. The function iterates through the list by following the 'next'
	pointers until the last element is reached (i.e., 'temp->next' is NULL).
	3. Once the last element is found, the 'next' pointer of the last
	element is updated to point to the new element, effectively adding the
	new element to the end of the list.

	After these steps, the new element is successfully added to the back
	of the linked list.

	Example:
	t_list *lst = ft_lstnew("Hello");
	ft_lstadd_back(&lst, ft_lstnew("World"));
	(The list now contains two elements: "Hello" followed by "World")
*/
void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (lst && new)
	{
		if (!*lst)
		{
			*lst = new;
			return ;
		}
		temp = *lst;
		while (temp->next)
			temp = temp->next;
		temp->next = new;
	}
}
