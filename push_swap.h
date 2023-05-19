/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: melee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 10:58:16 by melee             #+#    #+#             */
/*   Updated: 2023/05/18 16:02:52 by melee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# define FD 1

# include "libft.h"

void	    sa(t_list *stackA);
void	    sb(t_list *stackB);
void		ss(t_list *stackA, t_list *stackB);
void		pa(t_list **stackA, t_list **stackB);
void		pb(t_list **stackA, t_list **stackB);
long int    ft_atoi_long(const char *str);

#endif
