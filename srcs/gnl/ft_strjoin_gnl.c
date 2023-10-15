/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_gnl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/17 11:49:10 by iwozniak          #+#    #+#             */
/*   Updated: 2023/10/15 09:45:22 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_gnl(char *buffer, char *content)
{
	char	*result;
	size_t	i;
	size_t	j;

	if (!buffer)
		return (ft_strdup_gnl(content));
	if (!content)
		return (ft_strdup_gnl(buffer));
	i = 0;
	result = (char *)malloc(sizeof(char) * (ft_strlen_gnl(buffer)
				+ ft_strlen_gnl(content)) + 1);
	if (!result)
		return (NULL);
	while (buffer && buffer[i])
	{
		result[i] = buffer[i];
		i++;
	}
	j = 0;
	while (content && content[j])
		result[i++] = content[j++];
	result[i] = '\0';
	free(buffer);
	return (result);
}
