# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ana-pdos <ana-pdos@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/18 15:46:44 by ana-pdos          #+#    #+#              #
#    Updated: 2025/08/18 18:58:18 by ana-pdos         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
CC = cc
CFLAGS = -Wall -Werror -Wextra
CFILES = philo.c checks.c
OFILES = $(CFILES:.c=.o)

.PHONY: all clean fclean re 

all: $(NAME)

$(NAME): $(OFILES) 
	$(CC) $(CFLAGS) $(OFILES) -o $(NAME)

%.o: %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all