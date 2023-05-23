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

#
#
#
SRC_BONUS	=	main_bonus.c
UTILS_BONUS	=	check_files_bonus.c error_bonus.c ft_join.c

# Rutas
DIR_SRC_BONUS	=	$(addprefix bonus/, $(SRC_BONUS))
DIR_UTILS_BONUS	=	$(addprefix bonus_utils/, $(UTILS_BONUS))

# Objetos
OBJ_SRC_BONUS	=	$(DIR_SRC_BONUS:.c=.o)
OBJ_UTILS_BONUS	=	$(DIR_UTILS_BONUS:.c=.o)

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


#
#
#

bonus:	$(LIBFT) $(OBJ_SRC_BONUS) $(OBJ_UTILS_BONUS) $(OBJ_GNL)
	@$(CC) $(CFLAGS) $(LIBFT) $(OBJ_SRC_BONUS) $(OBJ_UTILS_BONUS) $(OBJ_GNL) -o $(NAME)

clean_bonus:
	@make clean -C libft
	@$(RM) $(OBJ_SRC_BONUS) $(OBJ_UTILS_BONUS) $(OBJ_GNL)

fclean_bonus: clean_bonus
	@make fclean -C libft
	@$(RM) $(NAME)

re_bonus: fclean_bonus bonus
.PHONY:	clean fclean re clean_bonus re_bonus fclean_bonus