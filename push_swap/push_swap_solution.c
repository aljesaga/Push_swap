/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:59:16 by alsanche          #+#    #+#             */
/*   Updated: 2021/11/25 16:59:34 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_result_2(t_list **stk_a)
{
	t_list	*aux;

	aux = *stk_a;
	if (aux->content > aux->next->content)
		swap(stk_a, stk_a, 0);
	return ;
}

void	ft_result_3(t_list **stk)
{
	t_list	*stk_a;

	stk_a = *stk;
	if (stk_a->content > stk_a->next->content)
	{
		if (stk_a->content < stk_a->next->next->content)
			swap(&stk_a, &stk_a, 0);
		else if (stk_a->next->content > stk_a->next->next->content)
		{
			swap(&stk_a, &stk_a, 0);
			rrr(&stk_a, &stk_a, 0);
		}
		else if (stk_a->next->content < stk_a->next->next->content)
			rr(&stk_a, &stk_a, 0);
	}
	else if (stk_a->content < stk_a->next->content)
	{
		if (stk_a->next->content > stk_a->next->next->content)
		{
			swap(&stk_a, &stk_a, 0);
			rr(&stk_a, &stk_a, 0);
		}
		else if (stk_a->content > stk_a->next->next->content)
			rrr(&stk_a, &stk_a, 0);
	}
}

void	ft_result_4_5(t_list **stk_a, t_list **stk_b, int n)
{
	t_list	*aux;
	int		*chr;

	aux = *stk_a;
	chr = chr_min(aux, n);
	while (n > 0)
	{
		if (aux->content == chr[0])
		{
			push(stk_a, stk_b, 1);
			n--;
		}
		else
			rrr(stk_a, stk_b, 0);
	}
	ft_result_3(stk_a);
	push(stk_a, stk_b, 0);
}
