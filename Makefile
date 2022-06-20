NAME = miniRT

FLAGS = -Wall -Wextra -Werror -g
SRC_DIR = srcs
OBJ_DIR = obj
INC_DIR = includes
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a
MLX_DIR = MLX42
MLX = $(MLX_DIR)/libmlx42.a
INC = -I $(INC_DIR)

LINKING_FLAGS = -lglfw -ldl -lm -O3 -L "/Users/$(USER)/.brew/opt/glfw/lib/"

PARSING = parse_file.c parse_lines.c parse_plane.c parse_cylinder.c \
			parse_sphere.c parse_ambient.c parse_light.c parse_camera.c
VECTOR = operator.c vector.c
RAY = color.c ray.c ligth.c
INTERSECTIONS = plane.c sphere.c cylinder.c
SRC_FILES = miniRT.c color.c coords.c util.c vectors.c mlx.c free_list.c \
$(addprefix parsing/, $(PARSING)) $(addprefix vectorlib/, $(VECTOR)) \
$(addprefix ray/, $(RAY)) $(addprefix intesections/, $(INTERSECTIONS))
SRC = $(addprefix $(SRC_DIR)/, $(SRC_FILES))

OBJ = $(patsubst %,$(OBJ_DIR)/%,$(SRC:.c=.o))

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ) $(MLX)
	gcc $(FLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME) $(LINKING_FLAGS)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	gcc $(FLAGS) $(INC) -c -o $@ $<

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(MLX):
	$(MAKE) -C $(MLX_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR)/ fclean
	$(MAKE) -C $(MLX_DIR)/ fclean
	rm -rf $(OBJ_DIR)

fclean:	clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
