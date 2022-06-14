/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   premier_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:50:55 by slord             #+#    #+#             */
/*   Updated: 2022/06/13 20:54:38 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	premier_sort(Liste *liste_a, Liste *liste_b)
{
	Element	*actuel;

	while (liste_a->premier->next != NULL)
	{
		pb(liste_a, liste_b);
	}
	actuel = liste_b->premier;
	while (liste_b->premier)
	{
		if (liste_a->premier->nombre > liste_b->premier->nombre)
			pa(liste_a, liste_b);
		if (liste_a->premier->nombre < liste_b->premier->nombre)
		{
			pa(liste_a, liste_b);
			rra(liste_a);
		}
		
	}
}