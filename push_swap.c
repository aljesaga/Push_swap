/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/11 16:02:20 by alsanche          #+#    #+#             */
/*   Updated: 2021/12/11 16:28:31 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_to_list(char *arv, t_list **stack_a)
{
	char		**aux;
	long		nbr;
	t_list		*newpoint;
	int			i;

	i = -1;
	aux = ft_split(arv, ' ');
	while (aux[++i])
	{
		if (aux[0] == '\0')
			exit (-1);
		nbr = ft_atoi_push(aux[i]);
		if (error(nbr) == 0)
			exit (-1);
		newpoint = ft_lstnew(nbr);
		ft_lstadd_back(stack_a, newpoint);
		free(aux[i]);
	}
	free(aux);
}

void	print_list(t_list *print)
{
	t_list	*stack;

	stack = print;
	while (stack)
	{
		printf("%d\n", stack->content);
		stack = stack->next;
	}
}

int	main(int arc, char **arv)
{
	int		i;
	t_list	*stack_a;
	t_list	*stack_b;

	if (arc < 2 )
		return (0);
	i = 1;
	while (i < arc)
	{
		add_to_list(arv[i], &stack_a);
		i++;
	}
	same_num(&stack_a);
	stack_b = NULL;
	ft_solu(&stack_a, &stack_b);
	clean_stack(&stack_a);
	return (0);
}
