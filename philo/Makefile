# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 11:13:26 by adenord           #+#    #+#              #
#    Updated: 2023/12/12 17:02:03 by adenord          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB := philo.a
SRCS := srcs/philosophers.c srcs/custom_sleep.c srcs/check_format.c \
srcs/clean_mess.c srcs/data_init.c srcs/ft_atol.c srcs/access.c \
srcs/hungries.c srcs/time.c srcs/write.c srcs/utils.c \
srcs/routines.c
OBJS := $(SRCS:.c=.o)
CC := cc
CFLAGS := -Wall -Wextra -Werror -O3 -I includes/ 
NAME := philo

all : $(NAME)

$(LIB) : $(OBJS)
	$(AR) rcs $@ $?

$(NAME) : $(LIB)
	$(CC) $(CFLAGS) -lpthread $(LIB) -o $@

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME) $(LIB)

re : fclean all

.PHONY : all clean fclean re
