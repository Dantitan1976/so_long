/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_solong.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dramirez <dramirez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/03 11:53:31 by dramirez          #+#    #+#             */
/*   Updated: 2023/06/03 11:53:31 by dramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Ojo, en MacOs da un error de leak de memoria si no ponemos free((char *)s1);
antes del return (cadena3)*/
char	*ft_strjoin_solong(char const *s1, char const *s2)
{
	char	*cadena3;
	size_t	cont_cadsrc;
	size_t	cont_cad3;

	if (!s1)
		return (ft_strdup(s2));
	cadena3 = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!cadena3)
		return (NULL);
	cont_cadsrc = 0;
	cont_cad3 = 0;
	while (s1[cont_cadsrc])
		cadena3[cont_cad3++] = s1[cont_cadsrc++];
	cont_cadsrc = 0;
	while (s2[cont_cadsrc])
		cadena3[cont_cad3++] = s2[cont_cadsrc++];
	cadena3[cont_cad3] = '\0';
	return (cadena3);
}
