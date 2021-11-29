/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 17:09:32 by alsanche          #+#    #+#             */
/*   Updated: 2021/11/29 16:39:04 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*chr_min(t_list **stk_a)
{
	int		*chr;
	t_list	*aux;

	chr = malloc(sizeof(int) * 2);
	chr[0] = 2147483647;
	chr[1] = chr[0];
	aux = *stk_a;
	while (aux->next)
	{
		if (aux->content < chr[0])
			chr[0] = aux->content;
		else
			aux = aux->next;
	}
	aux = *stk_a;
	while (aux)
	{
		if (aux->content < chr[1] && aux->content != chr[0])
			chr[1] = aux->content;
		else
			aux = aux->next;
	}
	return (chr);
}

void	ft_solu(t_list **stack_a, t_list **stack_b)
{
	int	points;

	if (i_got_it(stack_a) == 1)
		return ;
	points = ft_lstsize(*stack_a);
	if (points == 2)
		ft_result_2(stack_a);
	else if (points == 3)
		ft_result_3(stack_a);
	else if (points == 4)
		ft_result_4(stack_a, stack_b, points);
	else if (points == 5)
		ft_result_5(stack_a, stack_b, 0);
	return ;
}
