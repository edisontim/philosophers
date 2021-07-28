# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tedison <tedison@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/19 11:45:19 by tedison           #+#    #+#              #
#    Updated: 2021/07/26 19:20:48 by tedison          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= srcs/philo.c  srcs/utils.c srcs/forks_dead.c srcs/main_action.c\
				srcs/ts_put_action.c srcs/time_monitor.c
OBJS		= $(SRCS:.c=.o)
COMMON		= srcs/ft_atoi.c  srcs/ft_strjoin.c
COMMON_OBJS = $(COMMON:.c=.o)
CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror
NAME		= philo

all:			$(NAME)

$(NAME):		$(OBJS) $(COMMON_OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(COMMON_OBJS) 


clean:
				$(RM) $(OBJS) $(COMMON_OBJS)

fclean:			clean
				$(RM) $(NAME)

re:				fclean $(NAME)


.PHONY:			all clean fclean re
