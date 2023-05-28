/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:19:28 by melee             #+#    #+#             */
/*   Updated: 2023/05/28 14:53:44 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int	find_max(t_list *stackB)
{
	int	max;

	max = ft_atoi(stackB->content);
	stackB = stackB->next;
	while (stackB)
	{
		if (ft_atoi(stackB->content) > max)
			max = ft_atoi(stackB->content);
		stackB = stackB->next;
	}
	return (max);
}

int	find_min(t_list *stackB)
{
	int	min;

	min = ft_atoi(stackB->content);
	stackB = stackB->next;
	while (stackB)
	{
		if (ft_atoi(stackB->content) < min)
			min = ft_atoi(stackB->content);
		stackB = stackB->next;
	}
	return (min);
}

void ft_printf1(void *content)
{
	printf("%s\n",content);
}

void	ft_lstiterbackwards1(t_list *lst, void (*f)(void *))
{
	t_list	*node;

	if (lst && f)
	{
		node = lst;
		while (node)
		{
			f(node->content);
			node = node->prev;
		}
	}
}

int	find_max_or_min(int value, t_list *stackB)
{
	if (value < find_min(stackB) || value > find_max(stackB))
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

void	execute_operations(t_list **stackA, t_list **stackB, t_operations *ptr)
{
		while (ptr->ra)
		{
			ra(stackA);
			ptr->ra--;
		}	
		while (ptr->rb)
		{
			rb(stackB);
			ptr->rb--;
		}
		while (ptr->rra)
		{
			rra(stackA);
			ptr->rra--;
		}
		while (ptr->rrb)
		{
			rrb(stackB);
			ptr->rrb--;
		}
		while (ptr->rr)
		{
			rr(stackA, stackB);
			ptr->rr--;
		}
		while (ptr->rrr)
		{
			rrr(stackA, stackB);
			ptr->rrr--;
		}
		pb(stackA, stackB);
		ptr->first_time = 1;

}

void	upper_half(int	targetA, int targetB, t_operations *ptr)
{
		if (targetA > targetB)
		{
			ptr->temp_rr = targetB;
			ptr->temp_ra = targetA - targetB;
		 }
		else 
		{
			ptr->temp_rr = targetA;
			ptr->temp_rb = targetB - targetA;
		}
}

void	bottom_half(int	targetA, int targetB, t_operations *ptr)
{
		if (targetA > targetB)
		{
			ptr->temp_rrr = targetB;
			ptr->temp_rra = targetA - targetB;
		 }
		else 
		{
			ptr->temp_rrr = targetA;
			ptr->temp_rrb = targetB - targetA;
		}
}

void	mix1(int	targetA, int targetB, t_operations *ptr)
{
		ptr->temp_ra = targetA;
		ptr->temp_rrb = targetB;
}

void	mix2(int	targetA, int targetB, t_operations *ptr)
{
		ptr->temp_rra = targetA;
		ptr->temp_rb = targetB;
}



void	count_max_min(t_list *stackA, t_list *stackB, t_operations *ptr)
{
	int	targetA;
	int targetB;
	t_list *node;

	node = stackA;
	while (node && stackB)
	{

		if (find_max_or_min(ft_atoi(node->content), stackB))
		{	
			targetA = count_pos_stack(ft_atoi(node->content), stackA);
			targetB = count_pos_stack(find_max(stackB), stackB);
			if (targetA <= (ft_lstsize(stackA) / 2) && targetB <= (ft_lstsize(stackB) / 2))
			{
				upper_half(targetA, targetB, ptr);
				compare_operations(ptr);
			}
			else if (targetA > (ft_lstsize(stackA) / 2) && targetB > (ft_lstsize(stackB) / 2))
			{
				targetA = ft_lstsize(stackA) - targetA;
				targetB = ft_lstsize(stackB) - targetB;
				bottom_half(targetA, targetB, ptr);
				compare_operations(ptr);
			}
			else if (targetA <= (ft_lstsize(stackA) / 2) && targetB > (ft_lstsize(stackB) / 2))
			{
				targetB = ft_lstsize(stackB) - targetB;
				mix1(targetA, targetB, ptr);
				compare_operations(ptr);
			}
			
			else if (targetA > (ft_lstsize(stackA) / 2) && targetB <= (ft_lstsize(stackB) / 2))
			{
				targetA = ft_lstsize(stackA) - targetA;
				mix2(targetA, targetB, ptr);
				compare_operations(ptr);
			}
		}

		node = node->next;
	}	
}


void	sort(t_list **stackA, t_list **stackB)
{
	t_operations *ptr;
	int i = 0;
	int	max = 30;

	ptr = init();

	//pb(stackA, stackB);

	while (i < max && *stackA)
	{
		count_max_min(*stackA, *stackB, ptr);
		execute_operations(stackA, stackB, ptr);
		i++;
	}
	
	   		
/*	
		printf("ra %d\n", ptr->ra);
	printf("rb %d\n", ptr->rb);
	printf("rra %d\n", ptr->rra);
	printf("rrb %d\n", ptr->rrb);
	printf("rr %d\n", ptr->rr);
	printf("rrr %d\n", ptr->rrr);

	printf("temp ra %d\n", ptr->temp_ra);
	printf("temp rb %d\n", ptr->temp_rb);
	printf("temp rra %d\n", ptr->temp_rra);
	printf("temp rrb %d\n", ptr->temp_rrb);
	printf("temp rr %d\n", ptr->temp_rr);
	printf("temp rrr %d\n", ptr->temp_rrr);

*/
	printf("stackA\n");
	ft_lstiter(*stackA, ft_printf1);
	printf("stackB\n");
	ft_lstiter(*stackB, ft_printf1);


	
	
				




}

