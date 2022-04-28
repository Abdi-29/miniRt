NAME = libft.a

FLAGS = -Wall -Werror -Wextra -c

OBJ_DIR = obj

SRC = 	ft_atoi.c ft_bzero.c ft_calloc.c ft_itoa.c\
		ft_isalnum.c ft_isalpha.c ft_isascii.c \
		ft_isdigit.c ft_isprint.c ft_memchr.c \
		ft_memcmp.c ft_memcpy.c ft_memmove.c \
		ft_memset.c ft_putchar_fd.c ft_whitespaces.c \
		ft_putendl_fd.c ft_putnbr_fd.c\
		ft_putstr_fd.c ft_split.c ft_strchr.c \
		ft_strdup.c ft_striteri.c ft_strjoin.c \
		ft_strlcat.c ft_strlcpy.c ft_strlen.c \
		ft_strmapi.c ft_strncmp.c ft_strnstr.c \
		ft_strrchr.c ft_strtrim.c ft_strncpy.c \
		ft_substr.c get_next_line.c ft_whitespaces.c \
		ft_tolower.c ft_toupper.c \
		ft_lstadd_back_bonus.c ft_lstadd_front_bonus.c \
		ft_lstclear_bonus.c ft_lstdelone_bonus.c \
		ft_lstiter_bonus.c ft_lstlast_bonus.c \
		ft_lstmap_bonus.c ft_lstnew_bonus.c ft_lstsize_bonus.c \

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