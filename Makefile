FILES 	=	main.c \
		validation.c

S_PATH	=	srcs/
O_PATH	=	objs/
I_PATH	=	includes/

SRCS	=	${addprefix ${S_PATH}, ${FILES}}
OBJS	=	${addprefix ${O_PATH}, ${FILES:.c=.o}}

CC		=	gcc

NAME	=	ftc

RM		=	rm -rf

CFLAGS	= 	-Werror -Wall -O0 -g3 -fsanitize=address -fno-omit-frame-pointer -fno-optimize-sibling-calls -pthread

${O_PATH}%.o:	${S_PATH}%.c
				@mkdir -p ${dir $@}
				@${CC} ${CFLAGS} -c $< -o $@
				@echo "Compiling"


${NAME}:			${OBJS}
					@${CC} ${OBJS} ${CFLAGS} -o ${NAME} -I ${I_PATH}
					@echo "Compilation is completed !"

all:		${NAME}

clean:
			@${RM} ${O_PATH}*
			@echo "${BOLD}${SRED}Removing${S}${S} ${IGREY}${O_PATH}${S} 🗑️"

fclean:		clean
			@${RM} ${NAME}
			@echo "${BOLD}${SRED}Removing${S}${S} ${IGREY}${NAME}${S} 🗑️"

space:
			@echo " "

re:			fclean space all

.PHONY: all clean fclean re build space