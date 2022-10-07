RED=$'\x1b[31m
GREEN=$'\x1b[32m
PURPLE=$'\x1b[35m

NAME = cub3d

INCLUDE = include
HEADER = $(INCLUDE)/cub.h

CC = cc
CFLAGS = -Wall -Wextra -Werror -g
CFLAGS += -Imlx

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
MLX_DIR = mlx
MLX_LIB = $(MLX_DIR)/libmlx.a
GNL_DIR = gnl
GNL_LIB = $(GNL_DIR)/nextline.a
OFILES = ofiles
LIBFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

DRAW = $(addprefix drawing/, drawing_map draw_game get_dest get_horizontal get_vertical)
MOVES = $(addprefix moves/, keys get_pos collegion)
PARSING = $(addprefix parsing/, error_handler gen_map_table read_cub check_path)
UTILS = $(addprefix utils/, count ft_strcmp is_empty rays pixels rgb init_data minimap)
FILES =  $(addprefix src/, main $(PARSING) $(UTILS) $(DRAW) $(MOVES))

OBJ = $(addprefix $(OFILES)/, $(FILES:=.o))

all : $(NAME)


$(NAME): $(MLX_LIB) $(OBJ) $(LIBFT_LIB) $(GNL_LIB) $(HEADER)
	@$(CC) $(CFLAGS) $(LIBFT_LIB) $(GNL_LIB) $(OBJ) $(LIBFLAGS) $(MLX_LIB) -o $(NAME)

$(OFILES)/src/%.o: src/%.c $(HEADER)
	@mkdir -p $(@D)
	@$(CC) -I$(INCLUDE) $(CFLAGS) -o $@ -c $<
	@echo "$(GREEN)" "compiling $<"

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR)

$(GNL_LIB):
	@$(MAKE) -C $(GNL_DIR)

$(MLX_LIB):
	-@$(MAKE) -C $(MLX_DIR) 2> /dev/null

clean:
	@rm -rf $(OBJ)
	@rm -rf ofiles
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(GNL_DIR)
	@$(MAKE) clean -C $(MLX_DIR)
	@echo "$(RED)" "cleaning ..."

fclean : clean
	@rm -rf $(NAME) *.gch
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) fclean -C $(GNL_DIR)
	@$(MAKE) clean -C $(MLX_DIR)
	@echo "$(RED)" "full cleaning..."

re : fclean all
	@echo "$(PURPLE)" "remaking"

.PHONY: all clean fclean re bonus

