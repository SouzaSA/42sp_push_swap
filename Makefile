DEFAULT_GOAL:=	all

NAME		=	push_swap

NAME_BONUS	=	checker

PUSH_SWAP_DIR	=	push_swap
CHECKER_DIR	=	checker
OBJ_DIR		=	obj
INC_DIR		=	inc


CC			=	clang
CFLAGS		=	-Wall -Wextra -Werror
INCS		=	-I ${INC_DIR}
SAN			=	-g -fsanitize=address

SRCS		=

BONUS		=

SRCS_DIR	=	${addprefix ${PUSH_SWAP_DIR}/,${SRCS}}

BONUS_DIR	=	${addprefix ${CHECKER_DIR}/,${BONUS}}

OBJS		=	${addprefix ./${OBJ_DIR}/,${SRCS_DIR:.c=.o}}

BONUS_OBJS	=	${addprefix ./${OBJ_DIR}/,${BONUS_DIR:.c=.o}}

RM			=	@rm -rf

DIR_GUARD	=	@mkdir -p ${@D}

${OBJ_DIR}/%.o:	${SRC_DIR}/%.c
			${DIR_GUARD}
			${CC} ${CFLAGS} ${INCS} -c $< -o $@

${NAME}:	${OBJS}
			${CC} ${CFLAGS} ${OBJS} ${INCS} -o ${NAME}

all:		${NAME}

bonus:		${BONUS_OBJS}
			${CC} ${CFLAGS} ${BONUS_OBJS} -o ${NAME} ${INCS}

san:		${OBJS}
			${CC} ${SAN} ${CFLAGS} ${OBJS} -o ${NAME} ${INCS}

bonus_san:	${BONUS_OBJS}
			${CC} ${SAN} ${CFLAGS} ${BONUS_OBJS} -o ${NAME} ${INCS}

clean:
			${RM} ${OBJ_DIR}

fclean: 	clean
			${RM} ${NAME}

re:			fclean all

.PHONY:		all bonus san clean fclean re
