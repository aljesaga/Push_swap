/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:40:55 by alsanche          #+#    #+#             */
/*   Updated: 2021/11/29 16:41:21 by alsanche         ###   ########lyon.fr   */
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

int	same_num(t_list *stk_a)
{
	int	aux;

	while (stk_a)
	{
		aux = stk_a->content;
		while (stk_a->next)
		{
			if (aux == stk_a->next->content)
			{
				write(1, "Error\n", 7);
				return (0);
			}
			else
				stk_a = stk_a->next;
		}
		stk_a = stk_a->next;
	}
	return (42);
}

int	i_got_it(t_list **stack)
{
	t_list	*aux;

	aux = *stack;
	while (aux->next)
	{
		if (aux->content < aux->next->content)
			aux = aux->next;
		else
			return (0);
	}
	return (1);
}

void	clean_stack(t_list **stack)
{
	t_list	*aux;

	while (*stack)
	{
		aux = (*stack)->next;
		(*stack)->content = 0;
		free(*stack);
		(*stack) = aux;
	}
	*stack = NULL;
}
