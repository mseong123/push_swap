/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 13:14:46 by melee             #+#    #+#             */
/*   Updated: 2023/05/29 13:36:07 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_operations	*init(void)
{
	t_operations	*ptr;

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

void	upper_half(int pos[2], t_operations *ptr)
{
	if (pos[0] > pos[1])
	{
		ptr->temp_rr = pos[1];
		ptr->temp_ra = pos[0] - pos[1];
	}
	else
	{
		ptr->temp_rr = pos[0];
		ptr->temp_rb = pos[1] - pos[0];
	}
}

void	bottom_half(int pos[2], t_operations *ptr)
{
	if (pos[0] > pos[1])
	{
		ptr->temp_rrr = pos[1];
		ptr->temp_rra = pos[0] - pos[1];
	}
	else
	{
		ptr->temp_rrr = pos[0];
		ptr->temp_rrb = pos[1] - pos[0];
	}
}

void	mix1(int pos[2], t_operations *ptr)
{
		ptr->temp_ra = pos[0];
		ptr->temp_rrb = pos[1];
}

void	mix2(int pos[2], t_operations *ptr)
{
		ptr->temp_rra = pos[0];
		ptr->temp_rb = pos[1];
}
