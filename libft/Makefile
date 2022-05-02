NAME = libft.a

FLAGS = -Wall -Werror -Wextra -c
LIST = list
OBJ_DIR = obj

SRC = 	ft_isalpha.c ft_isdigit.c ft_isalnum.c \
		ft_isascii.c ft_isprint.c ft_strlen.c \
		ft_memset.c ft_bzero.c ft_memcpy.c \
		ft_memmove.c ft_strlcpy.c ft_strlcat.c \
		ft_toupper.c ft_tolower.c ft_strchr.c \
		ft_strrchr.c ft_strncmp.c ft_memchr.c \
		ft_memcmp.c ft_strnstr.c ft_atoi.c \
		ft_calloc.c ft_strdup.c ft_substr.c \
		ft_strjoin.c ft_strtrim.c ft_split.c \
		ft_itoa.c ft_strmapi.c ft_striteri.c \
        ft_printf/hex.c ft_printf/hex_util.c \
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
        ft_putnbr_fd.c ft_contains.c ft_printf/ft_printf.c \
        ft_printf/printing.c get_next_line/get_next_line.c \
        get_next_line/get_next_line_utils.c ft_iswhite_space.c \
        ft_strrepl.c ft_streq.c ft_atod.c $(LIST)/ft_lstadd_back.c \
        $(LIST)/ft_lstadd_front.c $(LIST)/ft_lstclear.c $(LIST)/ft_lstdelone.c \
        $(LIST)/ft_lstiter.c $(LIST)/ft_lstlast.c $(LIST)/ft_lstmap.c $(LIST)/ft_lstnew.c $(LIST)/ft_lstsize.c

INC = -I ../../includes

OBJ = $(patsubst %,$(OBJ_DIR)/%,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@ar -crs $(NAME) $(OBJ)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@gcc $(FLAGS) $(INC) -o $@ $<

clean:
	@rm -rf $(OBJ_DIR)

fclean:	clean
	@rm -f $(NAME)

re: fclean all

norm:
	norminette $(SRC) $(HEADER) $(BONUS_SRC)

.PHONY: all clean fclean re bonus norm