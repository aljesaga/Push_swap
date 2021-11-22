/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:59:16 by alsanche          #+#    #+#             */
/*   Updated: 2021/11/22 16:58:41 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_result_2(t_stack *stk_a)
{
	if (stk_a->num > stk_a->next->num)
		swap(stk_a, stk_a, 0);
}

void	ft_result_3(t_stack *stk_a)
{
	if (stk_a->num > stk_a->next->num)
	{
		if (stk_a->num < stk_a->next->next->num)
			swap(stk_a, stk_a, 0);
		else if (stk_a->next->num > stk_a->next->next->num)
		{
			swap(stk_a, stk_a, 0);
			rrr(stk_a, stk_a, 0);
		}
		else if (stk_a->next->num < stk_a->next->next->num)
			rr(stk_a, stk_a, 0);
	}
	else if (stk_a->num < stk_a->next->num)
	{
		if (stk_a->next->num > stk_a->next->next->num)
		{
			swap(stk_a, stk_a, 0);
			rr(stk_a, stk_a, 0);
		}
		else if (stk_a->num > stk_a->next->next->num)
			rrr(stk_a, stk_a, 0);
	}
}

void	ft_result_4_5(t_stack *stk_a, t_stack *stk_b, int n)
{
	int	*chr;

	chr = chr_min(stk_a, n);
	while (n > 0)
	{
		if (stk_a->num == chr[0])
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
