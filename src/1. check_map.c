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

/*	Chequeamos que el primer y último caracteres de la linea sean muros
	Con posicion = d->anchura_mapa chequeamos el primer caracter
	Con posicion = d->anchura_mapa - 2 chequeamos el último caracter*/

#include "../include/so_long.h"

void	check_linea1(t_juego *d)
{
	int	posicion;

	posicion = d->columnas_mapa - 2;
	while (posicion < ft_strlen(d->linea))
	{
		if (d->linea[posicion] == '1')
			posicion = posicion + d->columnas_mapa;
		else
			ft_error_solong(d, 2);
	}
	posicion = d->columnas_mapa;
	while (posicion < ft_strlen(d->linea))
	{
		if (d->linea[posicion] == '1')
			posicion = posicion + d->columnas_mapa;
		else
			ft_error_solong(d, 1);
	}
}

/*	Chequeamos que la primera fila y la última son muros
	Con while (posicion != d->anchura_mapa) chequeamos la primera fila completa
	Con while (ultimo != ft_strlen(d->linea)*/
void	check_linea2(t_juego *d)
{
	int	posicion;
	int	ultimo;

	posicion = 0;
	ultimo = ft_strlen(d->linea) - d->columnas_mapa;
	while (posicion != d->columnas_mapa)
	{
		if (d->linea[posicion] == '1' || d->linea[posicion] == '\n')
			posicion++;
		else
			ft_error_solong(d, 4);
	}
	while (ultimo != ft_strlen(d->linea))
	{
		if (d->linea[ultimo] == '1' || d->linea[ultimo] == '\n')
			ultimo++;
		else
			ft_error_solong(d, 4);
	}
	check_linea1(d);
}

void	check_elementos_linea(t_juego *d)
{
	int	posicion;

	posicion = 0;
	while (d->linea[posicion])
	{
		if (d->linea[posicion] != 'C' && d->linea[posicion] != 'P'
			&& d->linea[posicion] != 'E' && d->linea[posicion] != '1'
			&& d->linea[posicion] != '0' && d->linea[posicion] != '\n')
			ft_error_solong(d, 8);
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

/*Chequeamos que todas las filas tengan el mismo número de 
columnas*/
void	check_mapa(t_juego *d)
{
	int	filas;

	filas = 0;
	d->columnas_mapa = (int)ft_strlen(d->mapa[0]);
	while (d->mapa[filas])
	{
		if (d->columnas_mapa != (int)ft_strlen(d->mapa[filas]))
			ft_error_solong(d, 7);
	}
	filas++;
}
