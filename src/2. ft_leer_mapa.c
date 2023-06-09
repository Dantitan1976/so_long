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
void	ft_leer_mapa(char *mapa, t_juego *d)
{
	char	*fila;
	int		fd;

	fila = get_next_line(fd);
	mapa = NULL;
	if (!fila)
		ft_error_solong(d, 9);
	while (fila)
	{
		mapa = ft_strjoin_solong(mapa, fila);
		free(fila);
		fila = get_next_line(fd);
		d->filas_mapa++;
	}
	if (mapa[0] == '\n')
		ft_error_solong(d, 9);
	d->mapa = ft_split(fila, '\n');
	d->mapa_copia = ft_split(fila, '\n');
	free(fila);
	free(mapa);
}