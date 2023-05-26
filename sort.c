/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:19:28 by melee             #+#    #+#             */
/*   Updated: 2023/05/26 18:36:33 by melee            ###   ########.fr       */
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
/*
t_list *get_top(t_list *stack, int n)
{
	i = 0;

	while (i < n)
	{
		stack = stack->next;
		i++;
	}
	return (stack);
}

t_list *get_bottom(t_list **stack, int n)
{

}
*/
int	find_max_or_min(int value, t_list *stackB)
{
	if (value < find_min(stackB) || value > find_max(stackB))
	{
		return (1);
	}
	return (0);
}	

void	sort(t_list **stackA, t_list **stackB)
{
	int i = 16;
	int n = 0;

	//printf("max %d\n",find_max(*stackA));	

	while (ft_lstsize(*stackB)!=2)
		pb(stackA,stackB);

while(n < i)
{
		if (ft_lstsize(*stackA) == 1)
			pb(stackA,stackB);
		else if (ft_atoi((*stackB)->content) == find_max(*stackB) && find_max_or_min(ft_atoi((*stackA)->content), *stackB))
		{
			pb(stackA, stackB);
		}	
		else if (ft_atoi((*stackA)->content) > ft_atoi((*stackB)->content) && ft_atoi((*stackA)->content) < ft_atoi(ft_lstlast(*stackB)->content))
		{
			pb(stackA, stackB);
		}
		else if (find_max_or_min(ft_atoi((*stackA)->content), *stackB) && ft_atoi((*stackB)->next->content) == find_max(*stackB))
		{
			rb(stackB);
		}
		else if (find_max_or_min(ft_atoi((*stackA)->content), *stackB) && ft_atoi(ft_lstlast(*stackB)->content) == find_max(*stackB))
		{
			rrb(stackB);
		}
		else if (find_max_or_min(ft_atoi((*stackA)->next->content), *stackB) && ft_atoi((*stackB)->content) == find_max(*stackB))
		{
			ra(stackA);
		}
		
		else if (find_max_or_min(ft_atoi(ft_lstlast(*stackA)->content), *stackB) && ft_atoi((*stackB)->content) == find_max(*stackB))
		{
			rra(stackA);
		}	
		
		else if (ft_atoi((*stackA)->content) > ft_atoi((*stackB)->next->content) && ft_atoi((*stackA)->content) < ft_atoi((*stackB)->content))
		{
			rb(stackB);
		}
		
		else if (ft_atoi((*stackA)->content) > ft_atoi(ft_lstlast(*stackB)->content) && ft_atoi((*stackA)->content) < ft_atoi((*stackB)->content))
		{
			rrb(stackB);
		}
		
		else if (ft_atoi((*stackA)->next->content) > ft_atoi((*stackB)->content) && ft_atoi((*stackA)->next->content) < ft_atoi(ft_lstlast(*stackB)->content))
		{
			ra(stackA);
		}

		else if (ft_atoi(ft_lstlast(*stackA)->content) > ft_atoi((*stackB)->content) && ft_atoi(ft_lstlast(*stackA)->content) < ft_atoi(ft_lstlast(*stackB)->content))
		{
			rra(stackA);
		}
	
		

				printf("stackA\n");
	ft_lstiter(*stackA, ft_printf1);
	printf("stackB\n");
	ft_lstiter(*stackB, ft_printf1);
	

n++;
printf("count = %d\n",n);
				


}

	

				




}

