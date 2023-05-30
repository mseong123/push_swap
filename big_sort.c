/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:19:28 by melee             #+#    #+#             */
/*   Updated: 2023/05/30 13:12:55 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	find_top_bottom(int pos[2], t_list *s_a, t_list *s_b, t_operations *ptr)
{
	if (pos[0] <= (ft_lstsize(s_a) / 2) && pos[1] <= (ft_lstsize(s_b) / 2))
	{
		upper_half(pos, ptr);
		compare_operations(ptr);
	}
	else if (pos[0] > (ft_lstsize(s_a) / 2) && pos[1] > (ft_lstsize(s_b) / 2))
	{	
		pos[0] = ft_lstsize(s_a) - pos[0];
		pos[1] = ft_lstsize(s_b) - pos[1];
		bottom_half(pos, ptr);
		compare_operations(ptr);
	}
	else if (pos[0] <= (ft_lstsize(s_a) / 2) && pos[1] > (ft_lstsize(s_b) / 2))
	{
		pos[1] = ft_lstsize(s_b) - pos[1];
		mix1(pos, ptr);
		compare_operations(ptr);
	}	
	else if (pos[0] > (ft_lstsize(s_a) / 2) && pos[1] <= (ft_lstsize(s_b) / 2))
	{
		pos[0] = ft_lstsize(s_a) - pos[0];
		mix2(pos, ptr);
		compare_operations(ptr);
	}
}

void	count_max_min(t_list *stack_a, t_list *stack_b, t_operations *ptr)
{
	int		pos[2];
	t_list	*node;

	node = stack_a;
	while (node && stack_b)
	{
		if (find_max_or_min(ft_atoi(node->content), stack_b))
		{
			pos[0] = count_pos(ft_atoi(node->content), stack_a);
			pos[1] = count_pos(find_max(stack_b), stack_b);
			find_top_bottom(pos, stack_a, stack_b, ptr);
		}
		node = node->next;
	}
}

void	count_in_between(t_list *stack_a, t_list *stack_b, t_operations *ptr)
{
	int		pos[2];
	t_list	*node;

	node = stack_a;
	while (node && stack_b)
	{
		if (!find_max_or_min(ft_atoi(node->content), stack_b))
		{
			pos[0] = count_pos(ft_atoi(node->content), stack_a);
			pos[1] = count_pos(find_prev(ft_atoi(node->content), stack_b),
					stack_b);
			find_top_bottom(pos, stack_a, stack_b, ptr);
		}
		node = node->next;
	}
}

void	big_sort(t_list **stack_a, t_list **stack_b)
{
	t_operations	*ptr;
	int				max_b;

	ptr = init();
	while (*stack_a)
	{
		count_max_min(*stack_a, *stack_b, ptr);
		count_in_between(*stack_a, *stack_b, ptr);
		exec_ops(stack_a, stack_b, ptr);
	}
	max_b = find_max(*stack_b);
	if (count_pos(max_b, *stack_b) <= ft_lstsize(*stack_b))
		while (ft_atoi((*stack_b)->content) != max_b)
			rb(stack_b, 0);
	else
		while (ft_atoi((*stack_b)->content) != max_b)
			rrb(stack_b, 0);
	while (*stack_b)
		pa(stack_a, stack_b, 0);
	free(ptr);
}
