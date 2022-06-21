/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   premier_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:50:55 by slord             #+#    #+#             */
/*   Updated: 2022/06/20 20:35:12 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	premier_sort(Liste *liste_a, Liste *liste_b)
{
	int	i;
	int	petit;
	int	j;
	int minimum;
	int g;
	


	i = 0;
	j = 0;
	
	while (liste_a->premier->next != NULL)
	{	
		petit = trouver_valeur_min(liste_a, 20);
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
	/* while (i > 0)
	{
	
		gros = trouver_valeur_max(liste_b, 1000);
		if (trouver_position(liste_b, gros) <= (trouver_nombre_chainons(liste_b) / 2))
			j = 1;
		else
			j = 0;
		while (liste_b->premier->nombre != gros)
		{
			if (j == 1)
				rb(liste_b);
		if (j == 0)
				rrb(liste_b);
		}
		pa(liste_a,liste_b);
		i--;
	}
} */
	minimum = trouver_valeur_min(liste_a, 1000);
	while (i > 0)
	{
		
		if (liste_b->premier->nombre < minimum)
		{
			if (trouver_position(liste_a, minimum) <= (trouver_nombre_chainons(liste_a) / 2))
				j = 1;
			else 
				j = 0;
			while (liste_a->premier->nombre != minimum)
			{
				if (j == 1)
					ra(liste_a);
				if (j == 0)
					rra(liste_a);
			}
			minimum = liste_b->premier->nombre;
			pa(liste_a, liste_b);
			
			i--;
		}
		if (liste_b->premier->nombre > minimum)
		{
			g = trouver_bonne_position(liste_a, liste_b->premier->nombre);
			while (g > 0)
			{
				rra(liste_a);
				g--;
			}
			pa(liste_a, liste_b);
			i--;
		}
		}
		
		
}
