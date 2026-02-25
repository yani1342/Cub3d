# ===========================
#      PROJECT SETTINGS
# ===========================
NAME        = cube3D

CC          = cc
CFLAGS      = -Wall -Wextra -Werror -g3
INCLUDES    = -I. -Iincludes -I$(MLX_DIR)

SRC_DIRS    = src_exec src_pars scr_gc
OBJ_DIR     = obj
MLX_DIR     = minilibx-linux

# ===========================
#      SOURCE / OBJECTS
# ===========================
SRCS        = $(foreach dir,$(SRC_DIRS),$(wildcard $(dir)/*.c))
OBJS        = $(SRCS:%.c=$(OBJ_DIR)/%.o)

# ===========================
#      MLX (Linux)
# ===========================
MLX_LIB     = $(MLX_DIR)/libmlx_Linux.a
MLX_FLAGS   = -L$(MLX_DIR) $(MLX_LIB) -lXext -lX11 -lm

# ===========================
#      DEFAULT RULE
# ===========================
all: $(NAME)

# ===========================
#      BUILD EXECUTABLE
# ===========================
$(NAME): $(MLX_LIB) $(OBJS)
	@echo "Compilation de $(NAME)..."
	@$(CC) $(CFLAGS) $(OBJS) $(MLX_FLAGS) -o $(NAME)
	@echo "✔️ Compilation terminée"

# ===========================
#      BUILD OBJECTS
# ===========================
$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# ===========================
#      BUILD MLX
# ===========================
$(MLX_LIB):
	@echo "[MLX] Building MiniLibX..."
	@$(MAKE) -C $(MLX_DIR)

# ===========================
#      NORM RULE
# ===========================
norm:
	@echo "[NORM] Checking code style..."
	@norminette $(SRCS) *.h | sed 's/Error/🔴 Error/g' | sed 's/Warning/🟡 Warning/g'

# ===========================
#      CLEAN RULES
# ===========================
clean:
	@echo "[CLEAN] Removing object files"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "[CLEAN] Removing executable"
	@rm -f $(NAME)

re: fclean all

# ===========================
#      PHONY
# ===========================
.PHONY: all clean fclean re norm
