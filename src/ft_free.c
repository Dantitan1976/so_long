/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramirez <dramirez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 23:53:42 by dramirez          #+#    #+#             */
/*   Updated: 2023/05/21 23:53:42 by dramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_free(t_juego *d)
{
	d->errores = 1;
	if (d->linea)
		free(d->linea);
	if (d)
		free(d);
	exit (0);
}
