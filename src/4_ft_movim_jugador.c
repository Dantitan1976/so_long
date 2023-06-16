/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_ft_movim_jugador.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramirez <dramirez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 22:45:11 by dramirez          #+#    #+#             */
/*   Updated: 2023/06/13 22:45:11 by dramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	ft_movim_jugador(mlx_key_data_t tecla, void *parametro)
{
	t_juego	*d;

	d = parametro;
	d->jugador_posx_act = d->pirata->instances[0].x / 75;
	d->jugador_posy_act = d->pirata->instances[0].y / 75;
	if ((tecla.key == MLX_KEY_W || tecla.key == MLX_KEY_UP)
		&& tecla.action == MLX_RELEASE)
		ft_arriba(d);
	if ((tecla.key == MLX_KEY_S || tecla.key == MLX_KEY_DOWN)
		&& tecla.action == MLX_RELEASE)
		ft_abajo(d);
	if ((tecla.key == MLX_KEY_A || tecla.key == MLX_KEY_LEFT)
		&& tecla.action == MLX_RELEASE)
		ft_izquierda(d);
	if ((tecla.key == MLX_KEY_D || tecla.key == MLX_KEY_RIGHT)
		&& tecla.action == MLX_RELEASE)
		ft_derecha(d);
	if (tecla.key == MLX_KEY_ESCAPE && tecla.action == MLX_RELEASE)
		mlx_close_window(d->mlx);
}

void	ft_arriba(t_juego *d)
{
	if (d->mapa[d->jugador_posy_act - 1][d->jugador_posx_act] == '1'
		|| (d->mapa[d->jugador_posy_act - 1][d->jugador_posx_act] == 'E'
			&& !ft_victoria(d, d->jugador_posy_act - 1, d->jugador_posx_act)))
		return ;
	d->pirata->instances[0].y -= 75;
	if (d->mapa[d->jugador_posy_act - 1][d->jugador_posx_act] == 'C')
	{
		d->consumibles--;
		ft_tesoro_capturado(d);
	}
	d->mapa[d->jugador_posy_act][d->jugador_posx_act] = '0';
	d->mapa[d->jugador_posy_act - 1][d->jugador_posx_act] = 'P';
	d->jugador_posy_act--;
	d->movimientos++;
	ft_printf("Movimientos: %d\r", d->movimientos);
}

void	ft_abajo(t_juego *d)
{
	if (d->mapa[d->jugador_posy_act + 1][d->jugador_posx_act] == '1'
		|| (d->mapa[d->jugador_posy_act + 1][d->jugador_posx_act] == 'E'
			&& !ft_victoria(d, d->jugador_posy_act + 1, d->jugador_posx_act)))
		return ;
	d->pirata->instances[0].y += 75;
	if (d->mapa[d->jugador_posy_act + 1][d->jugador_posx_act] == 'C')
	{
		d->consumibles--;
		ft_tesoro_capturado(d);
	}
	d->mapa[d->jugador_posy_act][d->jugador_posx_act] = '0';
	d->mapa[d->jugador_posy_act + 1][d->jugador_posx_act] = 'P';
	d->jugador_posy_act++;
	d->movimientos++;
	ft_printf("Movimientos: %d\r", d->movimientos);
}

/*void	ft_abajo(t_juego *game)
{
	if (game->mapa[game->jugador_posy_act + 1][game->jugador_posx_act] == '1'
		|| (game->mapa[game->jugador_posy_act + 1][game->jugador_posx_act] == 'E'
			&& !ft_victoria(game, game->jugador_posy_act + 1, game->jugador_posx_act)))
		return ;wwss
	game->pirata->instances[0].y += 75;
	if (game->mapa[game->jugador_posy_act + 1][game->jugador_posx] == 'C')
	{
		game->consumibles--;
		ft_tesoro_capturado(game);
	}
	game->mapa[game->jugador_posy_act][game->jugador_posx_act] = '0';
	game->mapa[game->jugador_posy_act + 1][game->jugador_posx_act] = 'P';
	game->jugador_posy_act++;
	game->movimientos++;
	ft_printf("Moves: %d\n", game->movimientos);
}*/

void	ft_izquierda(t_juego *d)
{
	if (d->mapa[d->jugador_posy_act][d->jugador_posx_act - 1] == '1'
		|| (d->mapa[d->jugador_posy_act][d->jugador_posx_act - 1] == 'E'
			&& !ft_victoria(d, d->jugador_posy_act, d->jugador_posx_act - 1)))
		return ;
	d->pirata->instances[0].x -= 75;
	if (d->mapa[d->jugador_posy_act][d->jugador_posx_act - 1] == 'C')
	{
		d->consumibles--;
		ft_tesoro_capturado(d);
	}
	d->mapa[d->jugador_posy_act][d->jugador_posx_act] = '0';
	d->mapa[d->jugador_posy_act][d->jugador_posx_act - 1] = 'P';
	d->jugador_posx_act--;
	d->movimientos++;
	ft_printf("Movimientos: %d\r", d->movimientos);
}

void	ft_derecha(t_juego *d)
{
	if (d->mapa[d->jugador_posy_act][d->jugador_posx_act + 1] == '1'
		|| (d->mapa[d->jugador_posy_act][d->jugador_posx_act + 1] == 'E'
			&& !ft_victoria(d, d->jugador_posy_act, d->jugador_posx_act + 1)))
		return ;
	d->pirata->instances[0].x += 75;
	if (d->mapa[d->jugador_posy_act][d->jugador_posx_act + 1] == 'C')
	{
		d->consumibles--;
		ft_tesoro_capturado(d);
	}
	d->mapa[d->jugador_posy_act][d->jugador_posx_act] = '0';
	d->mapa[d->jugador_posy_act][d->jugador_posx_act + 1] = 'P';
	d->jugador_posx_act++;
	d->movimientos++;
	ft_printf("Movimientos: %d\r", d->movimientos);
}
