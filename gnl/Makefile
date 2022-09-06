RED=$'\x1b[31m
GREEN=$'\x1b[32m
PURPLE=$'\x1b[35m

CFILES = get_next_line.c  get_next_line_utils.c 
OFILES = $(CFILES:%.c=%.o)

CC = gcc
W = -c -Wall -Werror -Wextra
HEADER = get_next_line.h
NAME = nextline.a

all : $(NAME)

$(NAME) : $(OFILES)
	@$(CC) $(W) $(CFILES)
	@ar -rc $(NAME) $(OFILES)
	@echo "$(GREEN)" "compiling get_next_line"


%.o : %.c $(HEADER)
	@$(CC) $(FLAGS) -c $^ 
clean:
	@rm -rf $(OFILES) get_next_line.h.gch
fclean : clean
	@rm -rf $(NAME)
re : fclean all