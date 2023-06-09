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

t_juego	*inicializar_struct(t_juego *d, char *argv)
{
	d->mlx = NULL;
	d->palm = NULL;
	d->arena = NULL;
	d->cofre = NULL;
	d->pirata = NULL;
	d->exit = NULL;
	d->movimientos = 0;
	d->consumibles = 0;
	d->jugador = 0;
	d->salida = 0;
	d->muro = 0;
	d->vacio = 0;
	d->filas_mapa = 0;
	d->columnas_mapa = 0;
	d->mapa_nombre = ft_strdup(argv);
	return (d);
}

int	main(int argc, char **argv)
{
	t_juego	d;

	(void)argv;
	if (argc != 2)
	{
		ft_printf("\033[0;91mNúmero incorrecto de argumentos\033[0;39m");
		return (0);
	}
	check_ext_file(argv[1], &d);
	inicializar_struct(&d, argv[1]);
	ft_leer_mapa(argv[1], &d);
	ft_printf("Número de filas%d\n", d.filas_mapa);
	ft_printf("Número de columnas%d\n", d.columnas_mapa);
	d.mlx = mlx_init(d.columnas_mapa * 50, d.filas_mapa * 50, "So_Long", 0);
	mlx_loop(d.mlx);
}
