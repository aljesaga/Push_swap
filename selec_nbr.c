/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selec_nbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/11 14:13:30 by alsanche          #+#    #+#             */
/*   Updated: 2021/12/11 16:00:42 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*chr_max(t_list **stk)
{
	t_list	*aux;
	int		*chr;

	chr = malloc(sizeof(int) * 3);
	if (!chr)
		return (0);
	chr[2] = 0;
	chr[1] = INT_MIN;
	aux = *stk;
	while (aux)
	{
		if (aux->content > chr[1])
		{
			chr[1] = aux->content;
			chr[0] = chr[2];
		}
		chr[2]++;
		aux = aux->next;
	}
	return (chr);
}

int	*find(t_list **stk, int *min, int check)
{
	int		*i;
	t_list	*aux;

	i = malloc(sizeof(int) * 3);
	if (!i)
		exit (-1);
	aux = *stk;
	i[2] = 0;
	while (aux)
	{
		if (aux->content >= min[0] && aux->content <= min[1])
		{
			i[1] = aux->content;
			i[0] = i[2];
			if (check == 0)
				return (i);
		}
		aux = aux->next;
		i[2]++;
	}
	return (i);
}

int	*selec_nbr(t_list **stk_a, int *min)
{
	int	*first;
	int	*last;

	first = find(stk_a, min, 0);
	last = find(stk_a, min, 1);
	if (ft_lstsize(*stk_a) - last[0] < first[0])
	{
		free(first);
		return (last);
	}
	free(last);
	return (first);
}
