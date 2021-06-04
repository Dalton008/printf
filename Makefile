NAME = libftprintf.a

SRCS =	ft_atoi.c ft_isdigit.c ft_parse.c ft_printf.c ft_process_d.c\
	ft_process_hex.c ft_process_p.c ft_process.c ft_putchar.c\
	ft_putnbr.c ft_putstr.c ft_strlen.c ft_utils.c ft_strchr.c

OBJS = $(SRCS:.c=.o)

CC = gcc 

CFLAGS = -Wall -Wextra -Werror 

INCLUDE = ./includes/

all : $(NAME)

%.o: %.c $(INCLUDE)
	$(CC) $(CFLAGS) -I $(INCLUDE) -c $< -o $@  

$(NAME) : $(OBJS) $(INCLUDE)
	ar rcs $(NAME) $(OBJS)
	# $(CC) $(OBJS) -I $(INCLUDE) -o $(NAME)

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(NAME)

re : fclean all

bonus : $(NAME)

.PHONY: clean fclean re all