/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:40:55 by alsanche          #+#    #+#             */
/*   Updated: 2021/11/22 15:41:21 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	error(long atoi)
{
	if (atoi < INT_MIN || atoi > INT_MAX)
	{
		write(1, "Error\n", 7);
		return (0);
	}
	return (1);
}

int	same_num(t_stack *stk_a)
{
	int	aux;

	while (stk_a)
	{
		aux = stk_a->num;
		while (stk_a->next)
		{
			if (aux == stk_a->next->num)
			{
				write(1, "Error\n", 1);
				return (0);
			}
			else
				stk_a = stk_a->next;
		}
		stk_a = stk_a->next;
	}
	return (42);
}

void	clean_stack(t_stack **stack)
{
	t_stack	*aux;

	while (*stack)
	{
		aux = (*stack)->next;
		(*stack)->num = 0;
		free(*stack);
		(*stack) = aux;
	}
	*stack = NULL;
}
