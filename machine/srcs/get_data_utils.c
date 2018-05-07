/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/04 18:51:26 by bbeldame          #+#    #+#             */
/*   Updated: 2018/03/12 23:36:52 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

unsigned int		get_data_all_types_dir_four(t_env *env, t_process *current,
	int idx, char param_type)
{
	unsigned int	res;

	res = 0;
	if (param_type == REG_CODE && verify_reg(env->arena[M((idx))], 1, 1))
		res = get_reg(env, current, idx);
	else if (param_type == DIR_CODE)
		res = get_data_dir(env, idx, 4);
	else if (param_type == IND_CODE)
		res = get_data_ind(env, idx, 1);
	return (res);
}

unsigned int		get_data_all_types_dir_two(t_env *env, t_process *current,
	int idx, char param_type)
{
	unsigned int	res;

	res = 0;
	if (param_type == REG_CODE && verify_reg(env->arena[M((idx))], 1, 1))
		res = get_reg(env, current, idx);
	else if (param_type == DIR_CODE)
		res = get_data_dir(env, idx, 2);
	else if (param_type == IND_CODE)
		res = get_data_ind(env, idx, 1);
	return (res);
}

unsigned int		get_data_all_types_dir_two_no_restrict(t_env *env,
	t_process *current, int idx, char param_type)
{
	unsigned int	res;

	res = 0;
	if (param_type == REG_CODE && verify_reg(env->arena[M((idx))], 1, 1))
		res = get_reg(env, current, idx);
	else if (param_type == DIR_CODE)
		res = get_data_dir(env, idx, 2);
	else if (param_type == IND_CODE)
		res = get_data_ind(env, idx, 0);
	return (res);
}
