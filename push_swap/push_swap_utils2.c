/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:09:51 by alsanche          #+#    #+#             */
/*   Updated: 2021/11/22 18:09:41 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr_a_b(t_list *stk)
{
	t_list	*aux;
	t_list	*sig;

	sig = stk;
	while (sig->next->next)
		sig = sig->next;
	aux = sig->next->next;
	sig->next = NULL;
	*aux->next = *stk;
	stk = aux;
}

void	rrr(t_list *stk_a, t_list *stk_b, int check)
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

t_list	*new_stack(int num)
{
	t_list	*stack;
	t_head	*list;

	stack = (t_list *)malloc(sizeof(t_list));
	list = (t_head *)malloc(sizeof(t_head));
	if (!stack || !list)
		return (0);
	stack->num = num;
	stack->next = NULL;
	list->points = 1;
	list->one = stack;
	return (list);
}

void	add_nbr(t_list *stack, long nbr)
{
	t_list	*aux;
	t_list	*newnodo;

	aux = stack->one;
	newnodo = (t_list *)malloc(sizeof(t_list));
	if (!newnodo)
		return ;
	newnodo->num = nbr;
	while (aux)
	{
		if (aux->next == NULL)
			break ;
		aux = aux->next;
	}
	aux->next = newnodo;
	newnodo->next = NULL;
	stack->points++;
}
