/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 17:09:51 by alsanche          #+#    #+#             */
/*   Updated: 2021/12/09 13:42:00 by alsanche         ###   ########lyon.fr   */
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

int	*chr_min(t_list **stk_a)
{
	int		*chr;
	t_list	*aux;

	chr = malloc(sizeof(int) * 2);
	chr[0] = INT_MAX;
	chr[1] = chr[0];
	aux = *stk_a;
	while (aux->next)
	{
		if (aux->content < chr[0])
			chr[0] = aux->content;
		else
			aux = aux->next;
	}
	aux = *stk_a;
	while (aux)
	{
		if (aux->content < chr[1] && aux->content != chr[0])
			chr[1] = aux->content;
		else
			aux = aux->next;
	}
	return (chr);
}

void	ft_solu(t_list **stack_a, t_list **stack_b)
{
	int	points;

	if (i_got_it(stack_a) == 1)
		exit (-1);
	points = ft_lstsize(*stack_a);
	ft_map_num(stack_a, points);
	//printf("-------------------");
//	print_list(*stack_a);
	if (points == 2)
		ft_result_2(stack_a);
	else if (points == 3)
		ft_result_3(stack_a);
	else if (points == 4)
		ft_result_4(stack_a, stack_b, points);
	else if (points == 5)
		ft_result_5(stack_a, stack_b, 0);
	else if (points >= 6 && points <= 100)
		ft_result_100(stack_a, stack_b, points);
	return ;
}
