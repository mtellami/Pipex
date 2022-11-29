NAME = pipex
CFLAGS = -Wall -Wextra -Werror -I includes/
SRCS = srcs/pipex.c \
	   libft/ft_split.c libft/ft_putstr_fd.c libft/ft_strdup.c libft/ft_strjoin.c \
	   libft/ft_strlen.c srcs/free_arr.c srcs/errors.c srcs/in_exec.c srcs/out_exec.c \
	   srcs/get_data.c libft/ft_strstr.c srcs/get_path.c \

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
		  cc $(CFLAGS) $(OBJS) -o $(NAME)

clean :
		  rm -fr $(OBJS)

fclean : clean
	 	  rm -fr $(NAME)

re : fclean all