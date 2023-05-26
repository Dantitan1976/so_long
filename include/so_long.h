/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramirez <dramirez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/20 19:05:15 by dramirez          #+#    #+#             */
/*   Updated: 2023/05/20 19:05:15 by dramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"

typedef struct s_list_solong
{
	void	*mlx;
	char	*linea;
	int		movimientos;
	int		consumibles;
	int		jugador;
	int		salida;
	int		errores;
}	t_list_solong;

void	mapa_limites(t_list_solong *d, char *mapa);
int		inicializar_datos(t_list_solong *d, char *mapa);
int		main(int argc, char **argv);
void	ft_error_solong2(t_list_solong *d, int error);
void	ft_error_solong(t_list_solong *d, int error);
int		ft_free(t_list_solong *d);

#endif