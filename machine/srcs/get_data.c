/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/25 20:55:34 by bbeldame          #+#    #+#             */
/*   Updated: 2018/03/13 00:33:46 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

unsigned int	get_value(t_env *e, int idx)
{
	return (LBYTE(e->arena[M((idx))]) << 24) |
	(LBYTE(e->arena[M((idx + 1))]) << 16) |
	(LBYTE(e->arena[M((idx + 2))]) << 8) |
	LBYTE(e->arena[M((idx + 3))]);
}

int				get_reg(t_env *env, t_process *current, int idx)
{
	int reg_i;

	reg_i = LBYTE(env->arena[M((idx))]);
	if (reg_i > 0 && reg_i <= REG_NUMBER)
		return (current->reg[reg_i - 1]);
	return (0);
}

unsigned int	get_jumper(t_env *e, int idx, int restr)
{
	unsigned int	jumper;

	jumper = (LBYTE(e->arena[M((idx))]) << 8 |
		LBYTE(e->arena[M((idx + 1))]));
	jumper = restr ? (short)jumper % IDX_MOD : jumper;
	return (jumper);
}

unsigned int	get_data_dir(t_env *e, int idx, int label_size)
{
	unsigned int res;

	if (label_size == 2)
	{
		res = (LBYTE(e->arena[M((idx))]) << 8 | LBYTE(e->arena[M((idx + 1))]));
		return (short)(res);
	}
	else
	{
		res = get_value(e, idx);
		return (int)res;
	}
	return (res);
}

unsigned int	get_data_ind(t_env *e, int idx, int restr)
{
	short int	jumper;

	jumper = (short int)get_jumper(e, idx, restr);
	return (get_value(e, idx + jumper));
}
