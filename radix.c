/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:19:28 by melee             #+#    #+#             */
/*   Updated: 2023/05/25 12:42:47 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

char	*getMin(t_list *stackA, size_t pos)
{
	char 	*min;
	char	*content;
	
	min = NULL;
	while (stackA)
	{
		content = stackA->content;
		if (!min)
			min = stackA->content;
		else if (content[0] == '-' && min[0] == '-')
		{
			if (ft_strlen(content) > ft_strlen(min)) 
				min = content;
			else
				if (content[ft_strlen(content) - pos -1] > min[ft_strlen(content)-pos-1])
					min = content;
	}
		else if (content[0] == '-' && min[0] != '-')
			min = content;
		else if (content[0] != '-' && min[0] != '-')
		{
			if (pos > ft_strlen(content) - 1)
			{
				min = content;
				break;
			}
			else if (content[ft_strlen(content)-1-pos] < min[ft_strlen(min)-1-pos])
			{
				min = content;
			}

		}
		stackA = stackA->next;
	}
	return (min);
}


int	get_max_place(t_list *stackA)
{
	size_t		place;
	char		*content;

	place = 0;
	while (stackA)
	{
		content = stackA->content;
		if (content[0] == '-' && ft_strlen(content) - 1 > place)
			place = ft_strlen(content) - 1;
		else if (ft_strlen(content) > place)
			place = ft_strlen(content);
		stackA = stackA->next;
	}
	return (place);
}


void	ft_printf1(void *content)
{
	printf("%s\n",content);
}

void	radix_sort(t_list **stackA, t_list **stackB)
{
	int		place;
	char	*min;
	int		pos;
	char	*placeholder;

	place = get_max_place(*stackA);
	printf("place %d\n",place);
	pos = 0;
	while (pos < place)
	{
		while (*stackA)
		{
			min = getMin(*stackA, place);
			printf("min %s\n",min);
			if (ft_atoi((*stackA)->content) == ft_atoi(min))
				pb(stackA, stackB);
			else 
			{
				placeholder = (*stackA)->content;
				while (ft_atoi((*stackA)->content)!=ft_atoi(min))
					pb(stackA, stackB);	
				pb(stackA, stackB);
				rb(stackB);
				if (!*stackA)
					pa(stackA, stackB);
				else
					while (ft_atoi((*stackA)->content)!=ft_atoi(placeholder))
						pa(stackA, stackB);
				rrb(stackB);
			}		
					}
		while (*stackB)
		{
			pa(stackA, stackB);
		}

		pos++;
	}
	printf("ITERATION A\n");
	ft_lstiter(*stackA, ft_printf1);
	printf("ITERATION B\n");
	ft_lstiter(*stackB, ft_printf1);


}
