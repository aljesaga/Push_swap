/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/12 15:27:30 by alsanche          #+#    #+#             */
/*   Updated: 2021/11/24 16:54:59 by aviscogl         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t		i;
	char		*aux;
	const char	*ax;

	i = 0;
	aux = dest;
	ax = src;
	if (aux == '\0' && ax == '\0')
		return (NULL);
	while (i < n)
	{
		aux[i] = ax[i];
		i++;
	}
	return (dest);
}
