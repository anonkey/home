# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/08 22:38:59 by tseguier          #+#    #+#              #
#    Updated: 2014/01/12 01:11:19 by tseguier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
CFLAGS = -g -Wall -Wextra -Werror
LIBDIR = ./libft
INCDIR = ./inc
LIBF = -ltermcap -lft
NAME = ft_select
SRC = main.c \
	  ft_error.c \
	  ft_sighandler.c \
	  ft_execsuspend.c \
	  ft_term.c \
	  ft_termgraph.c \
	  ft_termopt.c \
	  ft_termcur.c \
	  ft_key.c \
	  ft_processkey.c \
	  ft_selelem.c \
	  ft_sellist.c \
	  ft_sellistmove.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): lib $(OBJ)
	$(CC) -I$(INCDIR) -L$(LIBDIR) $(LIBF) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.c
	$(CC) -I$(INCDIR) -o $@ -c $< $(CFLAGS)

lib:
	make -C $(LIBDIR)

relib:
	make -C $(LIBDIR) re

clean:
	make -C $(LIBDIR) clean
	rm -rf $(OBJ)

fclean: clean
	make -C $(LIBDIR) fclean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean fclean all re

