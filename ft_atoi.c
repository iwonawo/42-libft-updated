/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iwozniak <iwozniak@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 15:01:28 by iwozniak          #+#    #+#             */
/*   Updated: 2023/07/25 14:20:24 by iwozniak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_sign(const char c, int *sign)
{
	if (c == '-')
		*sign = *sign * -1;
}

static long long int	ft_result(const char *str, long long int i, int sign)
{
	long long int	res;
	long long int	temp;

	res = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		temp = res;
		res = (res * 10) + sign * (str[i] - '0');
		if (res > temp && sign < 0)
			return (0);
		if (res < temp && sign > 0)
			return (-1);
		i++;
	}
	return (res);
}

int	ft_atoi(const char *str)
{
	long long int	i;
	int				sign;
	long long int	result;

	i = 0;
	sign = 1;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		ft_sign(str[i], &sign);
		i++;
	}
	while (str[i] == '0')
		i++;
	result = ft_result(str, i, sign);
	return (result);
}
