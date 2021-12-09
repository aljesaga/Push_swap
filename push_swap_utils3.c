/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:09:32 by alsanche          #+#    #+#             */
/*   Updated: 2021/12/09 13:31:35 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	serch_place(t_list *aux, t_list **stk)
{
	t_list	*temp;
	int		count;

	temp = *stk;
	count = 0;
	while (temp)
	{
		if (aux->content > temp->content)
			count++;
		temp = temp->next;
	}
	return (count);
}

void	ft_map_num(t_list **stk, int point)
{
	t_list	*aux;
	int		*nums;
	int		i;

	nums = calloc(point, sizeof(int));
	if (!nums)
		exit (-1);
	aux = *stk;
	i = 0;
	while (i < point)
	{
		nums[i] = serch_place(aux, stk);
		i++;
		aux = aux->next;
	}
	i = 0;
	aux = *stk;
	while (i < point)
	{
		aux->content = nums[i];
		i++;
		aux = aux->next;
	}
	free(nums);
}