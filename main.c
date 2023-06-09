/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramirez <dramirez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 20:39:45 by dramirez          #+#    #+#             */
/*   Updated: 2023/05/21 20:39:45 by dramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../MLX42/include/MLX42/MLX42.h"

int	main(int argc, char **argv)
{
	t_juego	d;

	if (argc != 2)
		return (0);
	ft_leer_mapa(argv[1], &d);
	d.mlx = mlx_init(d.columnas_mapa, d.filas_mapa, "So_Long", 0);
	mlx_loop(d.mlx);
}
