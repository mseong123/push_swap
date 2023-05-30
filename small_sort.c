/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 15:41:33 by melee             #+#    #+#             */
/*   Updated: 2023/05/30 13:14:27 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_list **stack_a)
{
	if (!sorted(*stack_a))
	{
		if (ft_lstsize(*stack_a) == 2)
			sa(*stack_a, 0);
		else if (ft_atoi((*stack_a)->content) == find_max(*stack_a)
			&& ft_atoi(ft_lstlast(*stack_a)->content) == find_min(*stack_a))
		{
			sa(*stack_a, 0);
			rra(stack_a, 0);
		}
		else if (ft_atoi((*stack_a)->content) == find_min(*stack_a))
		{
			sa(*stack_a, 0);
			ra(stack_a, 0);
		}
		else if (ft_atoi((*stack_a)->content) == find_max(*stack_a))
			ra(stack_a, 0);
		else if (ft_atoi(ft_lstlast(*stack_a)->content) == find_max(*stack_a))
			sa(*stack_a, 0);
		else if (ft_atoi(ft_lstlast(*stack_a)->content) == find_min(*stack_a))
			rra(stack_a, 0);
	}
}

void	sort_4(t_list **stack_a, t_list **stack_b)
{
	while (ft_atoi((*stack_a)->content) != find_max(*stack_a))
	{
		if (count_pos(find_max(*stack_a), *stack_a) < ft_lstsize(*stack_a))
			ra(stack_a, 0);
		else
			rra(stack_a, 0);
	}
	pb(stack_a, stack_b, 0);
	sort_3(stack_a);
	pa(stack_a, stack_b, 0);
	ra(stack_a, 0);
}

void	sort_5(t_list **s_a, t_list **s_b)
{
	int	prev;

	prev = find_prev(find_max(*s_a), *s_a);
	while (ft_atoi((*s_a)->content) != prev)
	{
		if (count_pos(prev, *s_a) <= ft_lstsize(*s_a) / 2)
			ra(s_a, 0);
		else
			rra(s_a, 0);
	}
	pb(s_a, s_b, 0);
	while (ft_atoi((*s_a)->content) != find_max(*s_a))
	{
		if (count_pos(find_max(*s_a), *s_a) <= ft_lstsize(*s_a) / 2)
			ra(s_a, 0);
		else
			rra(s_a, 0);
	}
	pb(s_a, s_b, 0);
	sort_3(s_a);
	pa(s_a, s_b, 0);
	pa(s_a, s_b, 0);
	ra(s_a, 0);
	ra(s_a, 0);
}

void	small_sort(t_list **stack_a, t_list **stack_b)
{
	int	size_a;

	size_a = ft_lstsize(*stack_a);
	if (size_a <= 3)
		sort_3(stack_a);
	else if (size_a == 4)
		sort_4(stack_a, stack_b);
	else
		sort_5(stack_a, stack_b);
}
