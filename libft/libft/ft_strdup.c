/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramirez <dramirez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 20:50:30 by dramirez          #+#    #+#             */
/*   Updated: 2023/06/25 17:14:38 by dramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*duplicado;
	size_t	longitud;

	longitud = ft_strlen(s) + 1;
	duplicado = malloc(sizeof(char) * longitud);
	if (duplicado == NULL)
		return (NULL);
	duplicado = ft_memcpy(duplicado, s, longitud);
	return (duplicado);
}
