/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:09:51 by alsanche          #+#    #+#             */
/*   Updated: 2021/11/29 12:16:35 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_a_b(t_list **stk)
{
	t_list	*aux;
	t_list	*sig;

	sig = *stk;
	while (sig->next->next)
	{
		sig = sig->next;
	}
	aux = sig->next;
	aux->next = *stk;
	(*stk) = aux;
	sig->next = NULL;
}

void	rrr(t_list **stk_a, t_list **stk_b, int check)
{
	if (check == 0)
	{
		rr_a_b(stk_a);
		write(1, "rra\n", 4);
	}
	else if (check == 1)
	{
		rr_a_b(stk_b);
		write(1, "rrb\n", 4);
	}
	else if (check == 2)
	{
		rr_a_b(stk_a);
		rr_a_b(stk_b);
		write(1, "rrr\n", 4);
	}
}

long	ft_atoi_push(const char *a)
{
	long long	n;
	long long	sig;

	n = 0;
	sig = 1;
	while ((*a == 32) || (*a >= 9 && *a <= 13))
		a++;
	if (*a == 45)
		sig = -1;
	if (*a == 43 || *a == 45)
		a++;
	while (*a >= 48 && *a <= 57)
	{
		if ((n * sig) > 2147483647)
			return (-1);
		else if ((n * sig) < -2147483648)
			return (0);
		n = n * 10 + *a - 48;
		a++;
	}
	if (*a != '\0')
		return (-2147483649);
	return (n * sig);
}
