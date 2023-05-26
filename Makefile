# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dramirez <dramirez@student.42malaga.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/20 21:21:12 by dramirez          #+#    #+#              #
#    Updated: 2023/05/20 21:21:12 by dramirez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

DEF_COLOR	= \033[0;39m
VERDE		= \033[1;92m
ROJO		= \033[0;91m

SRCS = 	./src/so_long.c \
		./src/ft_free.c \
		./src/ft_error_solong.c \

OBJS = $(SRCS:.c=.o)

#Compilacion#
LIBRERIA = libft/libft.a

AR = ar -rcs

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

RM = rm -f

#Reglas#
.c.o:
		@echo "$(VERDE)COMPILANDO$(DEF_COLOR)"
		@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

norminette:
	@echo "\n$(VERDE) ****** NORMINETTE DE 42 ******$(DEF_COLOR)\n"
	@norminette .

libft:
	@echo "\n$(VERDE) ***** COMPILANDO LIBRERIA DE FUNCIONES *****$(DEF_COLOR)\n"
	@make -C libft
	@echo "$(VERDE)Librería de funciones compilada$(DEF_COLOR)\n"

mlx:
	@echo "\n$(VERDE) ***** COMPILANDO LIBRERIA GRÁFICA *****$(DEF_COLOR)\n"
	@make -C ./minilibx-linux
	@echo "$(VERDE)Librería gráfica compilada$(DEF_COLOR)\n"


compilar: $(NAME)

$(NAME): $(OBJS)
	@echo "\n$(VERDE)****** COMPILANDO PROGRAMA SO_LONG *****$(DEF_COLOR)\n"
	$(CC) $(CFLAGS) $(OBJS) $(LIBRERIA) -o $(NAME)
	@echo "\n$(VERDE)Programa servidor compilado con éxito$(DEF_COLOR)"

all: norminette libft mlx compilar

clean:
	@echo "\n$(VERDE)****** ELIMINANDO FICHEROS OBJETO******$(DEF_COLOR)\n"
	make clean -C libft
	make clean -C ./minilibx-linux
	$(RM) $(OBJS)
	@echo "$(VERDE)Eliminación de ficheros objeto terminada con éxito$(DEF_COLOR)\n"

fclean: clean
	@echo "\n$(VERDE)****** ELIMINANDO FICHEROS EJECUTABLES******$(DEF_COLOR)\n"
	make fclean -C libft
	make fclean -C ./minilibx-linux
	$(RM) $(NAME) $(OBJS)
	@echo "$(VERDE)Eliminación de ficheros ejecutables terminada con éxito$(DEF_COLOR)\n"

re: fclean all

.PHONY: norminette libft mlx compilar clean fclean re

