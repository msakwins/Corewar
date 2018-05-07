/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_aff.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:23:05 by msakwins          #+#    #+#             */
/*   Updated: 2018/03/14 20:28:06 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
** Aff function, if char != 0, add it to buffer, when receiving 0 or buffer is
** to the MAX_BUFFER index, print it with an \n
*/

int		func_aff(t_env *env, t_process *current)
{
	int		reg;
	int		i;

	i = 0;
	reg = get_reg(env, current, M((current->pc + 2))) % 256;
	if (current->idx_buffer >= MAX_BUFFER)
	{
		if (!env->visu)
			ft_printf("%s\n", current->buffer);
		current->idx_buffer = 0;
		return (3);
	}
	current->buffer[current->idx_buffer] = (char)reg;
	if (env->verbose)
		ft_printf("[%5d] Aff called from %d\n", env->cycle,
			current->id_champion);
	current->idx_buffer++;
	if (reg == 0)
	{
		if (!env->visu)
			ft_printf("%s\n", current->buffer);
		current->idx_buffer = 0;
		return (3);
	}
	return (3);
}
