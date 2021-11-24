/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:02:20 by alsanche          #+#    #+#             */
/*   Updated: 2021/11/24 17:08:05 by aviscogl         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_list(char *arv, t_list *stack_a, int arn)
{
	char		**aux;
	long		nbr;
	t_list		*newpoint;
	int			i;

	i = -1;
	aux = ft_split(arv, ' ');
	while (aux[++i])
	{
		nbr = ft_atoi_push(aux[i]);
		if (error(nbr) == 0)
			return ;
		if (arn == 1 && i == 0)
			stack_a = ft_lstnew(nbr);
		else
			newpoint = ft_lstnew(nbr);
			ft_add_back(stack_a, newpoint);
	}
	free(aux);
}

void	print_list(t_list *print)
{
	t_list	*stack;

	stack = print;
	while (stack)
	{
		printf("%p\n", stack->content);
		stack = stack->next;
	}
}

int	main(int arc, char **arv)
{
	int		i;
	t_list	stack_a;
	t_list	stack_b;

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
	same_num(&stack_a);
	ft_solu( &stack_a, &stack_b);
	return (0);
}
