# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/18 16:15:40 by bbeldame          #+#    #+#              #
#    Updated: 2018/03/19 23:14:15 by bbeldame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../corewar

FLAGS = -Wall -Wextra -Werror

LIBFTA = libft.a

LIBFTDIR = ../libft
OBJDIR = ./obj/
INCDIR = ./includes
SRCDIR = ./srcs/
FCDIR = $(SRCDIR)funcs/
VPATH = $(SRCDIR):$(FCDIR)

SRCS_NAME =	main.c \
			arena.c \
			init.c \
			parse_args.c \
			exit.c \
			check.c \
			parse_files.c \
			utils.c \
			lifecycle.c \
			manage_opcode.c \
			get_data.c \
			dump.c \
			visu.c \
			get_data_utils.c \
			new_cycle.c \
			init_visu.c

FUNCS_NAME = func_add.c \
			func_aff.c \
			func_and.c \
			func_fork_lfork.c \
			func_ld_lld.c \
			func_ldi_lldi.c \
			func_live.c \
			func_or.c \
			func_st.c \
			func_sti.c \
			func_sub.c \
			func_xor.c \
			func_zjmp.c

OBJS = $(addprefix $(OBJDIR),$(SRCS_NAME:.c=.o))
OBJS += $(addprefix $(OBJDIR),$(FUNCS_NAME:.c=.o))
LIBFT = $(addprefix $(LIBFTDIR)/,$(LIBFTA))

FUNCS = $(addprefix $(FCDIR),$(FUNCS_NAME))

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

SRCS = $(addprefix $(SRCDIR),$(SRCS_NAME))
SRCS += $(FUNCS)

all: $(NAME)

obj:
		@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:%.c
		@gcc $(FLAGS) -I $(INCDIR) -I $(LIBFTDIR) -o $@ -c $<

$(NAME): obj $(OBJS)
		@gcc $(OBJS) $(LIBFT) -lm -o $(NAME) -lncurses
		@echo "$(GREEN)---------corewar compiled---------$(NC)"

norme:
		@norminette includes srcs

clean:
		@rm -rf $(OBJDIR)

fclean:	clean
		@rm -f $(NAME)
		@echo "$(GREEN)----corewar removed completely----$(NC)"

test:
	echo $(SRCS)

re: fclean all
