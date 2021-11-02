DEFAULT_GOAL	:=	all

NAME			=	push_swap

NAME_BONUS		=	checker

SRC_DIR			=	src
PUSH_SWAP_DIR	=	push_swap
CHECKER_DIR		=	checker
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

SRCS			=	ft_check_args.c	\
					ft_check_ordered.c	\
					ft_destroy_stack.c	\
					ft_handler_push.c	\
					ft_handler_reverse_rotate.c	\
					ft_handler_rotate.c	\
					ft_handler_swap.c	\
					ft_load_stack.c	\
					ft_main.c	\
					ft_ordering_merge_sort.c	\
					ft_push_swap.c

BONUS			=

SRCS_DIR		=	${addprefix ${PUSH_SWAP_DIR}/,${SRCS}}

BONUS_DIR		=	${addprefix ${CHECKER_DIR}/,${BONUS}}

OBJS			=	${addprefix ./${OBJ_DIR}/,${SRCS_DIR:.c=.o}}

BONUS_OBJS		=	${addprefix ./${OBJ_DIR}/,${BONUS_DIR:.c=.o}}

RM				=	@rm -rf

DIR_GUARD		=	@mkdir -p ${@D}

${OBJ_DIR}/%.o:	${SRC_DIR}/%.c
				${DIR_GUARD}
				make -C ${LIBFT_DIR}
				${CC} ${CFLAGS} ${INCS} -c $< -o $@

${NAME}:		${OBJS}
				${CC} ${CFLAGS} ${OBJS} ${LIBS} ${INCS} -o ${NAME}

all:			${NAME}

bonus:			${BONUS_OBJS}
				${CC} ${CFLAGS} ${BONUS_OBJS} -o ${NAME} ${INCS}

san:			${OBJS}
				${CC} ${SAN} ${CFLAGS} ${OBJS} -o ${NAME} ${INCS}

bonus_san:		${BONUS_OBJS}
				${CC} ${SAN} ${CFLAGS} ${BONUS_OBJS} -o ${NAME} ${INCS}

clean:
				${RM} ${OBJ_DIR}

fclean: 		clean
				${RM} ${NAME}

re:				fclean all

.PHONY:			all bonus san clean fclean re
