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

SRCS = 	./src/1_check_map.c \
		./src/1_check_map2.c \
		./src/2_ft_leer_mapa.c \
		./src/3_ft_mostrar_mapa.c \
		./src/4_ft_movim_jugador.c \
		./src/ft_error_solong.c \
		./src/ft_free_solong.c \
		./src/so_long.c \
		
OBJS = $(SRCS:.c=.o)

#Compilacion#
LIBRERIA = libft/libft.a ./MLX42/libmlx42.a -lglfw -L /Users/${USER}/.brew/opt/glfw/lib/

LIBRERIA_LINUX = libft/libft.a /MLX42_linux/linux_make/libmlx42.a -Iinclude -ldl -lglfw -pthread -lm -o $(NAME)

AR = ar -rcs

CC = gcc

CFLAGS = -Wall -Werror -Wextra -g

RM = rm -f

#Reglas#
all: libft mlx compilar

%.o: %.c
		@echo "$(VERDE)COMPILANDO$(DEF_COLOR)"
		@$(CC) $(CFLAGS) -c $< -o $@

norminette:
	@echo "\n$(VERDE) ****** NORMINETTE DE 42 ******$(DEF_COLOR)\n"
	@norminette ./include/
	@norminette ./libft/
	@norminette ./src/


libft:
	@echo "\n$(VERDE) ***** COMPILANDO LIBRERIA DE FUNCIONES *****$(DEF_COLOR)\n"
	@make -C libft
	@echo "$(VERDE)Librería de funciones compilada$(DEF_COLOR)\n"

	
mlx:
	@echo "\n$(VERDE) ***** COMPILANDO LIBRERIA GRÁFICA *****$(DEF_COLOR)\n"
	@make -C ./MLX42
	@echo "$(VERDE)Librería gráfica compilada$(DEF_COLOR)\n"


compilar: $(NAME)

#Para MacOs
$(NAME): $(OBJS)
	@echo "\n$(VERDE)****** COMPILANDO PROGRAMA SO_LONG *****$(DEF_COLOR)\n"
	$(CC) $(CFLAGS) $(OBJS) $(LIBRERIA) -o $(NAME)
	@echo "\n$(VERDE)So_long compilado con éxito$(DEF_COLOR)"

#Para Linux
#$(NAME): $(OBJS)
#	@echo "\n$(VERDE)****** COMPILANDO PROGRAMA SO_LONG PARA LINUX *****$(DEF_COLOR)\n"
#	$(CC) $(CFLAGS) $(OBJS) $(LIBRERIA_LINUX) -o $(NAME)
#	@echo "\n$(VERDE)So_long para linux compilado con éxito$(DEF_COLOR)"

clean:
	@echo "\n$(VERDE)****** ELIMINANDO FICHEROS OBJETO******$(DEF_COLOR)\n"
	@make clean -C libft
	@make clean -C ./MLX42
	$(RM) $(OBJS)
	@echo "$(VERDE)Eliminación de ficheros objeto terminada con éxito$(DEF_COLOR)\n"

fclean: clean
	@echo "\n$(VERDE)****** ELIMINANDO FICHEROS EJECUTABLES******$(DEF_COLOR)\n"
	make fclean -C libft
	make fclean -C ./MLX42
	$(RM) $(NAME) $(OBJS)
	@echo "$(VERDE)Eliminación de ficheros ejecutables terminada con éxito$(DEF_COLOR)\n"

re: fclean all

.PHONY: norminette libft mlx compilar clean fclean re

