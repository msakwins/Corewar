/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_param.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/08 16:03:54 by arosset           #+#    #+#             */
/*   Updated: 2018/03/19 23:15:13 by bbeldame         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

int		get_labdir_pos(t_asm *param, t_inst *ins, t_label *tmp, int oc)
{
	t_list		*new;
	t_labdir	*content;

	if ((new = (t_list*)malloc(sizeof(t_list))) == NULL)
		exit_msg_error(param, "Malloc\n\033[35mWarning\033[00m.cor is bad", -1);
	if ((content = (t_labdir*)malloc(sizeof(t_labdir))) == NULL)
		exit_msg_error(param, "Malloc\n\033[35mWarning\033[00m.cor is bad", -1);
	content->label = tmp->label;
	content->instr_addr = ins->ins_octet;
	content->addr = ins->octet + 1;
	ins->octet += (oc == 0b10 && !g_op_tab[ins->i_instr].label_size) ? 4 : 2;
	content->oct_size = (oc == 0b10 &&
		!g_op_tab[ins->i_instr].label_size) ? 4 : 2;
	new->content = content;
	new->next = NULL;
	ins->param[ins->nb_instr] = 0;
	ft_lstaddtail(&param->labdirs, new);
	return (get_ocp_return(ins, oc));
}

int		ft_get_label(t_asm *param, t_inst *ins, int oc, int i)
{
	t_list	*elem;
	t_label	*tmp;

	elem = param->labels;
	while (elem)
	{
		tmp = elem->content;
		if (ft_strequ(ins->ins + i + 1, tmp->label))
			return (get_labdir_pos(param, ins, tmp, oc));
		elem = elem->next;
	}
	return (0);
}

int		get_reg(t_inst *ins)
{
	if (ins->ins[0] == 'r')
	{
		ins->param[ins->nb_instr] = ft_atoi_oflow(ins->ins + 1);
		ins->octet++;
		return (get_ocp_return(ins, 0b01));
	}
	return (0);
}

int		get_ind(t_asm *param, t_inst *ins, int oc)
{
	int	idx;
	int	i;

	i = (oc == 0b10 ? 0 : -1);
	if (ins->ins[++i] == LABEL_CHAR)
		return (ft_get_label(param, ins, oc, i));
	idx = i;
	if (ins->ins[idx] == '-')
		idx++;
	while (ins->ins[idx])
		if (!ft_isdigit(ins->ins[idx++]))
			return (0);
	ins->param[ins->nb_instr] = ft_atoi_oflow(ins->ins + i);
	if (oc == 0b10)
	{
		if (!g_op_tab[ins->i_instr].label_size)
			ins->octet += 4;
		else
			ins->octet += 2;
	}
	else
		ins->octet += 2;
	return (get_ocp_return(ins, oc));
}

int		get_param(t_asm *param, t_inst *ins)
{
	int		flag;
	int		p_type;

	flag = 0;
	p_type = g_op_tab[ins->i_instr].param[ins->nb_instr];
	if (p_type & T_REG)
		ins->ocp |= get_reg(ins);
	if (p_type & T_DIR)
	{
		flag = ins->ocp;
		if (*(ins->ins) == DIRECT_CHAR)
			ins->ocp |= get_ind(param, ins, 0b10);
		flag = flag != ins->ocp ? 1 : 0;
	}
	if (!flag && p_type & T_IND)
		ins->ocp |= get_ind(param, ins, 0b11);
	return (ft_strlen(ins->ins));
}
