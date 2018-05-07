/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_ldi_lldi.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 22:23:45 by bbeldame          #+#    #+#             */
/*   Updated: 2018/03/14 21:02:17 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

static unsigned int	get_value_ldis(t_env *env, t_process *current,
	t_ocp ocp, int restr)
{
	unsigned int	size1;
	short int		value1;
	short int		value2;

	size1 = get_size_param(ocp.one, 2);
	if (restr)
	{
		value1 = (short int)get_data_all_types_dir_two(env, current,
			M((current->pc + 2)), ocp.one);
		value2 = (short int)get_data_all_types_dir_two(env, current,
			M((current->pc + 2 + size1)), ocp.two);
	}
	else
	{
		value1 = (short int)get_data_all_types_dir_two_no_restrict(env,
			current, M((current->pc + 2)), ocp.one);
		value2 = (short int)get_data_all_types_dir_two_no_restrict(env,
			current, M((current->pc + 2 + size1)), ocp.two);
	}
	return ((unsigned int)(value1 + value2));
}

static int			both_ldis(t_env *env, t_process *current,
	t_ocp ocp, int restr)
{
	unsigned int	size1;
	unsigned int	size2;
	unsigned int	value;

	size1 = get_size_param(ocp.one, 2);
	size2 = get_size_param(ocp.two, 2);
	value = get_value_ldis(env, current, ocp, restr);
	if (env->verbose)
		ft_printf("[%5d] (l)ldi called from %d : loading %d in r%d\n",
		env->cycle, current->id_champion, value,
		env->arena[M((current->pc + 2 + size1 + size2))]);
	if (!verify_reg(env->arena[M((current->pc + 2 + size1 + size2))], 1, 1))
		return (2 + size1 + size2 + 1);
	if (size1 && size2)
		current->reg[env->arena[M((current->pc + 2 + size1 + size2))] - 1] =
			get_value(env, current->pc + value);
	current->carry = get_value(env, current->pc + value) ? 0 : 1;
	return (2 + size1 + size2 + 1);
}

int					func_ldi(t_env *env, t_process *current, t_ocp ocp)
{
	return (both_ldis(env, current, ocp, 1));
}

int					func_lldi(t_env *env, t_process *current, t_ocp ocp)
{
	return (both_ldis(env, current, ocp, 0));
}
