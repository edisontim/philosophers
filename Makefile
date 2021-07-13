# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tedison <tedison@student.s19.be>           +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/19 11:45:19 by tedison           #+#    #+#              #
#    Updated: 2021/06/30 13:10:48 by tedison          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS		= srcs/philo.c  srcs/utils.c srcs/forks_dead.c srcs/main_action.c\
				srcs/ts_put_action.c srcs/time_monitor.c
OBJS		= $(SRCS:.c=.o)
COMMON		= srcs/ft_atoi.c  srcs/ft_strjoin.c
COMMON_OBJS = $(COMMON:.c=.o)
BONUS		= srcs/philo_bonus.c srcs/utils_bonus.c srcs/ft_convert_base.c srcs/server.c\
				srcs/nbr_base_put_action_b.c srcs/main_action_b.c srcs/client.c \
				srcs/kill_put_nbr.c
BONUS_OBJS	= $(BONUS:.c=.o)
CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra
NAME		= philo
NAME_BONUS	= philo_bonus

all:			$(NAME)

$(NAME):		$(OBJS) $(COMMON_OBJS)
				$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(COMMON_OBJS) 

bonus:			$(BONUS_OBJS) $(COMMON_OBJS)
				$(CC) $(CFLAGS) -o $(NAME_BONUS) $(BONUS_OBJS) $(COMMON_OBJS)
clean:
				$(RM) $(OBJS) $(BONUS_OBJS) $(COMMON_OBJS)

fclean:			clean
				$(RM) $(NAME) $(NAME_BONUS)

re:				fclean $(NAME)


.PHONY:			all clean fclean re bonus
