RED=$'\x1b[31m
GREEN=$'\x1b[32m
PURPLE=$'\x1b[35m

CFILES = ft_atoi.c ft_bzero.c ft_calloc.c ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_memcpy.c ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
	ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_lstnew.c \
	ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c \

OFILES = $(CFILES:%.c=%.o)

CC = gcc
W = -c -Wall -Werror -Wextra -g
INC = libft.h
NAME = libft.a

all : $(NAME)

$(NAME) : $(OFILES) $(INC)
	@$(CC) $(W) $(CFILES)
	@ar -rc $(NAME) $(OFILES)
	@echo "$(GREEN)" "compiling libft"

%.o : %.c $(INC)
	@$(CC) $(CFILES) -c $<
	
clean:
	@rm -f $(OFILES)

fclean : clean
	@rm -f $(NAME)

re : fclean all

