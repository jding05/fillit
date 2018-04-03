# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sding <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/03/31 09:40:46 by sding             #+#    #+#              #
#    Updated: 2018/03/31 09:41:02 by sding            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

MAKE = make -C
NAME = fillit
LIB = libft/
FLAGS = -Wall -Wextra -Werror
CC = gcc

#When compiling. you need to add your .a lib
CFILES = $(LIB)/libft.a \
		 input.c \
         tetrimino.c \
		 check.c \
		 coor_single_position.c \
		 coor_position.c \
		 fill_char.c\
		 solver.c \
		 table.c \
		 main.c \


#These options are here in case the lib needs to be recompiled.
#LIBM, LIBC, LIBF will run rules re, clean and fclean inside the libft folder
LIBM = $(MAKE) $(LIB) re
LIBC = $(MAKE) $(LIB) clean
LIBF = $(MAKE) $(LIB) fclean
OBJECTS = $(CFILES:.c=.o)

all: $(NAME)

$(NAME):
	@$(LIBM)
	@$(CC) $(FLAGS) -I. -o $(NAME) $(CFILES)

clean:
	@$(LIBC)
	@/bin/rm -f $(OBJECTS) fillit.o

fclean:
	@$(LIBF)
	@/bin/rm -f $(OBJECTS) $(NAME)

re: fclean all
