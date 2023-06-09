/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imagenes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramirez <dramirez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 08:24:35 by dramirez          #+#    #+#             */
/*   Updated: 2023/05/28 08:24:35 by dramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_imagenes(t_juego *d)
{
	int	w_im;
	int	h_im;

	w_im = 50;
	h_im = 50;
	d->ancho = (d->anchura_mapa - 1) * w_im;
	d->alto = (ft_strlen(d->linea) / d->anchura_mapa + 1) * h_im;
	d->palm = mlx_image_to_window(d->mlx, "img/palm.xpm", &w_im, &h_im);
	d->arena = mlx_image_to_window(d->mlx, "img/arena.xpm", &w_im, &h_im);
	d->cofre = mlx_image_to_window(d->mlx, "img/cofre.xpm", &w_im, &h_im);
	d->pirata = mlx_image_to_window(d->mlx, "img/pirata_i.xmp", &w_im, &h_im);
	d->pirizq = mlx_image_to_window(d->mlx, "img/pirizq.xmp", &w_im, &h_im);
}
