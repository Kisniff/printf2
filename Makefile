# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sklepper <sklepper@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/18 10:23:16 by sklepper          #+#    #+#              #
#    Updated: 2018/09/27 15:14:52 by sklepper         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = libftprintf.a 

NAMEN = ft_printf

SRC = main.c \
      to_base.c \
      string.c \
      length.c \
      flags.c \
      path.c \
      precision.c \
      pick_f_u_int.c \
      pick_f_base.c \
      digits_precision.c \
      digits_precision_spec.c \
      pick_f_c.c \
      ft_itoa.c \
      ft_memset.c \
      ft_strchr.c \
	  write_str.c \
      ft_strcmp.c \
      ft_strlen.c \
      ft_strnew.c \
      ft_strdel.c \
      ft_atoi.c \
      ft_strdup.c \
      pick_f_w.c \
      pick_f_s.c \
      pick_f_bigs.c \
	  toolbox.c \
      pick_f_percent.c \
      pick_f_p.c \
      pick_f_d.c \
      exceptions_func.c \
      ft_bzero.c

OBJ = $(SRC:.c=.o) 

HEADER = libft.h

LFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ) 

yo:		$(OBJ)
	gcc $(FLAGS) -fsanitize=address -g -o $(NAMEN) $(OBJ) 
	rm -f $(OBJ)

%.o: %.c
	@gcc -c $(FLAGS) $<

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f $(NAMEN)

re: fclean all
