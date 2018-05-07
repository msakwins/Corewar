/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_body.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 17:34:02 by arosset           #+#    #+#             */
/*   Updated: 2018/03/10 16:08:35 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void	print_param(t_asm *param, t_inst *ins)
{
	int	i;

	i = -1;
	if (g_op_tab[ins->i_instr].ocp)
		ft_putchar_fd(ins->ocp, param->fd);
	while (++i < ins->nb_instr)
	{
		if (((unsigned)ins->ocp >> (6 - i * 2) & 0b11) == 0b01)
			ft_putchar_fd(ins->param[i], param->fd);
		else if (((unsigned)ins->ocp >> (6 - i * 2) & 0b11) == 0b11
			|| g_op_tab[ins->i_instr].label_size)
		{
			ft_putchar_fd((unsigned)ins->param[i] >> 8, param->fd);
			ft_putchar_fd(ins->param[i], param->fd);
		}
		else
		{
			ft_putchar_fd((unsigned)ins->param[i] >> 24, param->fd);
			ft_putchar_fd(ins->param[i] >> 16, param->fd);
			ft_putchar_fd(ins->param[i] >> 8, param->fd);
			ft_putchar_fd(ins->param[i], param->fd);
		}
	}
}

int		print_params(t_asm *param, char *line, t_inst *ins)
{
	int	i;

	i = 0;
	if (g_op_tab[ins->i_instr].ocp)
		ins->octet++;
	ins->nb_instr = 0;
	ins->ocp = 0;
	while (ins->nb_instr < g_op_tab[ins->i_instr].nb_param)
	{
		while (is_white_space(line[i]) || line[i] == SEPARATOR_CHAR)
			i++;
		if ((ins->ins = ft_strsub(line, i, get_param_end(line + i))) == NULL)
			return (0);
		i += get_param(param, ins);
		free(ins->ins);
		ins->nb_instr++;
	}
	print_param(param, ins);
	return (1);
}

int		get_instr(t_asm *param, char *line, t_inst *ins)
{
	int	idx;
	int	label_size;
	int	i;

	idx = 0;
	i = 0;
	if (!line)
		return (0);
	while (g_op_tab[idx].name)
	{
		label_size = get_size_inst(line);
		if (!(ft_strncmp(line, g_op_tab[idx].name, label_size)))
		{
			i = ft_strlen(g_op_tab[idx].name);
			break ;
		}
		idx++;
	}
	ins->octet += 1;
	ft_putchar_fd(idx + 1, param->fd);
	ins->ins_octet = ins->octet;
	ins->i_instr = idx;
	if (!print_params(param, line + i, ins))
		return (0);
	return (1);
}

int		get_label_pos(t_asm *param, char *line, t_inst *ins)
{
	t_list	*tmp;
	t_label	*content;
	int		x;

	tmp = param->labels;
	while (tmp)
	{
		content = tmp->content;
		x = ft_strlen(content->label);
		if (!(ft_strncmp(line, content->label, x)) && line[x] == LABEL_CHAR)
		{
			if (line[x] != LABEL_CHAR)
				return (0);
			content->addr = ins->octet + 1;
			return (0);
		}
		tmp = tmp->next;
	}
	return (1);
}

void	print_body(t_asm *param)
{
	t_file_list	*files;
	t_inst		ins;
	int			i;

	i = 0;
	files = param->body;
	ins.octet = 0;
	while (files)
	{
		if ((i = is_label(files->line)))
			get_label_pos(param, files->line, &ins);
		while (is_white_space(files->line[i]))
			i++;
		if (files->line[i] != '\0' && files->line[i] != COMMENT_CHAR)
		{
			get_instr(param, files->line + i, &ins);
		}
		files = files->next;
	}
	param->prog_size = ins.octet;
}
