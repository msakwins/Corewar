/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_ld_lld.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/22 15:23:05 by msakwins          #+#    #+#             */
/*   Updated: 2018/03/14 23:15:36 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

/*
** Function that handles both ld and lld function. The only difference between
** the two are the restriction flag. In the lld, there is no restriction of
** address.
**
** We start by getting the value inside of the ram, by direct or index mapping
** Then we get the size of the first parameter, to get the index of register.
** Some error checking, then we save the value at the index, set carry to 0
** or 1 depending on the value being 0 or not, and return the size taken.
*/

static int		both_lds(t_env *env, t_process *current, t_ocp ocp, int restr)
{
	int				size;
	unsigned int	value;
	int				reg_idx;

	if (ocp.one == DIR_CODE)
		value = get_data_dir(env, M((current->pc + 2)), 4);
	else if (ocp.one == IND_CODE)
		value = get_data_ind(env, M((current->pc)), restr);
	size = get_size_param(ocp.one, 4);
	reg_idx = env->arena[M((current->pc + 2 + size))];
	if (env->verbose)
		ft_printf("[%5d] (l)ld called from %d : loading %d in r%d\n",
		env->cycle, current->id_champion, value, reg_idx);
	if (ocp.one == REG_CODE || reg_idx > REG_NUMBER ||
		ocp.two != REG_CODE || ocp.one == 0)
		return (2 + size + 1);
	if (size && verify_reg(reg_idx, 1, 1))
		current->reg[reg_idx - 1] = value;
	current->carry = value == 0 ? 1 : 0;
	return (2 + size + 1);
}

int				func_ld(t_env *env, t_process *current, t_ocp ocp)
{
	return (both_lds(env, current, ocp, 1));
}

int				func_lld(t_env *env, t_process *current, t_ocp ocp)
{
	return (both_lds(env, current, ocp, 0));
}
