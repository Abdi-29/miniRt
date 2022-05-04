NAME = miniRT

FLAGS = -g
SRC_DIR = srcs
OBJ_DIR = obj
INC_DIR = includes
LIBFT_DIR = ./libft
MLX_DIR = ./minilibx

LIBFT = $(LIBFT_DIR)/libft.a
MLX = $(MLX_DIR)/libmlx.dylib

LINKING_FLAGS = -lglfw -ldl -lm -O3 -L "/Users/$(USER)/.brew/opt/glfw/lib/"

PARSING = parse_ACL.c parse_file.c parse_lines.c parse_plspcy.c
SRC_FILES = miniRT.c color.c coords.c util.c camera.c vectors.c \
$(addprefix parsing/, $(PARSING))
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ = $(patsubst $(SRC_DIR)/%,$(OBJ_DIR)/%,$(SRC:.c=.o))

INC = -I $(INC_DIR)

COM_COLOR = \033[0;33m
OBJ_COLOR = \033[0;36m
OK_COLOR = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR = \033[0;33m
NO_COLOR = \033[m
PRG_COLOR = \033[0;35m

OK_STRING = "[OK]"
ERROR_STRING = "[ERROR]"
WARN_STRING = "[WARNING]"
COM_STRING = "Compiling"

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(MLX)
	@gcc $(FLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME) $(LINKING_FLAGS) 2> $@.log; \
		RESULT=$$?; \
		if [ $$RESULT -ne 0 ]; then \
			printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(PRG_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"; \
		elif [ -s $@.log ]; then \
			printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(PRG_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"; \
		else  \
			printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(PRG_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"; \
		fi; \
		cat $@.log; \
		rm -f $@.log; \
		exit $$RESULT


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@gcc $(FLAGS) $(INC) $(READLINE_INC) -c -o $@ $< 2> $@.log; \
		RESULT=$$?; \
		if [ $$RESULT -ne 0 ]; then \
			printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"; \
		elif [ -s $@.log ]; then \
			printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $@" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"; \
		else  \
			printf "%-60b%b" "$(COM_COLOR)$(COM_STRING)$(OBJ_COLOR) $(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"; \
		fi; \
		cat $@.log; \
		rm -f $@.log; \
		exit $$RESULT

$(LIBFT):
	@printf "$(COM_COLOR)$(COM_STRING) $(LIB_COLOR)$(@)$(NO_COLOR)\n";
	@$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	@printf "$(COM_COLOR)$(COM_STRING) $(LIB_COLOR)$(@)$(NO_COLOR)\n";
	@make -C $(MLX_DIR)

clean:
	@printf "%b" "$(COM_COLOR)Cleaning $(LIB_COLOR)libft\n"
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@printf "%b" "$(ERROR_COLOR)Removing $(OBJ_COLOR)object files\n"
	@rm -rf $(OBJ_DIR)

fclean:	clean
	@printf "%b" "$(ERROR_COLOR)Removing $(PRG_COLOR) $(NAME)\n"
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re