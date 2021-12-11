/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_solution_100_500.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 10:52:34 by alsanche          #+#    #+#             */
/*   Updated: 2021/12/11 16:08:25 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	swap_selec(t_list **stk_a, t_list **stk_b, int i, int con)
{
	if (i == 1 && con > 2 && (*stk_b)->content < (*stk_b)->next->content)
		swap(stk_a, stk_b, 2);
	else if (i == 1)
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
		swap_selec(stk_a, stk_b, i[0], con);
		if (i[0] < (ft_lstsize(*stk_a) / 2))
			send_to_rr(stk_a, stk_b, 0, i[1]);
		else
			send_to_rrr(stk_a, stk_b, 0, i[1]);
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
			send_to_rr(stk_a, stk_b, 1, i[1]);
		else
			send_to_rrr(stk_a, stk_b, 1, i[1]);
		free(i);
	}
}
