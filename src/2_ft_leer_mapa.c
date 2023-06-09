/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_leer_mapa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramirez <dramirez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 00:07:02 by dramirez          #+#    #+#             */
/*   Updated: 2023/05/27 00:07:02 by dramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*Leemos el mapa usando get_next_line, volcando todos los datos en mapa.
Unimos todas las filas que leemos en una fila que llamamos mapa y luego 
la separamos con el split. También chequeamos que el mapa no empieza con
un salto de linea o que la fila no exista*/
void	ft_leer_mapa(char *ruta_mapa, t_juego *d)
{
	char	*fila;
	char	*mapa_str;
	int		fd;

	d->filas_mapa = 0;
	d->columnas_mapa = 0;
	mapa_str = malloc (1 * 1);
	fila = malloc(1 * 1);
	fd = open(ruta_mapa, O_RDONLY);
	fila = get_next_line(fd);
	//mapa = NULL;
	//if (!fila)
	//	ft_error_solong(d, 9);
	while (fila)
	{
		mapa_str = ft_strjoin_solong(mapa_str, fila);
		free(fila);
		fila = get_next_line(fd);
		d->filas_mapa++;
	}
	close(fd);
	//if (mapa_str[0] == '\n')
	//	ft_error_solong(d, 9);
	d->mapa = ft_split(mapa_str, '\n');
	d->columnas_mapa = ft_strlen(d->mapa[0]);
	d->mapa_copia = ft_split(mapa_str, '\n');
	free(fila);
	free(mapa_str);
}
