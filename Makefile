FILES 	=	main.c \
		validation.c\
		parsing.c\
		token.c\
		dirent.c\
		execute.c\
		size.c\
		name.c\
		date.c\
		mime.c\
		dir.c

S_PATH	=	srcs/
O_PATH	=	objs/
I_PATH	=	includes/

SRCS	=	${addprefix ${S_PATH}, ${FILES}}
OBJS	=	${addprefix ${O_PATH}, ${FILES:.c=.o}}

CC		=	gcc

NAME	=	ftc

RM		=	rm -rf

CFLAGS	= 	-Werror -Wall -O0 -g3 -fno-omit-frame-pointer -fno-optimize-sibling-calls -pthread

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
			@echo "Removing${S}${S} {O_PATH}${S} "

fclean:		clean
			@${RM} ${NAME}
			@echo "Removing${S}${S} ${NAME}${S} "

space:
			@echo " "

re:			fclean space all

test:		@mv ftc tests
			@./test_args


.PHONY: all clean fclean re build space