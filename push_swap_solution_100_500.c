/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solution_100_500.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:52:34 by alsanche          #+#    #+#             */
/*   Updated: 2021/12/16 15:11:25 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	send_to_rr(t_list **stk_a, t_list **stk_b, int check, int *i)
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
		if (aux->content == i[1])
		{
			push(stk_a, stk_b, check);
			break ;
		}
		if (check == 0 && i[2] > 2
			&& (*stk_b)->content < ft_lstlast(*stk_b)->content)
			rr(stk_a, stk_b, 2);
		else
			rr(stk_a, stk_b, check);
	}
}

void	send_to_rrr(t_list **stk_a, t_list **stk_b, int check, int *i)
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
		if (aux->content == i[1])
		{
			push(stk_a, stk_b, check);
			break ;
		}
		if (check == 0 && i[2] > 2
			&& ft_lstlast(*stk_b)->content > (*stk_b)->content)
			rrr(stk_a, stk_b, 2);
		else
			rrr(stk_a, stk_b, check);
	}
}

void	swap_selec(t_list **stk_a, t_list **stk_b, int *i)
{
	if (i[0] == 1 && i[2] > 2 && (*stk_b)->content < (*stk_b)->next->content)
		swap(stk_a, stk_b, 2);
	else if (i[0] == 1)
		swap(stk_a, stk_b, 0);
}

void	send_a(t_list **stk_a, t_list **stk_b, int *min)
{
	int	*i;
	int	con;

	con = 0;
	while (con < min[2])
	{
		i = selec_nbr(stk_a, min);
		i[2] = con;
		swap_selec(stk_a, stk_b, i);
		if (i[0] < (ft_lstsize(*stk_a) / 2))
			send_to_rr(stk_a, stk_b, 0, i);
		else
			send_to_rrr(stk_a, stk_b, 0, i);
		free(i);
		con++;
	}
}

void	send_b(t_list **stk_a, t_list **stk_b)
{
	int	*i;

	while (*stk_b)
	{
		i = chr_max(stk_b);
		if (i[0] == 1 && (*stk_b)->next)
			swap(stk_a, stk_b, 1);
		if (i[0] < (ft_lstsize(*stk_b) / 2))
			send_to_rr(stk_a, stk_b, 1, i);
		else
			send_to_rrr(stk_a, stk_b, 1, i);
		free(i);
	}
}
