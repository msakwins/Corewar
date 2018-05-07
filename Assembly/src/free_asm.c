/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_asm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 16:59:21 by arosset           #+#    #+#             */
/*   Updated: 2018/03/04 15:56:25 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

/*
**		free tout les elements des t_list
*/

void	free_t_list_labdir(t_list *list)
{
	t_list		*tmp;
	t_labdir	*labdir;

	tmp = list;
	while (tmp)
	{
		tmp = (list)->next;
		if ((list)->content)
		{
			labdir = (list)->content;
			free(list->content);
		}
		free(list);
		list = tmp;
	}
}

void	free_t_list_label(t_list *list)
{
	t_list	*tmp;
	t_label	*label;

	tmp = list;
	while (tmp)
	{
		tmp = (list)->next;
		if ((list)->content)
		{
			label = (list)->content;
			ft_strdel(&label->label);
			free(list->content);
		}
		free(list);
		list = tmp;
	}
}

/*
**		free tout les elements des t_file_list
*/

void	free_file_list(t_file_list **list)
{
	t_file_list	*cp_list;

	cp_list = (*list);
	while (cp_list)
	{
		cp_list = (*list)->next;
		if ((*list)->line)
			ft_strdel(&(*list)->line);
		free(*list);
		*list = cp_list;
	}
}

void	clean_env(t_asm *env)
{
	if (env->name_prg)
		ft_strdel(&env->name_prg);
	if (env->comment_prg)
		ft_strdel(&env->comment_prg);
	if (env->file_cor)
		ft_strdel(&env->file_cor);
	if (env->body)
		free_file_list(&env->body);
	if (env->header)
		free_file_list(&env->header);
	if (env->labels)
		free_t_list_label(env->labels);
	if (env->labdirs)
		free_t_list_labdir(env->labdirs);
	free(env);
}
