# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cabo-ram <cabo-ram@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/12/02 09:23:15 by cabo-ram          #+#    #+#              #
#    Updated: 2024/12/09 17:00:06 by cabo-ram         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap.a

SRC = main.c normalize.c \

OBJS = $(SRC:.c=.o)
HEADER = includes
LIBFT = libft
FT_PRINTF = ft_printf
GET_NEXT_LINE = get_next_line

CC = cc

CFLAGS = -Wall -Wextra -Werror -I$(HEADER) -g

RM = rm -rf

all: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	@make -C $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE)
	@cp libft/libft.a . ******
	@mv libft.a $(NAME) ******
	ar rcs $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)
	@make -C $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE) clean

fclean: clean
	$(RM) $(NAME)
	@make -C $(LIBFT) $(FT_PRINTF) $(GET_NEXT_LINE) fclean

re: fclean all

.PHONY all clean fclean re