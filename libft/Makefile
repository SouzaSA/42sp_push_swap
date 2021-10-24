.DEFAULT_GOAL	:=  all

NAME			=	libft.a

LIB_DIR			=	lib
OBJ_DIR			=	obj
INC_DIR			=	inc
SRC_DIR			=	src
IS_DIR			=	is
LST_DIR			=	lst
MEM_DIR			=	mem
PUT_DIR			=	put
STR_DIR			=	str

INCS			=	-I ./${INC_DIR}

IS				=	ft_isalnum.c	\
					ft_isalpha.c	\
					ft_isascii.c	\
					ft_isdigit.c	\
					ft_isprint.c	\
					ft_isspace.c

LST				=	ft_lstadd_back.c	\
					ft_lstadd_front.c	\
					ft_lstclear.c	\
					ft_lstdelone.c	\
					ft_lstiter.c	\
					ft_lstlast.c	\
					ft_lstmap.c	\
					ft_lstnew.c	\
					ft_lstsize.c

MEM				=	ft_bzero.c	\
					ft_calloc.c	\
					ft_memchr.c	\
					ft_memcmp.c	\
					ft_memcpy.c	\
					ft_memmove.c	\
					ft_memset.c

PUT				=	ft_putchar_fd.c	\
					ft_putendl_fd.c	\
					ft_putnbr_fd.c	\
					ft_putstr_fd.c

STR				=	ft_atoi.c	\
					ft_itoa.c	\
					ft_split.c	\
					ft_strchr.c	\
					ft_strcmp.c	\
					ft_strdup.c	\
					ft_striteri.c \
					ft_strjoin.c	\
					ft_strlcat.c	\
					ft_strlcpy.c	\
					ft_strlen.c	\
					ft_strmapi.c	\
					ft_strncmp.c	\
					ft_strnstr.c	\
					ft_strrchr.c	\
					ft_strtolower.c	\
					ft_strtrim.c	\
					ft_substr.c	\
					ft_tolower.c	\
					ft_toupper.c

SRCS			=	${ADD_DIR_IS}	\
					${ADD_DIR_LST}	\
					${ADD_DIR_MEM}	\
					${ADD_DIR_PUT}	\
					${ADD_DIR_STR}

ADD_DIR_IS		=	${addprefix ${IS_DIR}/,${IS}}
ADD_DIR_LST		=	${addprefix ${LST_DIR}/,${LST}}
ADD_DIR_MEM		=	${addprefix ${MEM_DIR}/,${MEM}}
ADD_DIR_PUT		=	${addprefix ${PUT_DIR}/,${PUT}}
ADD_DIR_STR		=	${addprefix ${STR_DIR}/,${STR}}
LIB_FILE		=	${addprefix ${LIB_DIR}/,${NAME}}
SRCS_DIR		=	${addprefix ${SRC_DIR}/,${SRCS}}

OBJS			=	${addprefix ./${OBJ_DIR}/,${SRCS:.c=.o}}

CC				=	clang
CFLAGS			=	-Wall -Wextra -Werror

RM				=	rm -rf

DIR_GUARD		=	mkdir -p ${@D}

${OBJ_DIR}/%.o:	${SRC_DIR}/%.c
				${DIR_GUARD}
				${CC} ${CFLAGS} ${INCS} -c $< -o $@

${NAME}:		${LIB_FILE}

${LIB_FILE}:	${OBJS}
				${DIR_GUARD}
				ar rcs ${LIB_FILE} ${OBJS}

all:			${NAME}

clean:
				${RM} ${OBJ_DIR}

fclean: 		clean
				${RM} ${LIB_DIR}

re:				fclean all

.PHONY:			all clean fclean re ${NAME}
