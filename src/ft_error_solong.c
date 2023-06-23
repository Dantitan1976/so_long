/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_solong.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramirez <dramirez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 12:14:07 by dramirez          #+#    #+#             */
/*   Updated: 2023/05/21 12:14:07 by dramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_error_solong2(t_juego *d, int error)
{
	(void)d;
	if (error == 8)
		ft_printf("\033[0;91m\nError. No hay salida posible.\033[0;39m\n");
	if (error == 9)
		ft_printf("\033[0;91m\nError. El mapa no es válido.\033[0;39m\n");
	exit(0);
}

void	ft_error_solong(t_juego *d, int error)
{
	ft_printf("\033[0;91m\n***** ERROR ***** \033[0;39m\n");
	if (error > 7)
		ft_error_solong2(d, error);
	if (error == 1)
		ft_printf("\033[0;91m\nFaltan muros en los bordes.\033[0;39m\n");
	if (error == 2)
		ft_printf("\033[0;91m\nError. Caracteres erróneos.\033[0;39m\n");
	if (d->consumibles < 1 && error == 3)
		ft_printf("\033[0;91m\nEl mapa no tiene consumibles.\033[0;39m\n");
	if (d->jugador != 1 && error == 4)
		ft_printf("\033[0;91m\nEl mapa debe tener un jugador.\033[0;39m\n");
	if (d->salida < 1 && error == 5)
		ft_printf("\033[0;91m\nEl mapa debe tener una salida.\033[0;39m\n");
	if (error == 6)
		ft_printf("\033[0;91m\nExtensión del fichero incorrecta.\033[0;39m\n");
	if (error == 7)
		ft_printf("\033[0;91m\nEl mapa tiene que ser rectangular.\033[0;39m\n");
	exit(0);
}
