/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_add.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:23:05 by msakwins          #+#    #+#             */
/*   Updated: 2018/03/14 20:27:29 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int		func_add(t_env *env, t_process *current)
{
	int		reg1_idx;
	int		reg2_idx;
	int		reg3_idx;

	reg1_idx = env->arena[M((current->pc + 2))];
	reg2_idx = env->arena[M((current->pc + 2 + 1))];
	reg3_idx = env->arena[M((current->pc + 2 + 2))];
	if (env->verbose)
		ft_printf("[%5d] Add called from %d : adding r%d and r%d to r%d\n",
			env->cycle, current->id_champion, reg1_idx, reg2_idx, reg3_idx);
	if (!verify_reg(reg1_idx, reg2_idx, reg3_idx))
		return (2 + 1 + 1 + 1);
	current->reg[reg3_idx - 1] = current->reg[reg1_idx - 1] +
		current->reg[reg2_idx - 1];
	current->carry = current->reg[reg3_idx - 1] ? 0 : 1;
	return (2 + 1 + 1 + 1);
}
