NAME		=	pipex
CC			=	cc
CFLAGS		=	-Wall -Werror -Wextra
RM			=	rm -rf
SANITIZE	=	-fsanitize=address
DEBUG		=	-g3
# Archivos
SRC			=	main.c childs.c
UTILS		=	error.c find_path.c ft_join.c free.c
GNL			=	get_next_line.c get_next_line_utils.c
# Rutas
DIR_SRC		=	$(addprefix mandatory/, $(SRC))
DIR_UTILS	=	$(addprefix utils/, $(UTILS))
DIR_GNL		=	$(addprefix gnl/, $(GNL))
# Objetos
OBJ_SRC		=	$(DIR_SRC:.c=.o)
OBJ_UTILS	=	$(DIR_UTILS:.c=.o)
OBJ_GNL		=	$(DIR_GNL:.c=.o)
LIBFT		=	libft/libft.a

all:	$(NAME)

$(NAME):	$(LIBFT) $(OBJ_GNL) $(OBJ_SRC) $(OBJ_UTILS)
	@$(CC) $(CFLAGS) $(LIBFT) $(OBJ_GNL) $(OBJ_SRC) $(OBJ_UTILS) -o $(NAME)

$(LIBFT):
	@make -C libft
sanitize:	$(LIBFT) $(OBJ_GNL) $(OBJ_SRC) $(OBJ_UTILS)
	@$(CC) $(SANITIZE) $(CFLAGS) $(LIBFT) $(OBJ_GNL) $(OBJ_SRC) $(OBJ_UTILS) -o $(NAME)

debug:	$(LIBFT) $(OBJ_GNL) $(OBJ_SRC) $(OBJ_UTILS)
	@$(CC) $(DEBUG) $(CFLAGS) $(LIBFT) $(OBJ_GNL) $(OBJ_SRC) $(OBJ_UTILS) -o $(NAME)

clean:
	@make clean -C libft
	@$(RM) $(OBJ_GNL) $(OBJ_SRC) $(OBJ_UTILS)

fclean:	clean
	@make fclean -C libft
	@$(RM) $(NAME)

re:	fclean all

.PHONY:	clean fclean re