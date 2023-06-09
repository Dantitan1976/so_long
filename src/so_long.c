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
	d->barco = NULL;
	d->movimientos = 0;
	d->consumibles = 0;
	d->consumibles_total = 0;
	d->jugador = 0;
	d->jugador_posx = 0;
	d->jugador_posx_act = 0;
	d->jugador_posy = 0;
	d->jugador_posy_act = 0;
	d->salida = 0;
	d->filas_mapa = 0;
	d->columnas_mapa = 0;
	d->mapa_nombre = ft_strdup(argv);
	return (d);
}

void	chequeos(t_juego *d)
{
	check_elementos_mapa(d);
	check_mapa(d);
	d->consumibles_total = d->consumibles;
	ft_camino(d);
	ft_mostrar_mapa(d);
	ft_free_solong(d);
}

int	ft_victoria(t_juego *d, int filas, int columnas)
{
	if (d->mapa[filas][columnas] == 'E')
	{
		if (d->consumibles == 0)
		{
			if (d->mapa[filas][columnas] == 'E')
			{
				ft_printf("¡¡¡¡Eres el pirata más famoso del Caribe!!!!\n");
				ft_printf("Total movimientos: %d\n", d->movimientos);
				mlx_close_window(d->mlx);
				return (1);
			}
		}
		else
			ft_printf("¡¡¡¡Arrrrr, grumetillo!!!! Quedan tesoros por recoger\n");
	}
	return (0);
}

void	ft_tesoro_capturado(t_juego *d)
{
	int	cofres;

	cofres = 0;
	while (cofres < d->consumibles_total)
	{
		if (d->cofre->instances[cofres].x == d->pirata->instances[0].x
			&& d->cofre->instances[cofres].y == d->pirata->instances[0].y)
		{
			ft_printf("¡¡¡He encontrado un tesoro!!!\n");
			d->cofre->instances[cofres].enabled = 0;
		}
		cofres++;
	}
}

int	main(int argc, char **argv)
{
	t_juego	d;

	atexit(ft_leaks);
	if (argc != 2)
	{
		ft_printf("\033[0;91mNúmero incorrecto de argumentos\033[0;39m");
		return (0);
	}
	check_ext_file(argv[1], &d);
	inicializar_struct(&d, argv[1]);
	ft_leer_mapa(argv[1], &d);
	ft_printf("Número de filas: %d\n", d.filas_mapa);
	ft_printf("Número de columnas: %d\n", d.columnas_mapa);
	ft_print_mapa(d.mapa);
	chequeos(&d);
}
