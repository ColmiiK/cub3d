#Variables

USERNAME = $(shell whoami)
NAME = cub3d
NAME_B = cub3d_bonus
INCLUDE = include
HEADER = $(INCLUDE)/$(NAME).h
HEADER_B = $(INCLUDE)/$(NAME)_bonus.h
LIBFT = lib/libft
MLX42 = lib/MLX42
SRC_DIR_B = src_bonus/
SRC_DIR = src/
OBJ_DIR_B = obj_bonus/
OBJ_DIR = obj/
CC = clang
CFLAGS = -Wall -Werror -Wextra
AR = ar rcs

# Colors

DEF_COLOR = $(shell tput sgr0)
GRAY = $(shell tput setaf 0)
RED = $(shell tput setaf 1)
GREEN = $(shell tput setaf 2)
YELLOW = $(shell tput setaf 3)
BLUE = $(shell tput setaf 4)
MAGENTA = $(shell tput setaf 5)
CYAN = $(shell tput setaf 6)
WHITE = $(shell tput setaf 7)

#Sources
	
SRC_FILES = main cleanup utils \
			parse/parse_map \
			parse/read_cub \
			parse/extract_legend \
			parse/extract_legend_utils \
			parse/check_map \
			parse/floodfill_map \
			game/game_loop \
			game/generic_hook \
			game/key_hook \
			game/minimap \
			game/movement \
			game/draw \
			raycast/first_step \
			raycast/init_raycast \
			raycast/ray_defines \
			raycast/ray_utils \
			raycast/raycast_loop \
			textures/texture \

SRC_FILES_B = main_bonus cleanup_bonus utils_bonus \
			parse/parse_map_bonus \
			parse/read_cub_bonus \
			parse/extract_legend_bonus \
			parse/extract_legend_utils_bonus \
			parse/check_map_bonus \
			parse/floodfill_map_bonus \
			game/game_loop_bonus \
			game/load_sprites_bonus \
			game/generic_hook_bonus \
			game/mouse_hook_bonus \
			game/key_hook_bonus \
			game/minimap_bonus \
			game/movement_bonus \
			game/draw_bonus \
			raycast/first_step_bonus \
			raycast/init_raycast_bonus \
			raycast/ray_defines_bonus \
			raycast/ray_utils_bonus \
			raycast/raycast_loop_bonus \
			textures/texture_bonus \

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
SRC_B = $(addprefix $(SRC_DIR_B), $(addsuffix .c, $(SRC_FILES_B)))
OBJ_B = $(addprefix $(OBJ_DIR_B), $(addsuffix .o, $(SRC_FILES_B)))
OBJF = .cache_exists

###

all:		$(NAME)


bonus:		$(NAME_B)

$(NAME):	$(OBJ)
			@make -C $(LIBFT)
			@make -C $(MLX42)
			@$(CC) -I./$(INCLUDE) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft lib/MLX42/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm -o $(NAME)
			@echo "$(GREEN)$(NAME) compiled!$(DEF_COLOR)"

$(NAME_B):	$(OBJ_B)
			@make -C $(LIBFT)
			@make -C $(MLX42)
			@$(CC) -I./$(INCLUDE) $(CFLAGS) $(OBJ_B) -L$(LIBFT) -lft lib/MLX42/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm -o $(NAME_B)
			@echo "$(GREEN)$(NAME_B) compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER) | $(OBJF)
			@mkdir -p $(dir $@)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) -I./$(INCLUDE) $(CFLAGS) -c $< -o $@

$(OBJ_DIR_B)%.o: $(SRC_DIR_B)%.c $(HEADER_B) | $(OBJF_B)
			@mkdir -p $(dir $@)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) -I./$(INCLUDE) $(CFLAGS) -c $< -o $@ 

$(OBJF):
			@mkdir -p $(OBJ_DIR)

$(OBJF_B):
			@mkdir -p $(OBJ_DIR_B

clean:
			@rm -rf $(OBJ_DIR)
			@rm -rf $(OBJ_DIR_B)
			@make clean -C $(LIBFT)
			@make clean -C $(MLX42)
			@echo "$(BLUE)$(NAME) object files cleaned!$(DEF_COLOR)"

fclean:		
			@rm -rf $(OBJ_DIR)
			@rm -rf $(OBJ_DIR_B)
			@rm -f $(NAME)
			@rm -f $(NAME_B)
			@rm -rf $(NAME).dSYM
			@make fclean -C $(LIBFT)
			@make fclean -C $(MLX42)
			@echo "$(BLUE)$(NAME) executable cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(MAGENTA)$(NAME) recompiled!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(SRC_B) $(INCLUDE) $(LIBFT)


.PHONY: all clean fclean re norm