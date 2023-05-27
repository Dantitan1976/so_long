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

void	check_linea_inicial(t_list_solong *d)
{
	int	posicion;

	posicion = d->anchura_mapa - 2;
	while (posicion < ft_strlen(d->linea))
	{
		if (d->linea[posicion] == '1')
			posicion = posicion + d->anchura_mapa;
		else
			ft_error_solong(d, 2);
	}
	posicion = d->anchura_mapa;
	while (posicion < ft_strlen(d->linea))
	{
		if (d->linea[posicion] == '1')
			posicion = posicion + d->anchura_mapa;
		else
			ft_error_solong(d, 1);
	}
}

void	check_primera_linea(t_list_solong *d)
{
	int	posicion;
	int	ultimo;

	posicion = 0;
	ultimo = ft_strlen(d->linea) - d->anchura_mapa;
	while (posicion != d->anchura_mapa)
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
	check_linea_inicial(d);
}

void	check_chars_linea(t_list_solong *d)
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

void	check_salto_linea(t_list_solong *d, char *fila)
{
	int	posicion;

	posicion = 0;
	d->linea_control = 1;
	while (fila[posicion])
	{
		if (fila[posicion] == '\n')
			d->linea_control = 0;
		posicion++;
	}

}

void	ft_leer_mapa(char *mapa, t_list_solong *d)
{
	char	*fila;
	int		fd;

	fd = open(mapa, O_RDONLY);
	if (fd < 0)
		ft_free(d);
	d->linea_control = 2;
	while (d->linea_control != 1)
	{
		d->altura_mapa++;
		fila = get_next_line(fd);
		if (!fila)
			ft_error_solong(d, 9);
		if (d->linea_control == 2)
			d->anchura_mapa = ft_strlen(fila);
		check_salto_linea(d, fila);
		if ((ft_strlen(fila) + d->linea_control) != d->anchura_mapa)
			ft_error_solong(d, 7);
		d->linea = ft_strjoin(d->linea, fila);
		if (fila)
			free(fila);
	}
	close(fd);
	check_primera_linea(d);
	check_chars_linea(d);
}
