NAME=libft.a
CC=gcc
CFLAGS=-Wall -Wextra -Werror
RM=rm -f
FILES=ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c ft_strlcpy.c \
ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c \
ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c \
ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
ft_putnbr_fd.c ft_contains.c ft_printf/ft_printf.c ft_printf/hex.c \
ft_printf/hex_util.c ft_printf/printing.c get_next_line/get_next_line.c \
get_next_line/get_next_line_utils.c ft_iswhite_space.c ft_strrepl.c \
ft_streq.c ft_atod.c
EXTRA_FILES=ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c
FILES_OBJ=$(FILES:%.c=%.o)
EXTRA_FILES_OBJ=$(EXTRA_FILES:%.c=%.o)

ifdef BONUS
	ALL_FILES_OBJ=$(FILES_OBJ) $(EXTRA_FILES_OBJ)
else
	ALL_FILES_OBJ=$(FILES_OBJ)
endif

all: $(NAME)

$(NAME): $(ALL_FILES_OBJ)
	ar -rcs $(NAME) $(ALL_FILES_OBJ)

bonus:
	$(MAKE) BONUS=1 all

clean:
	$(RM) $(FILES_OBJ) $(EXTRA_FILES_OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: make all clean fclean bonus re
