NAME	=	libftprintf.a
RM		=	rm -f
CC		=	cc
CFLAGS	=	-Wall -Werror -Wextra
SRCS	=	ft_printf_utils.c \
			ft_printf.c \
			ft_put_hex.c \
			ft_putchar.c \
			ft_putnbr.c \
			ft_putptr_hex.c \
			ft_putstr.c \
			ft_put_un_nbr.c
# BONUS	=	TO DO
OBJS	=	$(SRCS:.c=.o)
# BONUS_OBJS	=	TO DO
INCLUDE	=	ft_printf.h
LIB		=	ar -rcs

all:	$(NAME)

$(NAME):	$(OBJS) $(INCLUDE)
	@$(LIB) -r $@ $?
# BONUS:	$(BONUS_OBJS) $(OBJS)
#	$(LIB) -r $@ $?
%.o:%.c
	@$(CC) -c $(CFLAGS) $?
clean:
	@$(RM) $(OBJS)
fclean:	clean
	@$(RM) $(NAME)
re: fclean all

.PHONY: re fclean clean
