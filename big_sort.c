/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:19:28 by melee             #+#    #+#             */
/*   Updated: 2023/05/29 12:29:10 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

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

void ft_printf1(void *content)
{
	printf("%s\n",content);
}

int	find_max_or_min(int value, t_list *stack_b)
{
	if (value < find_min(stack_b) || value > find_max(stack_b))
	{
		return (1);
	}
	return (0);
}

int	count_pos_stack(int value, t_list *stack)
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

t_operations	*init(void)
{
	t_operations *ptr;

	ptr = (t_operations *)malloc(sizeof(t_operations));
	if (!ptr)
		return (NULL);
	ptr->ra = 0;
	ptr->rb = 0;
	ptr->rra = 0;
	ptr->rrb = 0;
	ptr->rr = 0;
	ptr->rrr = 0;
	ptr->temp_ra = 0;
	ptr->temp_rb = 0;
	ptr->temp_rra = 0;
	ptr->temp_rrb = 0;
	ptr->temp_rr = 0;
	ptr->temp_rrr = 0;
	ptr->first_time = 1;
	return (ptr);
}

void	reset_temp(t_operations *ptr)
{
	ptr->temp_ra = 0;
	ptr->temp_rb = 0;
	ptr->temp_rra = 0;
	ptr->temp_rrb = 0;
	ptr->temp_rr = 0;
	ptr->temp_rrr = 0;
}

void	compare_operations(t_operations *ptr)
{
	int current_total;
	int temp_total;

	current_total = ptr->ra + ptr->rb + ptr->rra + ptr->rrb + ptr->rr + ptr-> rrr;
	temp_total = ptr->temp_ra + ptr->temp_rb + ptr->temp_rra + ptr->temp_rrb + ptr->temp_rr + ptr-> temp_rrr;
	if (ptr->first_time)
	{
		ptr->ra = ptr->temp_ra;
		ptr->rb = ptr->temp_rb;
		ptr->rra = ptr->temp_rra;
		ptr->rrb = ptr->temp_rrb;
		ptr->rr = ptr->temp_rr;
		ptr->rrr = ptr->temp_rrr;
		ptr->first_time = 0;
	}
	else if (temp_total < current_total)
	{
		ptr->ra = ptr->temp_ra;
		ptr->rb = ptr->temp_rb;
		ptr->rra = ptr->temp_rra;
		ptr->rrb = ptr->temp_rrb;
		ptr->rr = ptr->temp_rr;
		ptr->rrr = ptr->temp_rrr;
	}	
	reset_temp(ptr);
}

void	execute_operations(t_list **stack_a, t_list **stack_b, t_operations *ptr)
{
		while (ptr->ra)
		{
			ra(stack_a, 0);
			ptr->ra--;
		}	
		while (ptr->rb)
		{
			rb(stack_b, 0);
			ptr->rb--;
		}
		while (ptr->rra)
		{
			rra(stack_a, 0);
			ptr->rra--;
		}
		while (ptr->rrb)
		{
			rrb(stack_b, 0);
			ptr->rrb--;
		}
		while (ptr->rr)
		{
			rr(stack_a, stack_b);
			ptr->rr--;
		}
		while (ptr->rrr)
		{
			rrr(stack_a, stack_b);
			ptr->rrr--;
		}
		pb(stack_a, stack_b);
		ptr->first_time = 1;

}

void	upper_half(int	target_a, int target_b, t_operations *ptr)
{
		if (target_a > target_b)
		{
			ptr->temp_rr = target_b;
			ptr->temp_ra = target_a - target_b;
		 }
		else 
		{
			ptr->temp_rr = target_a;
			ptr->temp_rb = target_b - target_a;
		}
}

void	bottom_half(int	target_a, int target_b, t_operations *ptr)
{
		if (target_a > target_b)
		{
			ptr->temp_rrr = target_b;
			ptr->temp_rra = target_a - target_b;
		 }
		else 
		{
			ptr->temp_rrr = target_a;
			ptr->temp_rrb = target_b - target_a;
		}
}

void	mix1(int	target_a, int target_b, t_operations *ptr)
{
		ptr->temp_ra = target_a;
		ptr->temp_rrb = target_b;
}

void	mix2(int	target_a, int target_b, t_operations *ptr)
{
		ptr->temp_rra = target_a;
		ptr->temp_rb = target_b;
}



void	count_max_min(t_list *stack_a, t_list *stack_b, t_operations *ptr)
{
	int	target_a;
	int target_b;
	t_list *node;

	node = stack_a;
	while (node && stack_b)
	{

		if (find_max_or_min(ft_atoi(node->content), stack_b))
		{	
			target_a = count_pos_stack(ft_atoi(node->content), stack_a);
			target_b = count_pos_stack(find_max(stack_b), stack_b);
			if (target_a <= (ft_lstsize(stack_a) / 2) && target_b <= (ft_lstsize(stack_b) / 2))
			{
				upper_half(target_a, target_b, ptr);
				compare_operations(ptr);
			}
			else if (target_a > (ft_lstsize(stack_a) / 2) && target_b > (ft_lstsize(stack_b) / 2))
			{
				target_a = ft_lstsize(stack_a) - target_a;
				target_b = ft_lstsize(stack_b) - target_b;
				bottom_half(target_a, target_b, ptr);
				compare_operations(ptr);
			}
			else if (target_a <= (ft_lstsize(stack_a) / 2) && target_b > (ft_lstsize(stack_b) / 2))
			{
				target_b = ft_lstsize(stack_b) - target_b;
				mix1(target_a, target_b, ptr);
				compare_operations(ptr);
			}
			
			else if (target_a > (ft_lstsize(stack_a) / 2) && target_b <= (ft_lstsize(stack_b) / 2))
			{
				target_a = ft_lstsize(stack_a) - target_a;
				mix2(target_a, target_b, ptr);
				compare_operations(ptr);
			}
		}

		node = node->next;
	}	
}

int	find_prev_value(int	value, t_list *stack_b)
{
	int	prev_value;
	
	prev_value = find_min(stack_b);
	while (stack_b)
	{
		if (ft_atoi(stack_b->content) > prev_value && ft_atoi(stack_b->content) < value)
		{
			prev_value = ft_atoi(stack_b->content);
		}
		stack_b = stack_b->next;
	}
	return (prev_value);
}

void	count_in_between(t_list *stack_a, t_list *stack_b, t_operations *ptr)
{
	int	target_a;
	int target_b;
	t_list *node;

	node = stack_a;
	while (node && stack_b)
	{
		if (!find_max_or_min(ft_atoi(node->content), stack_b))
		{
			target_a = count_pos_stack(ft_atoi(node->content), stack_a);
			target_b = count_pos_stack(find_prev_value(ft_atoi(node->content), stack_b), stack_b);
			if (target_a <= (ft_lstsize(stack_a) / 2) && target_b <= (ft_lstsize(stack_b) / 2))
			{
				upper_half(target_a, target_b, ptr);
				compare_operations(ptr);
			}
			else if (target_a > (ft_lstsize(stack_a) / 2) && target_b > (ft_lstsize(stack_b) / 2))
			{
				target_a = ft_lstsize(stack_a) - target_a;
				target_b = ft_lstsize(stack_b) - target_b;
				bottom_half(target_a, target_b, ptr);
				compare_operations(ptr);
			}
			else if (target_a <= (ft_lstsize(stack_a) / 2) && target_b > (ft_lstsize(stack_b) / 2))
			{
				target_b = ft_lstsize(stack_b) - target_b;
				mix1(target_a, target_b, ptr);
				compare_operations(ptr);
			}
			
			else if (target_a > (ft_lstsize(stack_a) / 2) && target_b <= (ft_lstsize(stack_b) / 2))
			{

				target_a = ft_lstsize(stack_a) - target_a;
				mix2(target_a, target_b, ptr);
				compare_operations(ptr);
			}
		}
		node = node->next;
	}


}


void	big_sort(t_list **stack_a, t_list **stack_b)
{
	t_operations *ptr;
	int	max_b;

	ptr = init();
	while (*stack_a)
	{
		count_max_min(*stack_a, *stack_b, ptr);
		count_in_between(*stack_a, *stack_b, ptr);
		execute_operations(stack_a, stack_b, ptr);
	}
	max_b = find_max(*stack_b);
	if (count_pos_stack(max_b, *stack_b) <= ft_lstsize(*stack_b))
		while (ft_atoi((*stack_b)->content) != max_b)
			rb(stack_b, 0);
	else
		while (ft_atoi((*stack_b)->content) != max_b)
			rrb(stack_b, 0);
	while(*stack_b)
		pa(stack_a, stack_b);

/*
	printf("stackA\n");
	ft_lstiter(*stackA, ft_printf1);
	printf("stackB\n");
	ft_lstiter(*stackB, ft_printf1);
*/




}

