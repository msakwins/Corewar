# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bbeldame <bbeldame@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/06/23 14:08:14 by arosset           #+#    #+#              #
#    Updated: 2018/03/19 23:14:45 by bbeldame         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= 	../asm
CC				=	gcc
CFLAGS			=	-Wall -Wextra -Werror

LIB_PATH		= 	../libft/
LIB				=	../libft/libft.a
LIB_LINK		=	../libft/libft.a

INC_PATH		= 	./include
SRC_PATH		=	./src
SRC_NAME 		=	main.c free_asm.c error.c parser.c ft_utility.c \
					struct_list.c set_name_extension.c parse_body.c \
					print_header.c parse_header.c check_param.c op.c \
					check_body.c parse_params.c finish_asm.c print_body.c\
					get_param.c ft_atoi_oflow.c
OBJ_PATH		=	./obj

OBJ_NAME		=	$(SRC_NAME:.c=.o)
INC_NAME		=	asm.h

OBJ 			= $(addprefix $(OBJ_PATH)/,$(OBJ_NAME))

# COLORS
RESET			=	"\033[00m"
RED				=	"\033[31m"
GREEN			=	"\033[32m"
YELLOW			=	"\033[33m"
BLUE			= 	"\033[34m"
PURPLE			=	"\033[35m"

# MESSAGE
SUCCESS			=	$(GREEN)SUCCESS$(RESET)
OK				=	$(PURPLE)OK$(RESET)
DELETE			=	$(RED)DELETE$(RESET)
TEST 			= 	$(YELLOW)DEBUT TEST$(RESET)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(LIB_LINK) $(CFLAGS) $(OBJ)  -o $@
	@echo "Exec =>"$(YELLOW) $(NAME) $(RESET): $(SUCCESS)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) $(CFLAGS) -o $@ -c $<
	@echo "Obj" [ $< ] $(OK)

clean:
	@rm -rf $(OBJ) $(OBJ_PATH)
	@echo $(DELETE) : $(OBJ) $(OBJ_PATH)
	@make -C $(LIB_PATH) clean

fclean: clean
	@rm -f $(NAME)
	@echo $(DELETE) : $(NAME)

norme:
	@norminette src include

test:
	./asm_zaz test.s && mv test.cor test_zaz.cor
	./asm test.s && diff test.cor test_zaz.cor


re: fclean all

