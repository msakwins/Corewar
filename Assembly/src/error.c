/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:08:57 by arosset           #+#    #+#             */
/*   Updated: 2018/03/04 15:56:02 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void	ft_print_usage(void)
{
	ft_printf("Usage: ./asm <source_file.s>\n");
}

void	msg_error(t_asm *env, char *msg, int n_line)
{
	if (n_line == -1)
	{
		ft_printf("\033[31mError\033[00m : %s\n");
	}
	else
	{
		ft_printf("\033[31mError\033[00m : %s in line %d\n", msg, n_line);
	}
	ft_strdel(&msg);
	env->err = 1;
}

void	exit_msg_error(t_asm *env, char *msg, int n_line)
{
	if (n_line == -1)
		ft_printf("\033[31mError\033[00m : %s\n");
	else
		ft_printf("\033[31mError\033[00m : %s in line %d\n", msg, n_line);
	if (env)
		clean_env(env);
	exit(1);
}

void	exit_msg_header(t_asm *param, int c_er)
{
	if (c_er == 1)
		ft_printf("\033[31mError\033[00m : Champion name too long \
(%d) max %d\n", ft_strlen(param->name_prg), PROG_NAME_LENGTH);
	else if (c_er == 2)
		ft_printf("\033[31mError\033[00m : Champion comment too long \
(%d) max %d\n", ft_strlen(param->comment_prg), COMMENT_LENGTH);
	param->err = 1;
}
