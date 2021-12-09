/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 15:59:16 by alsanche          #+#    #+#             */
/*   Updated: 2021/12/09 11:15:57 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_result_2(t_list **stk_a)
{
	t_list	*aux;

	aux = *stk_a;
	if (aux->content > aux->next->content)
		swap(stk_a, stk_a, 0);
	return ;
}

void	ft_result_3(t_list **stk)
{
	if ((*stk)->content > (*stk)->next->content)
	{
		if ((*stk)->content < (*stk)->next->next->content)
			swap(stk, stk, 0);
		else if ((*stk)->next->content > (*stk)->next->next->content)
		{
			swap(stk, stk, 0);
			rrr(stk, stk, 0);
		}
		else if ((*stk)->next->content < (*stk)->next->next->content)
			rr(stk, stk, 0);
	}
	else if ((*stk)->content < (*stk)->next->content)
	{
		if ((*stk)->content > (*stk)->next->next->content)
			rrr(stk, stk, 0);
		else if ((*stk)->next->content > (*stk)->next->next->content)
		{
			swap(stk, stk, 0);
			rr(stk, stk, 0);
		}
	}
}

void	ft_result_4(t_list **stk_a, t_list **stk_b, int n)
{
	t_list	*aux;
	int		*chr;

	chr = chr_min(stk_a);
	while (n > 0)
	{
		aux = *stk_a;
		if (i_got_it(stk_a) == 1)
			return ;
		if (aux->content == chr[0])
		{
			push(stk_a, stk_b, 0);
			break ;
		}
		else
			rr(stk_a, stk_b, 0);
		n--;
	}
	ft_result_3(stk_a);
	push(stk_a, stk_b, 1);
	free(chr);
}

void	ft_result_5(t_list **stk_a, t_list **stk_b, int n)
{
	t_list	*aux;
	int		*chr;

	chr = chr_min(stk_a);
	while (n < 2)
	{
		aux = *stk_a;
		if (i_got_it(stk_a) == 1 && (*stk_b) == NULL)
			return ;
		if (aux->content == chr[0] || aux->content == chr[1])
		{
			push(stk_a, stk_b, 0);
			n++;
		}
		else
			rr(stk_a, stk_b, 0);
	}
	ft_result_3(stk_a);
	aux = *stk_b;
	if (aux->content < aux->next->content)
		swap(stk_a, stk_b, 1);
	push(stk_a, stk_b, 1);
	push(stk_a, stk_b, 1);
	free(chr);
}
