#Variables

USERNAME = $(shell whoami)
NAME = cub3d
INCLUDE = include
HEADER = $(INCLUDE)/$(NAME).h
LIBFT = lib/libft
MLX42 = lib/MLX42
SRC_DIR = src/
OBJ_DIR = obj/
CC = clang
CFLAGS = -Wall -Werror -Wextra -g -fsanitize=address
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
			parse/check_map \
			parse/floodfill_map \
			game/game_loop \
			game/load_sprites \
			game/generic_hook \
			game/mouse_hook \
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

SRC = $(addprefix $(SRC_DIR), $(addsuffix .c, $(SRC_FILES)))
OBJ = $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SRC_FILES)))
OBJF = .cache_exists

###

all:		$(NAME)

$(NAME):	$(OBJ)
			@make -C $(LIBFT)
			@make -C $(MLX42)
			@$(CC) -I./$(INCLUDE) $(CFLAGS) $(OBJ) -L$(LIBFT) -lft lib/MLX42/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm -o $(NAME)
			@echo "$(GREEN)$(NAME) compiled!$(DEF_COLOR)"

$(OBJ_DIR)%.o: $(SRC_DIR)%.c $(HEADER) | $(OBJF)
			@mkdir -p $(dir $@)
			@echo "$(YELLOW)Compiling: $< $(DEF_COLOR)"
			@$(CC) -I./$(INCLUDE) $(CFLAGS) -c $< -o $@ 

$(OBJF):
			@mkdir -p $(OBJ_DIR)

clean:
			@rm -rf $(OBJ_DIR)
			@make clean -C $(LIBFT)
			@make clean -C $(MLX42)
			@echo "$(BLUE)$(NAME) object files cleaned!$(DEF_COLOR)"

fclean:		
			@rm -rf $(OBJ_DIR)
			@rm -f $(NAME)
			@rm -rf $(NAME).dSYM
			@make fclean -C $(LIBFT)
			@make fclean -C $(MLX42)
			@echo "$(BLUE)$(NAME) executable cleaned!$(DEF_COLOR)"

re:			fclean all
			@echo "$(MAGENTA)$(NAME) recompiled!$(DEF_COLOR)"

norm:
			@norminette $(SRC) $(INCLUDE) $(LIBFT)

run:		$(NAME)
			./$(NAME) maps/3.cub

.PHONY: all clean fclean re norm