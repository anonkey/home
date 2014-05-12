# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tseguier <tseguier@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/11/26 00:03:59 by tseguier          #+#    #+#              #
#    Updated: 2014/01/10 02:53:01 by tseguier         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
AR = ar
CFLAGS = -Wall -Wextra -Werror
LDFLAGS = rc
NAME = libft.a
SRC = ft_memset.c \
	ft_strcmp.c \
	ft_bzero.c \
	ft_memcpy.c \
	ft_memccpy.c \
	ft_memmove.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_strlen.c \
	ft_strdup.c \
	ft_strcpy.c \
	ft_strncpy.c \
	ft_strchr.c \
	ft_strrchr.c \
	ft_strcat.c \
	ft_strncat.c \
	ft_strlcat.c \
	ft_strstr.c \
	ft_strncmp.c \
	ft_strnstr.c \
	ft_atoi.c \
	ft_isalpha.c \
	ft_isdigit.c \
	ft_isalnum.c \
	ft_isascii.c \
	ft_isprint.c \
	ft_toupper.c \
	ft_tolower.c \
	ft_memalloc.c \
	ft_memdel.c \
	ft_strnew.c \
	ft_strdel.c \
	ft_strclr.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strequ.c \
	ft_strnequ.c \
	ft_strsub.c \
	ft_strjoin.c \
	ft_strtrim.c \
	ft_strsplit.c \
	ft_itoa.c \
	ft_putchar.c \
	ft_putstr.c \
	ft_putendl.c \
	ft_putnbr.c \
	ft_putchar_fd.c \
	ft_putstr_fd.c \
	ft_putendl_fd.c \
	ft_putnbr_fd.c \
	ft_lstnew.c \
	ft_lstdelone.c \
	ft_lstdel.c \
	ft_lstadd.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_ldcddel.c \
	ft_ldcdpop_back.c \
	ft_ldcdpush_front.c \
	ft_ldcd_celldel.c \
	ft_ldcditer.c \
	ft_ldcdpop_front.c \
	ft_ldcdpop.c \
	ft_ldcdsize.c \
	ft_ldcd_cellnew.c \
	ft_ldcdnew.c \
	ft_ldcdpush_back.c \
	ft_ldcdat.c \
	ft_ldcddel_head.c \
	ft_ldcddel_tail.c \
	ft_strcsub.c \
	ft_strsepjoin.c \
	ft_strtabcpy.c \
	ft_strtabrealloc.c \
	ft_strtabdel.c \
	get_next_line.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(LDFLAGS) $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean fclean all re $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
