/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:59:16 by alsanche          #+#    #+#             */
/*   Updated: 2021/11/24 17:13:50 by aviscogl         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_result_2(t_list *stk_a)
{
	if (stk_a->content > stk_a->next->content)
		swap(stk_a, stk_a, 0);
}

void	ft_result_3(t_list *stk_a)
{
	if (stk_a->content > stk_a->next->content)
	{
		if (stk_a->content < stk_a->next->next->content)
			swap(stk_a, stk_a, 0);
		else if (stk_a->next->content > stk_a->next->next->content)
		{
			swap(stk_a, stk_a, 0);
			rrr(stk_a, stk_a, 0);
		}
		else if (stk_a->next->content < stk_a->next->next->content)
			rr(stk_a, stk_a, 0);
	}
	else if (stk_a->content < stk_a->next->content)
	{
		if (stk_a->next->content > stk_a->next->next->content)
		{
			swap(stk_a, stk_a, 0);
			rr(stk_a, stk_a, 0);
		}
		else if (stk_a->content > stk_a->next->next->content)
			rrr(stk_a, stk_a, 0);
	}
}

void	ft_result_4_5(t_list *stk_a, t_list *stk_b, int n)
{
	int	*chr;

	chr = chr_min(stk_a, n);
	while (n > 0)
	{
		if (stk_a->content == chr[0])
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
