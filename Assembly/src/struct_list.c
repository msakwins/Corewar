/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arosset <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/11 15:30:06 by arosset           #+#    #+#             */
/*   Updated: 2018/03/04 16:05:57 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/asm.h"

void	ft_lstaddtail(t_list **alst, t_list *new)
{
	t_list	*tmp;

	tmp = NULL;
	if (alst && *alst)
	{
		tmp = *alst;
		while (tmp && tmp->next)
			tmp = tmp->next;
		if (tmp)
			tmp->next = new;
	}
	else if (alst)
		*alst = new;
}

/*
**		initialise struct t_asm
*/

t_asm	*init_t_asm(char *name)
{
	t_asm	*new_asm;

	if (!(new_asm = malloc(sizeof(t_asm))))
		exit_msg_error(NULL, "Malloc", -1);
	new_asm->name_prg = NULL;
	new_asm->comment_prg = NULL;
	new_asm->file_s = name;
	new_asm->file_cor = set_name_cor(name);
	new_asm->header = NULL;
	new_asm->body = NULL;
	new_asm->labels = NULL;
	new_asm->labdirs = NULL;
	new_asm->err = 0;
	new_asm->prog_size = -1;
	return (new_asm);
}

/*
**		Compte le nombre d'element t_file_list
*/

int		size_list(t_file_list **list)
{
	int			size;
	t_file_list	*tmp;

	size = 0;
	tmp = *list;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}

/*
**		initialise et ajoute element struct t_file_list
**		list comprenant : .name
**						  .comment
**						  instruction et label
*/

void	ft_add_end_file_list(t_file_list **list, char *line, int num_l)
{
	t_file_list *new;
	t_file_list *tmp;

	if (!(new = malloc(sizeof(t_file_list))))
		exit_msg_error(NULL, "Malloc", -1);
	new->line = ft_strdup(line);
	new->num_l = num_l;
	new->next = NULL;
	tmp = *list;
	if (!tmp)
		*list = new;
	else
	{
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
}
