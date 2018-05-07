/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_asm.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 16:58:37 by arosset           #+#    #+#             */
/*   Updated: 2018/03/10 16:06:02 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void	print_label_addr(t_asm *param, t_labdir *labdir)
{
	t_list	*tmp;
	t_label	*label;
	int		val;

	tmp = param->labels;
	while (tmp)
	{
		label = tmp->content;
		if (!ft_strcmp(labdir->label, label->label))
		{
			val = label->addr - labdir->instr_addr;
			if (labdir->oct_size == 4)
			{
				ft_putchar_fd(val >> 24, param->fd);
				ft_putchar_fd(val >> 16, param->fd);
			}
			ft_putchar_fd(val >> 8, param->fd);
			ft_putchar_fd(val, param->fd);
			if (lseek(param->fd, -(labdir->addr +
				labdir->oct_size - 1), SEEK_CUR) == -1)
				return ;
			return ;
		}
		tmp = tmp->next;
	}
}

void	complete_file(t_asm *param)
{
	t_list		*tmp;
	t_labdir	*content;

	if (lseek(param->fd, PROG_NAME_LENGTH + 8, SEEK_SET) == -1)
		return ;
	ft_putchar_fd((unsigned)param->prog_size >> 24, param->fd);
	ft_putchar_fd(param->prog_size >> 16, param->fd);
	ft_putchar_fd(param->prog_size >> 8, param->fd);
	ft_putchar_fd(param->prog_size, param->fd);
	if (lseek(param->fd, COMMENT_LENGTH + 4, SEEK_CUR) == -1)
		return ;
	tmp = param->labdirs;
	while (tmp)
	{
		content = tmp->content;
		if (lseek(param->fd, content->addr - 1, SEEK_CUR) == -1)
			return ;
		print_label_addr(param, content);
		tmp = tmp->next;
	}
}

int		get_ocp_return(t_inst *ins, int oc)
{
	if (ins->nb_instr == 0)
		return (oc << 6);
	else if (ins->nb_instr == 1)
		return (oc << 4);
	else
		return (oc << 2);
}

void	finalize_asm(t_asm *env)
{
	if ((env->fd = open(env->file_cor, O_CREAT | O_RDWR | O_TRUNC, 0755)) == -1)
		exit_msg_error(env, "Create file", -1);
	print_magic(env->fd);
	print_header(env);
	print_body(env);
	complete_file(env);
	ft_printf("Writing output programe to : \033[32m%s\033[00m\n",
			env->file_cor);
}
