/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msakwins <msakwins@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/18 00:23:22 by msakwins          #+#    #+#             */
/*   Updated: 2017/08/22 20:36:53 by msakwins         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	init_all(t_modif *modi)
{
	modi->mod = 0;
	modi->flag = 0;
	modi->plus = 0;
	modi->minus = 0;
	modi->sharp = 0;
	modi->space = 0;
	modi->zero = 0;
	modi->preci = 0;
	modi->digit = 0;
	modi->period = 0;
	modi->percent = 0;
	modi->cap = 0;
	modi->hexa = 0;
	modi->neg = 0;
}

void	free_all(t_modif *modi)
{
	modi->mod = 0;
	modi->flag = 0;
	modi->plus = 0;
	modi->minus = 0;
	modi->sharp = 0;
	modi->space = 0;
	modi->zero = 0;
	modi->preci = 0;
	modi->digit = 0;
	modi->period = 0;
	modi->percent = 0;
	modi->cap = 0;
	modi->hexa = 0;
	modi->neg = 0;
}

int		period_zero(uintmax_t nb, t_modif *modi)
{
	return (nb == 0 && PERIOD && PRECI == 0);
}

int		char_before_next_percent(const char *str, int index)
{
	int		i;

	i = 0;
	while (str[index + i] != '%' && str[index + i] != '\0')
		i++;
	write(1, str + index, i);
	return (i);
}
