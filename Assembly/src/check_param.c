/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 15:20:49 by arosset           #+#    #+#             */
/*   Updated: 2018/03/04 15:54:50 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

/*
**		parcour la chaine donne
**		renvoi 1 si la tout les elements sont des chiffres
** 		sinon renvoi 0
*/

int		ft_str_is_int(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < 48 && str[i] > 57)
			return (0);
		i++;
	}
	return (1);
}

/*
**		parcour la chaine donne
** 		renvoi 1 si la chaine est un registre conprit entre r1 et r16
** 		sinon renvoi 0
*/

int		is_reg(char *param)
{
	if (param[0] == 'r')
	{
		if (ft_str_is_int(param + 1))
		{
			if (ft_atoi(param + 1) >= 1 && ft_atoi(param + 1) <= REG_NUMBER)
				return (1);
		}
	}
	return (0);
}

/*
**		parcour la chaine donne
** 		renvoi 1 si la chaine est un label se terminant par ":"
** 		sinon renvoi 0
*/

int		is_label(char *param)
{
	int	i;

	i = 0;
	while (ft_strchr(LABEL_CHARS, param[i]))
		i++;
	if (param[i] == LABEL_CHAR)
	{
		return (i + 1);
	}
	return (0);
}

/*
**		parcour la chaine donne
** 		envoi la chaine a is_ind si elle commence par "%"
** 		sinon renvoi 0
*/

int		is_dir(t_list *labels, char *param)
{
	if (param[0] == DIRECT_CHAR)
		return (is_ind(labels, param + 1));
	return (0);
}

/*
**		parcour la chaine donne
**		compare le label eventuel a la t_list labels
** 		renvoi 1 si la chaine est un indirect
** 		sinon renvoi 0
*/

int		is_ind(t_list *labels, char *param)
{
	int		i;
	t_list	*elem;
	t_label *tmp;

	i = 0;
	if (param[i] == '-')
		i++;
	if (param[i] == '\0')
		return (0);
	if (param[i] == LABEL_CHAR)
	{
		elem = labels;
		while (elem)
		{
			tmp = elem->content;
			if (!ft_strncmp(param + 1, tmp->label, ft_strlen(tmp->label) - 1)
				&& verif_end_line_param(param + 1, ft_strlen(tmp->label)))
				return (1);
			elem = elem->next;
		}
		return (0);
	}
	if (!check_end_ind(param, i))
		return (0);
	return (1);
}
