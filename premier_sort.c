/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   premier_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:50:55 by slord             #+#    #+#             */
/*   Updated: 2022/06/15 15:40:08 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	premier_sort(Liste *liste_a, Liste *liste_b)
{
	int	i;
	int j;
	Element *actuel;
	int	petit;


	j = 0;
	actuel = liste_a->premier->next;
	petit = liste_a->premier->nombre;
	while (liste_a)
	{
		i = trouver_min(liste_a);
		while (i > 0)
		{
			ra(liste_a);
			j--;
		}
		pa(liste_a, liste_b);
	}
}
