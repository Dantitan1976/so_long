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
	int		fd;

	fd = open(ruta_mapa, O_RDONLY);
	d->linea = malloc (1 * 1);
	fila = malloc(1 * 1);
	fila = get_next_line(fd);
	ruta_mapa = NULL;
	//if (!fila)
	//	ft_error_solong(d, 9);
	while (fila)
	{
		d->linea = ft_strjoin_solong(d->linea, fila);
		free(fila);
		fila = get_next_line(fd);
		d->filas_mapa++;
	}
	close(fd);
	d->mapa = ft_split(d->linea, '\n');
	d->columnas_mapa = ft_strlen(d->mapa[0]);
	d->mapa_copia = ft_split(d->linea, '\n');
	free(fila);
}

void	ft_print_mapa(char **matriz)
{
	int	y;

	y = 0;
	while (matriz[y])
	{
		ft_printf("%s\n", matriz[y]);
		y++;
	}
}
