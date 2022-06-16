/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   premier_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:50:55 by slord             #+#    #+#             */
/*   Updated: 2022/06/16 18:25:51 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	premier_sort(Liste *liste_a, Liste *liste_b)
{
	int	i;
	int	petit;
	int	j;
	int g;
	int gros;

	i = 0;
	j = 0;
	g = 0;
	while (liste_a->premier->next != NULL)
	{	
		petit = trouver_valeur_min(liste_a, 10);
		if (trouver_position(liste_a, petit) <= (trouver_nombre_chainons(liste_a) / 2))
			j = 1;
		else 
			j = 0;	
		while (liste_a->premier->nombre != petit)
		{
			if (j == 1)
				ra(liste_a);
			if (j == 0)
				rra(liste_a);
		}
		pb(liste_a, liste_b);
		i++;
	}
	while (i > 0)
	{
		gros = trouver_valeur_max(liste_b, 1000);
		while (liste_b->premier->nombre != gros)
			rb(liste_b);
		pa(liste_a,liste_b);
		i--;
	}
}
