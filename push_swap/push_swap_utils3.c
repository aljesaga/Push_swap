/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:09:32 by alsanche          #+#    #+#             */
/*   Updated: 2021/11/25 17:26:32 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*chr_min(t_list *stk_a, int n)
{
	int	*chr;
	int	count;

	chr = (int *)malloc(sizeof(int) * n);
	count = 0;
	while (count < n)
	{
		chr[count] = 2147483647;
		count++;
	}
	while (count > 0)
	{
		if (stk_a->content < chr[count - 1] && chr[count - 1] != chr[count])
		{
			chr[count - 1] = stk_a->content;
			count--;
		}
		else
			*stk_a = *stk_a->next;
	}
	return (chr);
}

void	ft_solu(t_list *stack_a, t_list *stack_b)
{
	int	points;

	points = ft_lstsize(stack_a);
	if (points == 2)
		ft_result_2(&stack_a);
	else if (points == 3)
		ft_result_3(&stack_a);
	else if (points == 4)
		ft_result_4_5(&stack_a, &stack_b, 1);
	else if (points == 5)
		ft_result_4_5(&stack_a, &stack_b, 2);
	return ;
}
