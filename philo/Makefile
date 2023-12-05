# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 11:13:26 by adenord           #+#    #+#              #
#    Updated: 2023/12/05 16:36:36 by adenord          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS := srcs/philosophers.c srcs/custom_sleep.c srcs/parser.c srcs/clean_mess.c \
srcs/data_init.c srcs/ft_atol.c
CC := cc
CFLAGS := -Wall -Wextra -Werror -I includes/ -lpthread
NAME := philo

all : $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) $(SRCS) -o $(NAME)

clean :

fclean : clean
	$(RM) $(NAME)

re : fclean all
