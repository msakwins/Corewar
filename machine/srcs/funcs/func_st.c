/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_st.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:23:05 by msakwins          #+#    #+#             */
/*   Updated: 2018/03/14 22:56:52 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static int		st_ind(t_env *env, t_process *current, unsigned int value)
{
	short int		second_arg;
	int				i;

	second_arg = (short int)get_jumper(env, M((current->pc + 3)), 1);
	i = 0;
	if (env->verbose)
		ft_printf("[%5d] St called from %d : storing %d to %d\n",
			env->cycle, current->id_champion, value, second_arg);
	while (i < REG_SIZE)
	{
		env->arena[M((current->pc + second_arg + i))] =
			LBYTE(value >> (8 * (3 - i)));
		i++;
	}
	return (2 + 1 + 2);
}

static int		st_reg(t_env *env, t_process *current, unsigned int value,
	int size)
{
	unsigned int	second_arg;

	second_arg = env->arena[M((current->pc + 3))];
	if (env->verbose)
		ft_printf("[%5d] St called from %d : storing %d to r%d\n",
			env->cycle, current->id_champion, value, second_arg);
	if (second_arg > REG_NUMBER || second_arg <= 0)
		return (2 + 1 + 1);
	if (size)
		current->reg[second_arg - 1] = value;
	return (2 + 1 + 1);
}

int				func_st(t_env *env, t_process *current, t_ocp ocp)
{
	int				size;
	unsigned int	value;
	int				reg_idx;

	size = get_size_param(ocp.two, 4);
	reg_idx = env->arena[M((current->pc + 2))];
	if (ocp.one != REG_CODE || reg_idx > REG_NUMBER || ocp.two == 0)
		return (2 + size + 1);
	value = current->reg[reg_idx - 1];
	current->carry = value == 0 ? 1 : 0;
	if (ocp.two == REG_CODE)
		return (st_reg(env, current, value, size));
	else
		return (st_ind(env, current, value));
}
