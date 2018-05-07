/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <msakwins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/09 20:56:27 by msakwins          #+#    #+#             */
/*   Updated: 2017/08/07 20:39:02 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int	digitscount(int n)
{
	int				size;
	unsigned int	nb;

	size = 0;
	if (n < 0)
	{
		nb = -n;
		size++;
	}
	else
		nb = n;
	while (nb > 9)
	{
		nb = nb / 10;
		size++;
	}
	size++;
	return (size);
}

char		*ft_itoa(int n)
{
	char			*str;
	int				i;
	unsigned int	nb;
	int				minus;

	minus = 0;
	if (!(str = (char *)malloc(sizeof(char) * digitscount(n) + 1)))
		return (NULL);
	i = digitscount(n);
	if (n < 0)
	{
		minus = 1;
		nb = -n;
	}
	else
		nb = n;
	str[i--] = '\0';
	while (nb >= 10)
	{
		str[i--] = 48 + nb % 10;
		nb = nb / 10;
	}
	str[i--] = 48 + nb;
	str[i] = (minus) ? '-' : str[i];
	return (str);
}
