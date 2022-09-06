NAME = cube3d

INCLUDE = 
HEADER = $(INCLUDE)/

CC = cc
FLAGS = -Wall -Wextra -Werror

LIBFT_DIR = libft
LIBFT_LIB = $(LIBFT_DIR)/libft.a
OFILES = ofiles


FILES =  $(addprefix src/, )

OBJ = $(addprefix $(OFILES)/, $(FILES:=.o))

all : $(NAME)


$(NAME): $(OBJ) $(LIBFT_LIB) $(HEADER)
	@$(CC) $(FLAGS) $(LIBFT_LIB) $(OBJ) -o $(NAME)

$(OFILES)/src/%.o: src/%.c $(HEADER)
	@mkdir -p $(@D)
	@$(CC) -I$(INCLUDE) $(FLAGS) -o $@ -c $<
	@echo "$(GREEN)" "compiling $<"

$(LIBFT_LIB):
	@$(MAKE) -C $(LIBFT_DIR)
	
clean:
	@rm -rf $(OBJ)
	@rm -rf ofiles
	@$(MAKE) clean -C $(LIBFT_DIR)
	@echo "$(RED)" "cleaning ..."

fclean : clean
	@rm -rf $(NAME) *.gch
	@$(MAKE) fclean -C $(LIBFT_DIR)
	@echo "$(RED)" "full cleaning..."

re : fclean all
	@echo "$(PURPLE)" "remaking"

.PHONY: all clean fclean re bonus

