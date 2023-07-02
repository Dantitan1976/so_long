/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1. check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramirez <dramirez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 14:27:56 by dramirez          #+#    #+#             */
/*   Updated: 2023/06/03 14:27:56 by dramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long_bonus.h"

/*Chequeamos la extensión del fichero del mapa*/
void	check_ext_file(char *mapa, t_juego *d)
{
	int	longitud;

	longitud = ft_strlen(mapa);
	if (longitud > 2 && mapa[longitud - 4] == '.' && mapa[longitud - 3] == 'b'
		&& mapa[longitud - 2] == 'e' && mapa[longitud - 1] == 'r');
	else
		ft_error_solong(d, 6);
}

/*Chequeamos que todas las filas tengan el mismo número de 
columnas y que los bordes son muros*/
void	check_mapa(t_juego *d)
{
	int	filas;
	int	columnas;

	filas = 0;
	d->columnas_mapa = (int)ft_strlen(d->mapa[0]);
	while (d->mapa[filas])
	{
		if (d->columnas_mapa != (int)ft_strlen(d->mapa[filas]))
			ft_error_solong(d, 7);
		columnas = 0;
		while (d->mapa[filas][columnas])
		{
			if (filas == 0 || columnas == 0 || filas == d->filas_mapa - 1
				|| columnas == d->columnas_mapa - 1)
			{
				if (d->mapa[filas][columnas] != '1')
					ft_error_solong(d, 1);
			}
			columnas++;
		}
		filas++;
	}
}

/*Chequeamos que el mapa tiene los caracteres obligatorios*/
void	check_elementos_mapa(t_juego *d)
{
	int	fila;
	int	col;

	fila = 0;
	while (d->mapa[++fila])
	{
		col = 0;
		while (d->mapa[fila][++col])
		{
			if (d->mapa[fila][col] == 'P')
			{
				d->jugador++;
				d->jugador_posx = col;
				d->jugador_posy = fila;
			}
			else if (d->mapa[fila][col] == 'C')
				d->consumibles++;
			else if (d->mapa[fila][col] == 'E')
				d->salida++;
			else if (d->mapa[fila][col] == 'X')
				d->enemigo++;
			else if (d->mapa[fila][col] != '1' && d->mapa[fila][col] != '0')
				ft_error_solong(d, 2);
		}
	}
	check_map2(d);
}

static void	ft_fillmap(t_juego *d, int x, int y)
{
	if (d->mapa_copia[y][x] == 'E')
	{
		d->mapa_copia[y][x] = '1';
		return ;
	}
	d->mapa_copia[y][x] = '1';
	if (d->mapa_copia[y + 1][x] != '1')
		ft_fillmap(d, x, y + 1);
	if (d->mapa_copia[y - 1][x] != '1')
		ft_fillmap(d, x, y - 1);
	if (d->mapa_copia[y][x + 1] != '1')
		ft_fillmap(d, x + 1, y);
	if (d->mapa_copia[y][x - 1] != '1')
		ft_fillmap(d, x - 1, y);
}

void	ft_camino(t_juego *d)
{
	int	posicion;

	posicion = 0;
	ft_fillmap(d, d->jugador_posx, d->jugador_posy);
	while (d->mapa_copia[posicion])
	{
		if (ft_strchr(d->mapa_copia[posicion], 'E')
			|| ft_strchr(d->mapa_copia[posicion], 'C'))
			ft_error_solong(d, 8);
		posicion++;
	}
	while (d->mapa_copia[posicion])
	{
		free(d->mapa_copia[posicion]);
		posicion++;
	}
}
