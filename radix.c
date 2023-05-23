/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 09:19:28 by melee             #+#    #+#             */
/*   Updated: 2023/05/23 10:36:34 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

char	*getMin(t_list *stackA, int place)
{
	char 	*res;
	char	*content;

	res = NULL;
	while (stackA)
	{
		content = stackA->content;
		if (res == NULL)
			res = content;
		else if (content[0] == '-')
			if (res[0] == '-')
			{
			   if (ft_strlen(content) > ft_strlen(res))
					res = content;
	   			else if (content[place + 1] > res[place + 1])
					res = content;
			}
			else
			{
				printf("ms\n");
				res = content;
			}
		else
			if (res[0] != '-' && ft_strlen(content) < ft_strlen(res))
				res = content;
			else if (res[0] != '-' && content[place] < res[place])
				res = content;
		stackA = stackA->next;
	}
	return (res);

}


int	get_max_place(t_list *stackA)
{
	size_t		res;
	char	*content;

	res = 0;
	while (stackA)
	{
		content = stackA->content;
		if (content[0] == '-' && ft_strlen(content) - 1 > res)
			res = ft_strlen(content) - 1;
		else if (ft_strlen(content) > res)
			res = ft_strlen(content);
		stackA = stackA->next;
	}
	return (res);
}


void	radix_sort(t_list **stackA, t_list **stackB)
{
	int		place;
	char	*min;

	stackB= NULL;
	place = get_max_place(*stackA);
	//printf("place %d\n", place);

	//while (place)
	//{
	//	while (*stackA)
	//	{
			min = getMin(*stackA, 6);
			printf("min %s\n",min);
	//	}

	//}	

}
