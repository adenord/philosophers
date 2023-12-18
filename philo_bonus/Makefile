# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: adenord <adenord@student.42mulhouse.fr>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/05 11:13:26 by adenord           #+#    #+#              #
#    Updated: 2023/12/18 19:05:43 by adenord          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB := philo_bonus.a
SRCS := srcs_bonus/philosophers.c srcs_bonus/custom_sleep.c \
srcs_bonus/check_format.c srcs_bonus/clean_mess.c srcs_bonus/data_init.c \
srcs_bonus/ft_atol.c srcs_bonus/access.c srcs_bonus/hungries.c \
srcs_bonus/time.c srcs_bonus/write.c srcs_bonus/routines.c \
srcs_bonus/safe_semaphore.c srcs_bonus/safe_thread.c
OBJS := $(SRCS:.c=.o)
CC := cc
CFLAGS := -Wall -Wextra -Werror -O3 -I includes_bonus/ 
NAME := philo_bonus

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
