/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solution_100_500.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:52:34 by alsanche          #+#    #+#             */
/*   Updated: 2021/12/09 13:57:14 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*chr_max(t_list **stk)
{
	t_list	*aux;
	int		*chr;

	chr = malloc(sizeof(int) * 2);
	if (!chr)
		return (0);
	chr[0] = 0;
	chr[1] = INT_MIN;
	aux = *stk;
	while (aux)
	{
		if (aux->content > chr[1])
			chr[1] = aux->content;
		chr[0] += 1;
		aux = aux->next;
	}
	return (chr);
}

void	send_to_rr(t_list **stk_a, t_list **stk_b, int check, int i)
{
	t_list	*aux;

	if (check == 0)
		aux = *stk_a;
	else
		aux = *stk_b;
	while (aux)
	{
		if (check == 0)
			aux = *stk_a;
		else
			aux = *stk_b;
		if (aux->content == i)
		{
			push(stk_a, stk_b, check);
			break ;
		}
		rr(stk_a, stk_b, check);
	}
}

void	send_to_rrr(t_list **stk_a, t_list **stk_b, int check, int i)
{
	t_list	*aux;

	if (check == 0)
		aux = *stk_a;
	else
		aux = *stk_b;
	while (aux)
	{
		if (check == 0)
			aux = *stk_a;
		else
			aux = *stk_b;
		if (aux->content == i)
		{
			push(stk_a, stk_b, check);
			break ;
		}
		rrr(stk_a, stk_b, check);
	}
}

int	*nbr_2_push(t_list **stk, int min, int max)
{
	int		*i;
	t_list	*aux;

	i = malloc(sizeof(int) * 2);
	if (!i)
		return (0);
	aux = *stk;
	i[0] = 0;
	while (aux)
	{
		if (aux->content >= min && aux->content <= max)
		{
			i[1] = aux->content;
			return (i);
		}
		else
		{
			aux = aux->next;
			i[0]++;
		}
	}
	return (i);
}

void	ft_result_100(t_list **stk_a, t_list **stk_b, int points)
{
	int	*i;
	int	min;
	int	max;

	max = 19;
	min = 0;
	while (max <= points)
	{
		while (min++ < max)
		{
			i = nbr_2_push(stk_a, min, max);
			if (i[0] < points / 2)
				send_to_rr(stk_a, stk_b, 0, i[1]);
			else
				send_to_rrr(stk_a, stk_b, 0, i[1]);
		}
		while (*stk_b)
		{
			i = chr_max(stk_b);
			if (i[0] < points / 2)
				send_to_rr(stk_a, stk_b, 1, i[1]);
			else
				send_to_rrr(stk_a, stk_b, 1, i[1]);
		}
		if (i_got_it(stk_a) == 1)
			break ;
		max += 20;
	}
}
