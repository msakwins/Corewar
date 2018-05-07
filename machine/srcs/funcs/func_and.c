/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_and.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:23:05 by msakwins          #+#    #+#             */
/*   Updated: 2018/03/14 20:53:08 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
** Include verification of size, if bad size, then bad ocp, then return
*/

int		func_and(t_env *env, t_process *current, t_ocp ocp)
{
	int				size1;
	int				size2;
	int				value1;
	int				value2;

	size1 = get_size_param(ocp.one, 4);
	size2 = get_size_param(ocp.two, 4);
	value1 = get_data_all_types_dir_four(env, current,
		M((current->pc + 2)), ocp.one);
	value2 = get_data_all_types_dir_four(env, current,
		M((current->pc + 2 + size1)), ocp.two);
	if (env->verbose)
		ft_printf("[%5d] And called from %d : and between %d and %d to r%d\n",
			env->cycle, current->id_champion, value1, value2,
			env->arena[M((current->pc + 2 + size1 + size2))]);
	if (!verify_reg(env->arena[M((current->pc + 2 + size1 + size2))], 1, 1))
		return (2 + size1 + size2 + 1);
	if (size1 && size2)
		current->reg[env->arena[M((current->pc + 2 + size1 + size2))] - 1] =
			value1 & value2;
	current->carry = value1 & value2 ? 0 : 1;
	return (2 + size1 + size2 + 1);
}
