# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 09:23:15 by cabo-ram          #+#    #+#              #
#    Updated: 2024/12/16 12:49:08 by cabo-ram         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRC = main.c normalize.c op_rot_rev.c op_swap_push.c sort.c \

OBJS = $(SRC:.c=.o)
HEADER = includes
LIBFT = libft

CC = cc

CFLAGS = -Wall -Wextra -Werror -I$(HEADER) -g

RM = rm -rf

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a .
	@mv libft.a $(NAME)
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	@make -C $(LIBFT) clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFT) fclean

re: fclean all

.PHONY: all clean fclean re