/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 16:01:34 by alsanche          #+#    #+#             */
/*   Updated: 2021/11/26 19:21:28 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	s_a_b(t_list **stk)
{
	int	aux;

	aux = (*stk)->next->content;
	(*stk)->next->content = (*stk)->content;
	(*stk)->content = aux;
}

void	swap(t_list **stk_a, t_list **stk_b, int check)
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
	return ;
}

void	push(t_list **stk_a, t_list **stk_b, int check)
{
	t_list	*aux;
	t_list	*temp;
	t_list	*help;

	aux = *stk_a;
	temp = *stk_b;
	if (check == 0)
	{
		temp = aux;
		temp->next = NULL;
		aux = aux->next;
		write (1, "pa\n", 3);
	}
	else
	{
		help = aux;
		aux = temp;
		aux->next = help;
		temp = temp->next;
		write (1, "pb\n", 3);
	}
}

void	r_a_b(t_list **stk)
{
	t_list	*aux;
	t_list	*temp;

	temp = *stk;
	aux = *stk;
	ft_lstadd_back(stk, temp);
	aux = temp->next;
	temp->next = NULL;
}

void	rr(t_list **stk_a, t_list **stk_b, int check)
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
	else if (check == 2)
	{
		r_a_b(stk_a);
		r_a_b(stk_b);
		write(1, "rr\n", 3);
	}
}
