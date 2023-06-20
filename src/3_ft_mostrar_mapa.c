/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mostrar_mapa.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramirez <dramirez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 20:56:26 by dramirez          #+#    #+#             */
/*   Updated: 2023/05/27 20:56:26 by dramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*Iniciamos el juego*/
void	ft_mostrar_mapa(t_juego *d)
{
	ft_crear_mapa(d);
	ft_generar_mapa(d);
	ft_generar_jugador(d);
	mlx_key_hook(d->mlx, &ft_movim_jugador, d);
	mlx_loop(d->mlx);
	mlx_terminate(d->mlx);
}

/*Creamos la ventana y cargamos en la estructura las imágnenes en png (texturas)
Pasamos las texturas a imágenes y borramos después las texturas*/
void	ft_crear_mapa(t_juego *d)
{
	t_texturas	*textura;

	textura = malloc(sizeof(t_texturas));
	d->mlx = mlx_init(d->columnas_mapa * 75, d->filas_mapa * 75, "So_Long", 0);
	if (!d->mlx)
		ft_printf("\033[0;91mError librería gráfica\nCTRL+C: Salir\033[0;39m\n");
	textura->palm_text = mlx_load_png("img/png/palmera.png");
	textura->arena_text = mlx_load_png("img/png/arena.png");
	textura->cofre_text = mlx_load_png("img/png/cofre.png");
	textura->pirata_text = mlx_load_png("img/png/pirata.png");
	textura->barco_text = mlx_load_png("img/png/barco.png");
	d->palm = mlx_texture_to_image(d->mlx, textura->palm_text);
	d->arena = mlx_texture_to_image(d->mlx, textura->arena_text);
	d->cofre = mlx_texture_to_image(d->mlx, textura->cofre_text);
	d->pirata = mlx_texture_to_image(d->mlx, textura->pirata_text);
	d->barco = mlx_texture_to_image(d->mlx, textura->barco_text);
	mlx_delete_texture(textura->palm_text);
	mlx_delete_texture(textura->arena_text);
	mlx_delete_texture(textura->cofre_text);
	mlx_delete_texture(textura->pirata_text);
	mlx_delete_texture(textura->barco_text);

}

/*Generamos el mapa colocando cada objeto en el mapa usando la
función mlx_image_to_window para mostrarlo en pantalla. Primero colocamos
el fondo (arena) para que, cuando coloquemos la imagen,
aparezca ya sobre el fondo.*/
void	ft_generar_mapa(t_juego *d)
{
	int		col;
	int		fil;

	col = 0;
	fil = 0;
	while (d->mapa[fil])
	{
		while (d->mapa[fil][col])
		{
			mlx_image_to_window (d->mlx, d->arena, col * 75, fil * 75);
			if (d->mapa[fil][col] == 'C')
				mlx_image_to_window (d->mlx, d->cofre, col * 75, fil * 75);
			else if (d->mapa[fil][col] == 'E')
				mlx_image_to_window (d->mlx, d->barco, col * 75, fil * 75);
			else if (d->mapa[fil][col] == '1')
				mlx_image_to_window (d->mlx, d->palm, col * 75, fil * 75);
			col++;
		}
		col = 0;
		fil++;
	}
}

void	ft_generar_jugador(t_juego *d)
{
	int		col;
	int		fil;

	col = 0;
	fil = 0;
	while (d->mapa[fil])
	{
		while (d->mapa[fil][col])
		{
			if (d->mapa[fil][col] == 'P')
				mlx_image_to_window (d->mlx, d->pirata, col * 75, fil * 75);
			col++;
		}
		col = 0;
		fil++;
	}
}