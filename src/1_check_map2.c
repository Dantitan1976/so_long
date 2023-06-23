/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_check_map2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramirez <dramirez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 19:44:56 by dramirez          #+#    #+#             */
/*   Updated: 2023/06/22 19:44:56 by dramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	check_map2(t_juego *d)
{
	int	fila;
	int	col;

	fila = 0;
	while (d->mapa[++fila])
	{
		col = 0;
		while (d->mapa[fila][++col])
		{
			if (d->jugador != 1)
				ft_error_solong(d, 4);
			else if (d->salida != 1)
				ft_error_solong(d, 5);
			else if (d->consumibles < 1)
				ft_error_solong(d, 3);
		}
	}
}
