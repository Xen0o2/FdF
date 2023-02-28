# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alecoutr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/27 13:44:41 by alecoutr          #+#    #+#              #
#    Updated: 2023/02/28 11:45:01 by alecoutr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf

SRCS =	main.c \
		functions/utils/ft_atoi.c \
		functions/utils/ft_split.c \
		functions/utils/ft_strlen.c \
		functions/get_next_line/get_next_line.c \
		functions/get_next_line/get_next_line_utils.c \
		functions/ft_printf/ft_printf.c \
		functions/ft_printf/ft_putchar_fd.c \
		functions/ft_printf/ft_putnbr_fd.c \
		functions/ft_printf/ft_putstr_fd.c \
		functions/ft_printf/ft_putunbr_fd.c \
		functions/ft_printf/ft_toupper.c
		
GCC = gcc -Wall -Wextra -Werror

$(NAME):
	# $(GCC) $(SRCS) -o $(NAME) libmlx42.a -I include -lglfw -L "/Users/mdoumi/.brew/opt/glfw/lib/"
	$(GCC) $(SRCS) -o $(NAME) libmlx42.a -I include -lglfw -L "/opt/homebrew/Cellar/glfw/3.3.8/lib/"

all: $(NAME)

clean:
	rm -rf ${OBJS}

fclean:	clean
	rm -rf $(NAME)

re:	fclean all
