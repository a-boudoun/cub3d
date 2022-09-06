RED=$'\x1b[31m
GREEN=$'\x1b[32m
PURPLE=$'\x1b[35m

NAME = cub3d

INCLUDE = include
HEADER = $(INCLUDE)/cub.h

CC = cc
FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
GNL_DIR = gnl
GNL_LIB = $(GNL_DIR)/nextline.a
OFILES = ofiles


FILES =  $(addprefix src/, main)

OBJ = $(addprefix $(OFILES)/, $(FILES:=.o))

all : $(NAME)


$(NAME): $(OBJ) $(LIBFT_LIB) $(GNL_LIB) $(HEADER)
	@$(CC) $(FLAGS) $(LIBFT_LIB) $(GNL_LIB) $(OBJ) -o $(NAME)

$(OFILES)/src/%.o: src/%.c $(HEADER)
	@mkdir -p $(@D)
	@$(CC) -I$(INCLUDE) $(FLAGS) -o $@ -c $<
	@echo "$(GREEN)" "compiling $<"

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR)

$(GNL_LIB):
	@$(MAKE) -C $(GNL_DIR)
	
clean:
	@rm -rf $(OBJ)
	@rm -rf ofiles
	@$(MAKE) clean -C $(LIBFT_DIR)
	@$(MAKE) clean -C $(GNL_DIR)
	@echo "$(RED)" "cleaning ..."

fclean : clean
	@rm -rf $(NAME) *.gch
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@$(MAKE) fclean -C $(GNL_DIR)
	@echo "$(RED)" "full cleaning..."

re : fclean all
	@echo "$(PURPLE)" "remaking"

.PHONY: all clean fclean re bonus

