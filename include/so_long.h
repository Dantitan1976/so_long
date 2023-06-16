/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramirez <dramirez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:05:15 by dramirez          #+#    #+#             */
/*   Updated: 2023/05/20 19:05:15 by dramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>

typedef struct s_juego
{
	mlx_t			*mlx;
	mlx_image_t		*palm;
	mlx_image_t		*arena;
	mlx_image_t		*cofre;
	mlx_image_t		*pirata;
	mlx_image_t		*barco;
	char			*linea;
	char			**mapa;
	char			**mapa_copia;
	char			*mapa_nombre;
	int				movimientos;
	//int				vacio;
	//int				muro;
	int				consumibles;
	int				consumibles_total;
	int				jugador;
	int				jugador_posx;
	int				jugador_posx_act;
	int				jugador_posy;
	int				jugador_posy_act;
	int				salida;
	int				columnas_mapa;
	int				filas_mapa;
}	t_juego;

typedef struct s_texturas
{
	mlx_texture_t	*palm_text;
	mlx_texture_t	*arena_text;
	mlx_texture_t	*cofre_text;
	mlx_texture_t	*pirata_text;
	mlx_texture_t	*barco_text;
}	t_texturas;


/*1_check_map.c*/
void	check_ext_file(char *mapa, t_juego *d);
void	check_mapa(t_juego *d);
void	check_elementos_mapa(t_juego *d);
void	ft_flood_fill(t_juego *d, int pos_ejex, int pos_ejey);
void	ft_camino(t_juego *d);
/*2_ft_leer_mapa.c*/
void	ft_leer_mapa(char *ruta_mapa, t_juego *d);
void	ft_print_mapa(char **matriz);
/*3_ft_mostrar_mapa.c*/
void	ft_mostrar_mapa(t_juego *d);
void	ft_crear_mapa(t_juego *d);
void	ft_generar_mapa(t_juego *d);
void	ft_generar_jugador(t_juego *d);
/*4_ft_movim_jugador.c*/
void	ft_movim_jugador(mlx_key_data_t tecla, void *parametro);
void	ft_arriba(t_juego *d);
void	ft_abajo(t_juego *d);
void	ft_izquierda(t_juego *d);
void	ft_derecha(t_juego *d);
/*ft_error_solong.c*/
void	ft_error_solong2(t_juego *d, int error);
void	ft_error_solong(t_juego *d, int error);
/*ft_free.c*/
void	ft_free_solong(t_juego *d);
/*so_long.c*/
t_juego	*inicializar_struct(t_juego *d, char *argv);
void	chequeos(t_juego *d);
int		ft_victoria(t_juego *d, int columnas, int filas);
void	ft_tesoro_capturado(t_juego *d);
int		main(int argc, char **argv);

#endif