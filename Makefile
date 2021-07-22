NAME    		= push_swap

SRCS_LIST		= main.c parsing.c ope.c ope2.c ope3.c push_swap.c utils.c 

SRCS            = $(addprefix ${FOLDER}/, ${SRCS_LIST})

HEADER            = includes
FOLDER            = src

LIBFT             = libft

CC                = gcc
CFLAGS            = -Wall -Werror -Wextra -fsanitize=address
RM                = rm -f

all:            $(NAME)

$(NAME):        ${OBJS}
				@make -C src/libft
				@make bonus -C src/libft
				@cp src/libft/libft.a ./
				$(CC) $(CFLAGS) $(SRCS) -I$(HEADER) -L. -lft -o push_swap			

clean:
				@${RM} ${OBJS}
				@make clean -C src/libft

fclean:			clean
				@${RM} ${NAME}
				@make fclean -C src/libft

re:                fclean all

.PHONY: all clean fclean re main
