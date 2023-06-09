/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mostrar_mapa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramirez <dramirez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 20:56:26 by dramirez          #+#    #+#             */
/*   Updated: 2023/05/27 20:56:26 by dramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_imagenes(t_juego d)
{
	int	w_im;
	int	h_im;

	w_im = 50;
	h_im = 50;
	d->ancho = (d.columnas_mapa - 1) * w_im;
	d->alto = (d.filas_mapa + 1) * h_im;
	d->palm = mlx_image_to_window(d->mlx, "img/palm.xpm", &w_im, &h_im);
	d->arena = mlx_image_to_window(d->mlx, "img/arena.xpm", &w_im, &h_im);
	d->cofre = mlx_image_to_window(d->mlx, "img/cofre.xpm", &w_im, &h_im);
	d->pirata = mlx_image_to_window(d->mlx, "img/pirata_i.xmp", &w_im, &h_im);
	d->pirizq = mlx_image_to_window(d->mlx, "img/pirizq.xmp", &w_im, &h_im);
}

/*Generamos el mapa colocando cada objeto en el mapa usando la
función mlx_image_to_window para mostrarlo en pantalla. Primero colocamos
el fondo para que, cuando coloquemos la imagen, aparezca ya sobre el fondo.*/
void	ft_generar_mapa(t_juego *d)
{
	int		columnas;
	int		filas;

	columnas = 0;
	filas = 0;
	while (d->mapa[filas][columnas])
	{
		mlx_image_to_window (d->mlx, d->arena, x * 50, y * 50);
		else if (imagen == 'P')
			mlx_image_to_window (d->mlx, d->pirata, x * 50, y * 50);
		else if (imagen == 'C')
			mlx_image_to_window (d->mlx, d->cofre, x * 50, y * 50);
		else if (imagen == 'E')
			mlx_image_to_window (d->mlx, d->exit, x * 50, y * 50);
		else if (imagen == '1')
			mlx_image_to_window (d->mlx, d->palm, x * 50, y * 50);
		columnas++;
	}
	columnas = 0;
	filas++;
}

void	ft_mostrar_mapa(t_juego *d)
{
	int	posicion;

	posicion = 0;
	ft_printf("MAPA\n");
	while (d->mapa[posicion])
	{
		ft_printf("%s\n", d->mapa[posicion])
		posicion++;
	}
	posicion = 0;
	ft_printf("MAPA COPIA\n");
	while (d->mapa_copia[posicion])
	{
		ft_printf("%s\n", d->mapa_copia[posicion])
		posicion++;
	}
}
