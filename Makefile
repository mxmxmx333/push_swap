# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/25 17:14:05 by mbonengl          #+#    #+#              #
#    Updated: 2024/06/22 14:07:34 by mbonengl         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV >VARIABLES< VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV #
NAME 	:=	push_swap

CFLAGS 	:= 	-Wall -Werror -Wextra

CC 		:= 	cc

RM		:=	rm -f

SRCS 	:= main.c memory_free_meta.c \
		input_cleaner.c	input_convertcheckback.c input_fill_stacks.c \
		input_formatcheck.c input_check.c \
		s_ops_rotates.c s_ops_swaps.c s_ops_pushes.c s_ops_reverse_rotates.c \
		sort_push_swap.c sort_costs_a.c sort_push_to_a.c sort_push_to_b.c \
		sort_push_to_b_utils.c sort_targeting_a.c sort_targeting_b.c \
		sort_stacks_utils.c \
		basic_utils.c ft_bzero.c ft_calloc.c ft_itoa.c ft_split.c \
		ft_strdup.c ft_strlcpy.c ft_substr.c

OBJS	:=	$(SRCS:.c=.o)

norm:= norminette -R CheckForbiddenSourceHeader

# ɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅ #

# VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV >RULES< VVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVVV #
all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

norm: $(SRCS)
	$(norm) $(SRCS) push_swap.h
	
.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS) a.out

fclean:	clean
	$(RM) $(NAME)

re: fclean all

.PHONY:	all clean fclean re norm
# ɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅɅ #
