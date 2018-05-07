/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_oflow.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:41:19 by arosset           #+#    #+#             */
/*   Updated: 2018/03/08 16:41:21 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

long	ft_atoi_oflow(char *str)
{
	int		i;
	int		sign;
	long	ans;

	i = 0;
	sign = 1;
	ans = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
			str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' && ++i)
		sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (ans * 10 + (str[i] - '0') >= 0)
			ans = 10 * ans + (str[i] - '0');
		else
			return (-1);
		i++;
	}
	return (ans * sign);
}
