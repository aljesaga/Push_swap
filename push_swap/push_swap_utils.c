/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:01:34 by alsanche          #+#    #+#             */
/*   Updated: 2021/11/22 18:06:38 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_a_b(t_list *stk)
{
	int	aux;

	aux = stk->next->num;
	stk->next->num = stk->num;
	stk->num = aux;
}

void	swap(t_list *stk_a, t_list *stk_b, int check)
{
	if (check == 0)
	{
		s_a_b(stk_a);
		write(1, "sa\n", 3);
	}
	else if (check == 1)
	{
		s_a_b(stk_b);
		write(1, "sb\n", 3);
	}
	else if (check == 2)
	{
		s_a_b(stk_a);
		s_a_b(stk_b);
		write(1, "ss\n", 3);
	}
}

void	push(t_list *stk_a, t_list *stk_b, int check)
{
	t_list	*aux;

	if (check == 0)
	{
		stk_b->next = stk_a->next;
		stk_b->next->next = NULL;
		stk_a = stk_a->next;
		write (1, "pa\n", 3);
	}
	else
	{
		aux = stk_a;
		stk_a = stk_b;
		stk_a->next = aux;
		stk_b = stk_b->next;
		write (1, "pb\n", 3);
	}
}

void	r_a_b(t_list *stk)
{
	t_list	*aux;

	aux = stk;
	while (stk->next)
	{
		*stk = *stk->next;
		stk->next = stk->next;
	}
	*stk->next = *aux;
}

void	rr(t_list *stk_a, t_list *stk_b, int check)
{
	if (check == 0)
	{
		r_a_b(stk_a);
		write(1, "ra\n", 3);
	}
	else if (check == 1)
	{
		r_a_b(stk_b);
		write(1, "rb\n", 3);
	}
	else if (check == 3)
	{
		r_a_b(stk_a);
		r_a_b(stk_b);
		write(1, "rr\n", 3);
	}
}
