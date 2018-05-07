/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_sti.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:23:05 by msakwins          #+#    #+#             */
/*   Updated: 2018/03/14 20:25:30 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static void		write_sti(t_env *env, t_process *current, unsigned int value)
{
	int			i;
	int			reg_value;

	reg_value = current->reg[env->arena[M((current->pc + 2))] - 1];
	i = 0;
	if (env->verbose)
		ft_printf("[%5d] Sti called from %d : storing %d to %d\n",
			env->cycle, current->id_champion, reg_value, value);
	while (i < REG_SIZE)
	{
		env->arena[M((current->pc + value + i))] =
			LBYTE(reg_value >> (8 * (3 - i)));
		i++;
	}
	current->carry = reg_value ? 0 : 1;
}

int				func_sti(t_env *env, t_process *current, t_ocp ocp)
{
	int				size2;
	int				size3;
	int				value2;
	int				value3;

	size2 = get_size_param(ocp.two, 2);
	size3 = get_size_param(ocp.three, 2);
	value2 = get_data_all_types_dir_two(env, current,
		M((current->pc + 2 + 1)), ocp.two);
	value3 = get_data_all_types_dir_two(env, current,
		M((current->pc + 2 + 1 + size2)), ocp.three);
	if (!verify_reg(env->arena[M((current->pc + 2))], 1, 1))
		return (2 + 1 + size2 + size3);
	write_sti(env, current, (value2 + value3) % IDX_MOD);
	return (2 + 1 + size2 + size3);
}
