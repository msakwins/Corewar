/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:00:46 by arosset           #+#    #+#             */
/*   Updated: 2018/03/10 16:11:53 by arosset          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "../../libft/includes/libft.h"
# include "../../libft/includes/ft_printf.h"
# include "op.h"

# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/*
**	4 bytes : magic number
**	128 bytes : NAME
**	4 bytes = 0
**	4 bytes : prog_size
**	2048 bytes : comment
**	4 bytes = 0
**	prog_size bytes : prog
*/

typedef struct			s_label
{
	char				*label;
	int					addr;
}						t_label;

typedef struct			s_labdir
{
	char				*label;
	int					instr_addr;
	int					addr;
	int					oct_size;
}						t_labdir;

typedef struct			s_file_list
{
	char				*line;
	int					num_l;
	struct s_file_list	*next;
}						t_file_list;

typedef struct			s_inst
{
	char				*ins;
	int					i_instr;
	int					nb_instr;
	int					ocp;
	int					param[3];
	int					ins_octet;
	int					octet;
}						t_inst;

typedef struct			s_asm
{
	char				*name_prg;
	char				*comment_prg;
	char				*file_cor;
	char				*file_s;
	int					fd;
	t_file_list			*header;
	t_file_list			*body;
	t_list				*labels;
	t_list				*labdirs;
	int					err;
	int					prog_size;
}						t_asm;

/*
**		Print asm.cor
*/

void					finalize_asm(t_asm *env);
void					print_header(t_asm *param);
void					print_magic(int fd);
void					print_body(t_asm *param);

int						get_ocp_return(t_inst *ins, int oc);
int						get_reg(t_inst *ins);
int						get_ind(t_asm *param, t_inst *ins, int oc);
int						get_param_end(char *line);
int						get_param(t_asm *param, t_inst *ins);

/*
**		Parser asm.s
*/

int						ft_parser(t_asm *param);
int						ft_parse_body(t_asm *param);
int						set_name_comment(t_asm *param);
int						check_body(t_asm *param);
int						parse_params(char *line, t_asm *param, int idx, int i);

/*
**		Check parameters instruction
*/

int						is_reg(char *param);
int						is_label(char *param);
int						is_dir(t_list *labels, char *param);
int						is_ind(t_list *labels, char *param);
int						check_end_ind(char *param, int i);

/*
** 		verif extension and name
*/

int						ft_check_ext(char *str);
char					*set_name_cor(char *name);

/*
** 		struct and list
*/

t_asm					*init_t_asm(char *name);
void					ft_add_end_file_list(t_file_list **list, char *line,
							int num_l);
int						size_list(t_file_list **list);
void					ft_lstaddtail(t_list **alst, t_list *new);

/*
** 		Utilitaire
*/

int						is_white_space(char c);
int						verif_end_line_param(char *str, int i);
int						ft_open_file(char *s);
char					*ft_skip_space(char *s);
int						verif_line(char *line);
int						get_size_inst(char *line);
long					ft_atoi_oflow(char *str);
int						verif_jump(char *line, int nb_param);
char					*ft_strjoin_my(char *s1, char *s2);

/*
** 		Free
*/

void					free_file_list(t_file_list **list);
void					clean_env(t_asm *env);

/*
** 		Fonction erreur
*/

void					exit_msg_error(t_asm *env, char *msg, int n_line);
void					exit_msg_header(t_asm *param, int c_er);
void					msg_error(t_asm *env, char *msg, int n_line);
void					ft_print_usage(void);

#endif
