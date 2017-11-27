NAME		=	libftprintf.a
CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

_SRCS		=	ft_printf.c \
				printf_handlers.c \

SRCS_DIR	=	.
SRCS		=	$(patsubst %,$(SRCS_DIR)/%,$(_SRCS))
OBJS		=	$(SRCS:.c=.o)

LIBFT		=	libft

# COLORS
_GREY=\x1b[30m
_RED=\x1b[31m
_GREEN=\x1b[32m
_YELLOW=\x1b[33m
_BLUE=\x1b[34m
_PURPLE=\x1b[35m
_CYAN=\x1b[36m
_WHITE=\x1b[37m
_END=\x1b[0m
_SUCCESS=$(_GREEN)

.PHONY: all clean fclean re $(LIBFT)

all: $(NAME)

$(NAME): $(LIBFT)
	@echo "$(_RED)Compiling$(_END) $(NAME) $(_GREEN)...$(_END)"
	@$(CC) -c $(CFLAGS) $(SRCS) -I$(LIBFT)/includes
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)
	@echo  "$(NAME) : $(_SUCCESS)done$(_END)"

$(LIBFT):
	@make -C $(LIBFT)

clean:
	@/bin/rm -f $(OBJS)
	@make clean -C $(LIBFT)

fclean: clean
	@/bin/rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all
