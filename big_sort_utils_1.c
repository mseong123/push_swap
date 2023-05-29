/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:02:04 by melee             #+#    #+#             */
/*   Updated: 2023/05/29 13:23:12 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_list *stack_b)
{
	int	max;

	max = ft_atoi(stack_b->content);
	stack_b = stack_b->next;
	while (stack_b)
	{
		if (ft_atoi(stack_b->content) > max)
			max = ft_atoi(stack_b->content);
		stack_b = stack_b->next;
	}
	return (max);
}

int	find_min(t_list *stack_b)
{
	int	min;

	min = ft_atoi(stack_b->content);
	stack_b = stack_b->next;
	while (stack_b)
	{
		if (ft_atoi(stack_b->content) < min)
			min = ft_atoi(stack_b->content);
		stack_b = stack_b->next;
	}
	return (min);
}

int	find_max_or_min(int value, t_list *stack_b)
{
	if (value < find_min(stack_b) || value > find_max(stack_b))
	{
		return (1);
	}
	return (0);
}

int	count_pos(int value, t_list *stack)
{
	int	pos;

	pos = 0;
	while (ft_atoi(stack->content) != value)
	{
		stack = stack->next;
		pos++;
	}
	return (pos);
}

int	find_prev(int value, t_list *stack_b)
{
	int	prev_value;

	prev_value = find_min(stack_b);
	while (stack_b)
	{
		if (ft_atoi(stack_b->content) > prev_value
			&& ft_atoi(stack_b->content) < value)
		{
			prev_value = ft_atoi(stack_b->content);
		}
		stack_b = stack_b->next;
	}
	return (prev_value);
}
