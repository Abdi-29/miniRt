NAME = libft.a

FLAGS = -Wall -Werror -Wextra -c
OBJ_DIR = obj

PRINT =	printing.c hex.c hex_util.c ft_printf.c
GNL =	get_next_line.c get_next_line_utils.c
LIST =	ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
		ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c \
		ft_lstsize.c ft_lstadd_back.c
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
		ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
		ft_putnbr_fd.c ft_contains.c ft_iswhite_space.c \
		ft_strrepl.c ft_streq.c ft_atod.c \
		ft_ends_with.c \
		$(addprefix list/, $(LIST)) \
		$(addprefix get_next_line/, $(GNL)) \
		$(addprefix ft_printf/, $(PRINT))

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