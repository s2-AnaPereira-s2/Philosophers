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
CFLAGS = -Wall -Werror -Wextra -I.
RM	= rm -f
HEADER = philo.h
SRC = ./src
CFILES = \
	$(SRC)/philo.c \
	$(SRC)/philo_utils.c \
	$(SRC)/main.c \
	$(SRC)/routines.c \
	$(SRC)/init.c \
	$(SRC)/clean.c \

OFILES = $(CFILES:%.c=%.o)

GREEN		= \033[0;32m
GREY		= \033[0;90m
RED			= \033[0;31m
RESET		= \033[0m

all: $(NAME)

$(NAME): $(OFILES) 
	@$(CC) $(CFLAGS) $(OFILES) -o $(NAME)
	@echo "$(GREEN)Executable created: $(NAME)$(RESET)"

%.o: %.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OFILES)
	@echo "$(RED)Cleaned object files.$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED)Fully cleaned everything.$(RESET)"

re: fclean all

.PHONY: all clean fclean re 