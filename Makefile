# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gajayme <gajayme@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/10 15:22:34 by gajayme           #+#    #+#              #
#    Updated: 2021/11/10 18:00:07 by gajayme          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADER = printf.h

SRC = 	printf.c \
		printf_utils.c\

O_FILES = $(patsubst %.c,%.o,$(SRC))
D_FILES = $(patsubst %.c,%.d,$(SRC))

COMPILER =	gcc -Wall -Wextra -Werror

AR = ar -rcs

RM = rm -rf

all : $(NAME)

$(NAME) : $(O_FILES)
	$(AR) $(NAME) $?

%.o : %.c
	$(COMPILER) -c $< -o $@ -MMD

include $(wildcard $(D_FILES))


clean :
	$(RM) $(O_FILES) $(D_FILES) a.out

fclean : clean
	$(RM) $(NAME)
	
re : fclean all

.PHONY : all, clean, fclean, re

