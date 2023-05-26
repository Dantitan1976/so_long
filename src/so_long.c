/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramirez <dramirez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 18:09:23 by dramirez          #+#    #+#             */
/*   Updated: 2023/05/20 18:09:23 by dramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	mapa_limites(t_list_solong *d, char *mapa)
{
	int	longitud;

	longitud = ft_strlen(mapa);
	if (longitud > 2 && mapa[longitud - 4] == '.' && mapa[longitud - 3] == 'b'
		&& mapa[longitud - 2] == 'e' && mapa[longitud - 1] == 'r');
	else
		ft_error_solong(d, 6);
}

int	inicializar_datos(t_list_solong *d, char *mapa)
{
	d->movimientos = 0;
	mapa_limites(d, mapa);
}

int	main(int argc, char **argv)
{
	t_list_solong	*d;

	if (argc != 2)
	{
		ft_printf("\033[0;91mNúmero incorrecto de argumentos\033[0;39m");
		return (0);
	}
	d = ft_calloc(1, sizeof(t_list_solong));
	if (!d)
		return (0);
	d->mlx = mlx_init(1920, 1080, "So_Long", 1);
}
