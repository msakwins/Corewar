/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 21:19:30 by bbeldame          #+#    #+#             */
/*   Updated: 2018/03/12 23:36:57 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/vm.h"

int					verify_reg(int r1, int r2, int r3)
{
	if (r1 < 1 || r1 > REG_NUMBER)
		return (0);
	if (r2 < 1 || r2 > REG_NUMBER)
		return (0);
	if (r3 < 1 || r3 > REG_NUMBER)
		return (0);
	return (1);
}

unsigned int		get_size_param(char param_type, int dir)
{
	if (param_type == REG_CODE)
		return (1);
	if (param_type == DIR_CODE)
		return (dir);
	if (param_type == IND_CODE)
		return (IND_SIZE);
	return (0);
}

t_ocp				get_ocp(t_env *env, t_process *current)
{
	unsigned char	byte_ocp;
	t_ocp			ocp;

	ocp.one = 0;
	ocp.two = 0;
	ocp.three = 0;
	byte_ocp = 0;
	if (env->arena[M((current->pc))] != LIVE &&
		env->arena[M((current->pc))] != ZJMP &&
		env->arena[M((current->pc))] != FORK &&
		env->arena[M((current->pc))] != LFORK)
	{
		byte_ocp = env->arena[M((current->pc + 1))];
		ocp.one = byte_ocp >> 6;
		ocp.two = (byte_ocp >> 4) & 0x03;
		ocp.three = (byte_ocp >> 2) & 0x03;
	}
	return (ocp);
}

void				init_reg(t_process *process)
{
	int i;

	i = 0;
	while (i < 16)
		process->reg[i++] = 0;
}
