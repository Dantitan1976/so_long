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
	mlx_image_t		*exit;
	char			*linea;
	char			**mapa;
	char			**mapa_copia;
	char			*mapa_nombre;
	int				movimientos;
	int				vacio;
	int				muro;
	int				consumibles;
	int				jugador;
	int				salida;
	int				errores;
	int				columnas_mapa;
	int				filas_mapa;
	int				ancho;
	int				alto;
	int				linea_control;
}	t_juego;

/*1.check_map.c*/
void	check_ext_file(char *mapa, t_juego *d);
void	check_mapa(t_juego *d);
void	check_elementos_linea(t_juego *d);
void	ft_flood_fill(t_juego *d, int pos_ejex, int pos_ejey);
void	ft_camino(t_juego *d);
/*2_ft_leer_mapa.c*/
void	ft_leer_mapa(char *ruta_mapa, t_juego *d);
/*3.ft_mostrar_mapa.c*/
void	ft_imagenes(t_juego d);
void	ft_generar_mapa(t_juego *d);
void	ft_mostrar_mapa(t_juego *d);

void	ft_error_solong2(t_juego *d, int error);
void	ft_error_solong(t_juego *d, int error);
int		ft_free(t_juego *d);
void	ft_imagenes(t_juego *d);
/*so_long.c*/
t_juego	*inicializar_struct(t_juego *d, char *argv);
int		main(int argc, char **argv);

#endif