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

/*Chequeamos la extensión del fichero del mapa*/
void	check_ext_file(char *mapa, t_juego *d)
{
	int	longitud;

	longitud = ft_strlen(mapa);
	if (longitud > 2 && mapa[longitud - 4] == '.' && mapa[longitud - 3] == 'b'
		&& mapa[longitud - 2] == 'e' && mapa[longitud - 1] == 'r');
	else
		ft_error_solong(d, 6);
}

int	inicializar_datos(t_juego *d, char *mapa)
{
	d->movimientos = 0;
	check_ext_file(mapa, d);
	ft_leer_mapa(mapa, d);
	return (0);
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
	ft_leer_mapa(argv[1], &d);
	ft_printf("Número de filas%d\n", d.filas_mapa);
	ft_printf("Número de columnas%d\n", d.columnas_mapa);
	
	d.mlx = mlx_init(d.columnas_mapa * 50, d.filas_mapa * 50, "So_Long", 0);
	mlx_loop(d.mlx);
}
