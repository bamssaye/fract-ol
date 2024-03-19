# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/16 07:29:23 by bamssaye          #+#    #+#              #
#    Updated: 2024/03/19 03:05:42 by bamssaye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -rf
AR = ar -rc
FLAG = -fsanitize=address
#-----------
FUN = fractol_utils.c fractol.c libft_utils.c

#----------
OBG = $(FUN:%.c=%.o)
#----------

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

all : $(NAME)

$(NAME): $(OBG)
	$(CC) $(OBG) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)
c:
	$(RM)  $(OBG)
f : 
	$(RM) $(NAME)
re: c all
	