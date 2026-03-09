# ===========================
#      PROJECT SETTINGS
# ===========================
NAME        = cub3D

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3
INCLUDES    = -Iincludes -I$(MLX_DIR)

SRC_DIR     = srcs
OBJ_DIR     = obj
MLX_DIR     = minilibx-linux
LIBFT_DIR   = libft

# ===========================
#      SOURCE / OBJECTS
# ===========================
SRCS_FILES  = parsing/main.c \
              parsing/check_args.c \
              parsing/get_textures.c \
              parsing/get_colors.c \
              parsing/parse_rgb.c \
              parsing/parsing.c \
              parsing/init.c \
              parsing/free.c \
			  parsing/parse_map.c \
			  parsing/parse_map2.c \
			  parsing/check_map.c \
			  parsing/flood_fill.c \
			  parsing/minimap.c \
			  parsing/events.c \
			  parsing/movement.c \

SRCS        = $(addprefix $(SRC_DIR)/, $(SRCS_FILES))
OBJS        = $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# ===========================
#      MLX (Linux)
# ===========================
MLX_LIB     = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS   = -L$(MLX_DIR) $(MLX_LIB) -lXext -lX11 -lm

LIBFT_LIB   = $(LIBFT_DIR)/libft.a
LIBFT_FLAGS = -L$(LIBFT_DIR) -lft

# ===========================
#      DEFAULT RULE
# ===========================
all: $(NAME)

# ===========================
#      BUILD EXECUTABLE
# ===========================
$(NAME): $(LIBFT_LIB) $(MLX_LIB) $(OBJS)
	@echo "Compilation de $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) $(LIBFT_FLAGS) -lm -o $(NAME)
	@echo "✔️ Compilation terminée"

# ===========================
#      BUILD OBJECTS
# ===========================
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# ===========================
#      BUILD MLX
# ===========================
$(MLX_LIB):
	@echo "[MLX] Building MiniLibX..."
	@$(MAKE) -C $(MLX_DIR)

# ===========================
#      BUILD LIBFT
# ===========================
$(LIBFT_LIB):
	@echo "[LIBFT] Building Libft..."
	@$(MAKE) -s -C $(LIBFT_DIR)

# ===========================
#      NORM RULE
# ===========================
norm:
	@echo "[NORM] Checking code style..."
	@norminette $(SRCS) include/*.h | sed 's/Error/🔴 Error/g' | sed 's/Warning/🟡 Warning/g'

# ===========================
#      CLEAN RULES
# ===========================
clean:
	@echo "[CLEAN] Removing object files"
	@rm -rf $(OBJ_DIR)
	@$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	@echo "[CLEAN] Removing executable"
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

# ===========================
#      PHONY
# ===========================
.PHONY: all clean fclean re norm
