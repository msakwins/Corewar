/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_sub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:23:05 by msakwins          #+#    #+#             */
/*   Updated: 2018/03/14 21:02:45 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		func_sub(t_env *env, t_process *current)
{
	int		reg1_idx;
	int		reg2_idx;
	int		reg3_idx;

	reg1_idx = env->arena[M((current->pc + 2))];
	reg2_idx = env->arena[M((current->pc + 2 + 1))];
	reg3_idx = env->arena[M((current->pc + 2 + 2))];
	if (env->verbose)
		ft_printf(
			"[%5d] Sub called from %d : substract r%d to r%d inside r%d\n",
			env->cycle, current->id_champion, reg2_idx, reg1_idx, reg3_idx);
	if (!verify_reg(reg1_idx, reg2_idx, reg3_idx))
		return (2 + 1 + 1 + 1);
	current->reg[reg3_idx - 1] = current->reg[reg1_idx - 1] -
		current->reg[reg2_idx - 1];
	current->carry = current->reg[reg3_idx - 1] ? 0 : 1;
	return (2 + 1 + 1 + 1);
}
