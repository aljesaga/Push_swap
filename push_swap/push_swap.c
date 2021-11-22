/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:02:20 by alsanche          #+#    #+#             */
/*   Updated: 2021/11/22 18:03:57 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_list(char *arv, t_head *stack_a, int arn)
{
	char		**aux;
	long		nbr;
	int			i;

	i = -1;
	aux = ft_split(arv, ' ');
	while (aux[++i])
	{
		nbr = ft_atoi_push(aux[i]);
		if (error(nbr) == 0)
			return ;
		if (arn == 1)
			stack_a = new_stack(nbr);
		else
			add_nbr(stack_a, nbr);
	}
	free(aux);
}

void	print_list(t_head *print)
{
	t_stack	*stack;

	stack = print->one;
	while (stack)
	{
		printf("%d\n", stack->num);
		stack = stack->next;
	}
}

int	main(int arc, char **arv)
{
	int		i;
	t_head	stack_a;
	t_head	stack_b;

	if (arc < 2)
		return (0);
	i = 1;
	arv++;
	while (i < arc)
	{
		add_to_list(*arv, &stack_a, i);
		arv++;
		i++;
	}
	print_list(&stack_a);
	stack_b = *new_stack(0);
	same_num(stack_a.one);
	ft_solu(&stack_a, stack_a.one, stack_b.one);
	return (0);
}
