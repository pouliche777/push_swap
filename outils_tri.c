/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_tri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:04:06 by slord             #+#    #+#             */
/*   Updated: 2022/06/15 15:25:38 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//fonction qui trouve la position du nombre le plus petit dans une liste
int	trouver_min(Liste *liste)
{
	int		position_min;
	int		i;
	int		min;
	Element	*actuel;

	actuel = liste->premier;
	position_min = 0;
	min = actuel->nombre;
	i = 0;
	while (actuel->next != NULL)
	{
		i++;
		if (min > actuel->next->nombre)
		{
			position_min = i;
			min = actuel->next->nombre;
		}
		actuel = actuel->next;
	}
	return (position_min);
}
