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

#include "../include/so_long.h"

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
			else if (d->mapa[fila][col] != '1' && d->mapa[fila][col] != '0')
				ft_error_solong(d, 2);
		}
	}
	if (d->jugador != 1 || d->salida != 1 || d->consumibles < 1)
		ft_error_solong(d, 2);
}

/*Comprobamos que la posicion a comprobar está dento del mapa
Como la salida 'E', los consumibles 'C' y el camino libre '0'
son objetos por los que podemos pasar, los convertimos en 'F'*/
void	ft_flood_fill(t_juego *d, int pos_ejex, int pos_ejey)
{
	if (pos_ejex < 0 || pos_ejey < 0 || pos_ejey > d->filas_mapa
		|| pos_ejex > d->columnas_mapa
		|| d->mapa_copia[pos_ejex][pos_ejey] == '1'
		|| d->mapa_copia[pos_ejex][pos_ejey] == 'F')
		return ;
	if (d->mapa_copia[pos_ejex][pos_ejey] == 'E'
		|| d->mapa_copia[pos_ejex][pos_ejey] == 'C')
			d->mapa_copia[pos_ejex][pos_ejey] = '0';
	d->mapa_copia[pos_ejex][pos_ejey] = 'F';
	ft_flood_fill(d, pos_ejex + 1, pos_ejey);
	ft_flood_fill(d, pos_ejex - 1, pos_ejey);
	ft_flood_fill(d, pos_ejex, pos_ejey + 1);
	ft_flood_fill(d, pos_ejex, pos_ejey - 1);
}

void	ft_camino(t_juego *d)
{
	int	filas;
	int	columnas;

	filas = 0;
	while (d->mapa_copia[++filas])
	{
		columnas = 0;
		while (d->mapa_copia[filas][++columnas])
		{
			if (d->mapa_copia[filas][columnas] == 'E' ||
				d->mapa_copia[filas][columnas] == 'C')
				ft_error_solong(d, 8);
			columnas++;
		}
		filas++;
	}
}
