# output
NAME =		minish

AR =		ar rcs
RM =		rm -f

# compile option
CC =		gcc
CFLAGS =	-Wall -Wextra -Werror

# library
LIBFT_DIR =	./includes/libft/
LIBFT =	libft.a

# source files
MAIN_DIR =	./
MAIN_SRCS = \
			main.c

WOPARK_DIR =	./wopark/
WOPARK_SRCS = \
			parse.c

JUNGHWKI_DIR =	./junghwki/
JUNGHWKI_SRCS = \
			envv_lst.c \
			execute_builtin.c \
			ft_cd.c \
			ft_echo.c \
			ft_export.c \
			ft_pwd.c \
			ft_unset.c \
			utils.c

MANDATORY =	\
			$(addprefix $(MAIN_DIR), $(MAIN_SRCS)) \
			$(addprefix $(WOPARK_DIR), $(WOPARK_SRCS)) \
			$(addprefix $(JUNGHWKI_DIR), $(JUNGHWKI_SRCS))

OBJS =	$(MANDATORY:.c=.o)

# roles
all :	$(NAME)

# library :	$(LIBFT)

$(NAME) :	$(LIBFT) $(OBJS)
			$(CC) $(CFLAGS) $< -o $(NAME) $(LIBFT) $(OBJS)

$(LIBFT) :
			make -C $(LIBFT_DIR)
			make bonus -C $(LIBFT_DIR)
			mv $(LIBFT_DIR)$(LIBFT) .

clean :
			$(RM) $(OBJS) $(LIBFT)
			make clean -C $(LIBFT_DIR)

fclean : clean
			$(RM) $(NAME)

re : fclean $(NAME)

.PHONY: all clean fclean re