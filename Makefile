# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bamssaye <bamssaye@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/25 03:33:03 by bamssaye          #+#    #+#              #
#    Updated: 2024/03/25 05:48:20 by bamssaye         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra -Werror 
RM = rm -rf
AR = ar -rc
OBJDIR = obj
#-----------
FUN = fractol_utils.c fractol.c libft_utils.c\
	ft_parsing.c ft_init.c calcu_fractol.c\
	ft_hooks.c

#----------
#OBG = $(FUN:%.c=%.o)
#----------
OBG =  $(addprefix $(OBJDIR)/,  $(FUN:.c=.o))

$(OBJDIR)/%.o: %.c
	@mkdir -p $(OBJDIR)
	$(CC)  -I/usr/include -Imlx_linux -O3 -c $< -o $@

all : $(NAME)

$(NAME): $(OBG)
	$(CC) $(OBG) -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz -o $(NAME)

bonus : all
	
clean:
	$(RM) $(OBJDIR)

fclean : clean
	$(RM) $(NAME)
	
re: clean all

.SECONDARY : $(OBG)