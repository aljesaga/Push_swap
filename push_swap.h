/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alsanche <alsanche@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 16:35:34 by alsanche          #+#    #+#             */
/*   Updated: 2021/11/29 16:40:02 by alsanche         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

# define PUSH_SWAP_H

# define INT_MIN -2147483648
# define INT_MAX 2147483647

# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>

/* push_swap */
int		main(int arc, char **arv);
void	add_to_list(char *arv, t_list **stack_a);

/* push_swap_utils */
void	s_a_b(t_list **stk);
void	swap(t_list **stk_a, t_list **stk_b, int check);
void	push(t_list **stk_a, t_list **stk_b, int check);
void	r_a_b(t_list **stk);
void	rr(t_list **stk_a, t_list **stk_b, int check);

/* push_swap_utils2 */
void	rr_a_b(t_list **stk);
void	rrr(t_list **stk_a, t_list **stk_b, int check);
long	ft_atoi_push(const char *a);

/* push_swap_utils3 */
int		*chr_min(t_list **stk_a);
void	ft_solu(t_list **stack_a, t_list **stack_b);

/* push_swap_error */
int		error(long atoi);
int		same_num(t_list *stk_a);
int		i_got_it(t_list **stack);
void	clean_stack(t_list **stack);

/* push_swap_solution */
void	ft_result_2(t_list **stk_a);
void	ft_result_3(t_list **stk_a);
void	ft_result_4(t_list **stk_a, t_list **stk_b, int n);
void	ft_result_5(t_list **stk_a, t_list **stk_b, int n);

/* quitar antes de entregar */

void    print_list(t_list *print);

#endif
