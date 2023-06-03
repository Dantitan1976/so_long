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

void	xy(char imagen, int posicion, t_juego *d)
{
	int		x;
	int		y;

	y = (posicion / d->anchura_mapa) * 50;
	x = (posicion % d->anchura_mapa) * 50;
	if (d->errores == 0)
	{
		if (imagen == 'P')
			mlx_image_to_window (d->mlx, d->pirata, x * 50, y * 50);
		if (imagen == 'C')
			mlx_image_to_window (d->mlx, d->cofre, x * 50, y * 50);
		if (imagen == 'E')
			mlx_image_to_window (d->mlx, d->cofre, x * 50, y * 50);
		if (imagen == '1')
			mlx_image_to_window (d->mlx, d->palm, x * 50, y * 50);
		if (imagen == '0')
			mlx_image_to_window (d->mlx, d->arena, x * 50, y * 50);
		{
			/* code */
		}
		
	}
	
}

void	ft_mostrar_mapa(t_juego *d)
{
	int	posicion;

	posicion = 0;
	while (d->linea[posicion])
	{
		if (d->linea[posicion] == '\n')
			posicion++;
		if (d->linea[posicion] != 'C' && d->linea[posicion] != 'P'
			&& d->linea[posicion] != 'E' && d->linea[posicion] != '1'
			&& d->linea[posicion] != '0')
			exit (0);
		{
			
		}
		
		}
		
	}
}