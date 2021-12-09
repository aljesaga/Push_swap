/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:40:55 by alsanche          #+#    #+#             */
/*   Updated: 2021/12/09 12:20:01 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_err(int active)
{
	if (active == 1)
	{
		write(1, "Error\n", 6);
		exit (-1);
	}
}

int	error(long atoi)
{
	if (atoi < INT_MIN || atoi > INT_MAX)
		print_err(1);
	return (1);
}

int	same_num(t_list **stk_a)
{
	t_list	*aux;
	t_list	*temp;

	aux = *stk_a;
	if (!stk_a || aux == NULL)
		return (0);
	while (aux->next)
	{
		temp = aux->next;
		while (temp)
		{
			if (aux->content == temp->content)
				print_err(1);
			temp = temp->next;
		}
		aux = aux->next;
	}
	return (42);
}

int	i_got_it(t_list **stack)
{
	t_list	*aux;

	aux = *stack;
	if (!aux)
		return (1);
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
