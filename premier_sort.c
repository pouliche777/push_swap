/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   premier_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:50:55 by slord             #+#    #+#             */
/*   Updated: 2022/06/21 19:44:47 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void 	premier_sort(Liste *liste_a, Liste *liste_b)
{
	int	i;
	int	petit;
	int	j;
	int *test;

	i = 0;
	j = 0;
	while (liste_a->premier->next != NULL)
	{	
		petit = trouver_valeur_min(liste_a, 15);
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
	while (i > 0)
	{	
		{
			test = trouver_bonne_position(liste_a, liste_b->premier->nombre);
			if (test[0] <= (trouver_nombre_chainons(liste_a) / 2))
				j = 1;
			else
				j = 0;
			while (test[1] != liste_a->premier->nombre)
			{
				if (j == 1)
					ra(liste_a);
				if (j == 0)
					rra(liste_a);
				test[0]--;
			}
			pa(liste_a, liste_b);
			i--;
		}
	}
	if (trouver_position_min(liste_a) <= trouver_nombre_chainons(liste_a) / 2)
			j = 1;
	else
			j = 0;
	while (liste_a->premier->nombre != trouver_valeur_min(liste_a, 1000))
	{
		if (j == 1)
			ra(liste_a);
		if (j == 0)
			rra(liste_a);
	}
}

void 	smaller_sort(Liste *liste_a)
{
	Element	*l;

	l = liste_a->premier;
	if (l->nombre > l->next->nombre && l->nombre < l->next->next->nombre)
		sa(liste_a);
	else if (l->nombre > l->next->nombre && l->next->nombre > l->next->next->nombre)
	{
		sa(liste_a);
		rra(liste_a);
	
	}
	else if (l->nombre > l->next->nombre && l->next->nombre < l->next->next->nombre)
		ra(liste_a);
	else if (l->nombre < l->next->next->nombre
		&& l->next->next->nombre < l->next->nombre)
	{
		sa(liste_a);
		ra(liste_a);
	}
	else if (l->nombre < l->next->nombre && l->nombre > l->next->next->nombre)
		rra(liste_a);
}

void 	small_sort(Liste *liste_a, Liste *liste_b)
{
	int	j;
	int	*test;
	 
	pb(liste_a, liste_b);
	pb(liste_a, liste_b);
	smaller_sort(liste_a);
	j = 0;
	while (liste_b->premier->nombre)
	{	
		{
			test = trouver_bonne_position(liste_a, liste_b->premier->nombre);
			if (test[0] <= (trouver_nombre_chainons(liste_a) / 2))
				j = 1;
			else
				j = 0;
			while (test[1] != liste_a->premier->nombre)
			{
				if (j == 1)
					ra(liste_a);
				if (j == 0)
					rra(liste_a);
				test[0]--;
			}
			pa(liste_a, liste_b);
		}
	}
}
