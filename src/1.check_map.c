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

/*Chequeamos que la línea que contiene el mapa completo tiene alguno
de los caracteres obligatorios*/
void	check_elementos_linea(t_juego *d)
{
	int	posicion;

	posicion = 0;
	while (d->linea[posicion])
	{
		if (d->linea[posicion] != 'C' && d->linea[posicion] != 'P'
			&& d->linea[posicion] != 'E' && d->linea[posicion] != '1'
			&& d->linea[posicion] != '0' && d->linea[posicion] != '\n')
			ft_error_solong(d, 2);
		if (d->linea[posicion] == 'C')
			d->consumibles++;
		if (d->linea[posicion] == 'P')
			d->jugador++;
		if (d->linea[posicion] == 'E')
			d->salida++;
		if (d->linea[posicion] == '1')
			d->muro++;
		if (d->linea[posicion] == '0')
			d->vacio++;
		posicion++;
	}
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
		|| d->mapa_copia[pos_ejex][pos_ejey] == 'C'
		|| d->mapa_copia[pos_ejex][pos_ejey] == '0')
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
			if (d->mapa_copia[filas][columnas] == 'E')
				ft_error_solong(d, 8);
		}
	}
}
