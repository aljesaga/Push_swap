/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:40:55 by alsanche          #+#    #+#             */
/*   Updated: 2021/11/24 17:11:27 by aviscogl         ###   ########lyon.fr   */
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
