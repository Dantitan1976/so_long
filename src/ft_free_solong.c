/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_solong.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramirez <dramirez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 23:53:42 by dramirez          #+#    #+#             */
/*   Updated: 2023/05/21 23:53:42 by dramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_free_solong(t_juego *d)
{
	int	posicion;

	posicion = 0;
	while (posicion < d->filas_mapa)
	{
		free(d->mapa[posicion]);
		free(d->mapa_copia[posicion]);
		posicion++;
	}
	if (d->linea)
		free(d->linea);
	if (d->mapa)
	{
		free(d->mapa);
		free(d->mapa_copia);
	}
	if (d->mapa_nombre != NULL)
		free(d->mapa_nombre);
	//free(d);
}
