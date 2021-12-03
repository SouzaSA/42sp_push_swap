# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sde-alva <sde-alva@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/13 20:32:03 by sde-alva          #+#    #+#              #
#    Updated: 2021/11/28 14:53:44 by sde-alva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

.DEFAULT_GOAL	:=	all

NAME			=	push_swap

NAME_BONUS		=	checker

SRC_DIR			=	src
PUSH_SWAP_DIR	=	push_swap
CHECKER_DIR		=	checker
SHARED_DIR		=	shared
OBJ_DIR			=	obj
INC_DIR			=	inc

LIBFT			=	ft
LIBFT_DIR		=	libft
LIBFT_INC		=	${LIBFT_DIR}/inc
LIBFT_LIB		=	${LIBFT_DIR}/lib

CC				=	clang
CFLAGS			=	-Wall -Wextra -Werror
INCS			=	-I ${INC_DIR} -I ${LIBFT_INC}
LIBS			=	-L ${LIBFT_LIB} -l ${LIBFT}
SAN				=	-g -fsanitize=address

SHARED_FILES	=	ft_check_args.c	\
					ft_check_sorted.c	\
					ft_destroy_splited_vals.c	\
					ft_destroy_stack.c	\
					ft_get_num_vals.c	\
					ft_get_splited_vals.c	\
					ft_load_stack.c	\
					ft_load_values.c	\
					ft_worker_push.c	\
					ft_worker_reverse_rotate.c	\
					ft_worker_rotate.c	\
					ft_worker_swap.c

SRCS			=	ft_check_reverse_sorted.c	\
					ft_handler_push.c	\
					ft_handler_reverse_rotate.c	\
					ft_handler_rotate.c	\
					ft_handler_swap.c	\
					ft_main.c	\
					ft_manage_stk_a.c	\
					ft_manage_stk_b.c	\
					ft_push_swap.c	\
					ft_quick_pivot.c	\
					ft_sort_four.c	\
					ft_sort_stack_a_three.c	\
					ft_sort_stack_a_two.c	\
					ft_sort_stack_a.c	\
					ft_sort_stack_b_three.c	\
					ft_sort_stack_b_two.c	\
					ft_sort_three.c \
					ft_write_move.c \
					${SHARED_DIR_ADD}

BONUS			=	ft_checker.c	\
					ft_main.c	\
					ft_exec_cmds.c	\
					ft_exec_push.c	\
					ft_exec_reverse_rotate.c	\
					ft_exec_rotate.c	\
					ft_exec_swap.c	\
					${SHARED_DIR_ADD}

SHARED_DIR_ADD	=	${addprefix ../${SHARED_DIR}/,${SHARED_FILES}}

SRCS_DIR		=	${addprefix ${PUSH_SWAP_DIR}/,${SRCS}}

BONUS_DIR		=	${addprefix ${CHECKER_DIR}/,${BONUS}}

OBJS			=	${addprefix ./${OBJ_DIR}/,${SRCS_DIR:.c=.o}}

BONUS_OBJS		=	${addprefix ./${OBJ_DIR}/,${BONUS_DIR:.c=.o}}

RM				=	@rm -rf

DIR_GUARD		=	@mkdir -p ${@D}

${OBJ_DIR}/%.o:	${SRC_DIR}/%.c
				${DIR_GUARD}
				${CC} ${CFLAGS} ${INCS} -c $< -o $@

${NAME}:		${OBJS}
				make -C ${LIBFT_DIR}
				${CC} ${CFLAGS} ${OBJS} ${LIBS} ${INCS} -o ${NAME}

${NAME_BONUS}:	${BONUS_OBJS}
				make -C ${LIBFT_DIR}
				${CC} ${CFLAGS} ${BONUS_OBJS} ${LIBS} ${INCS} -o ${NAME_BONUS}

all:			${NAME}

bonus:			${NAME_BONUS}

san:			${OBJS}
				${CC} ${SAN} ${CFLAGS} ${OBJS} ${LIBS} ${INCS} -o ${NAME}

bonus_san:		${BONUS_OBJS}
				${CC} ${SAN} ${CFLAGS} ${BONUS_OBJS} ${LIBS} ${INCS} -o ${NAME}

clean:
				${RM} ${OBJ_DIR}
				make -C ${LIBFT_DIR} clean

fclean: 		clean
				${RM} ${NAME}
				${RM} ${NAME_BONUS}
				make -C ${LIBFT_DIR} fclean

re:				fclean all

.PHONY:			all bonus san clean fclean re
