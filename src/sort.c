/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/13 15:50:55 by slord             #+#    #+#             */
/*   Updated: 2022/08/09 14:06:38 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	big_sort(t_liste *liste_a, t_liste *liste_b, int *retour)
{
	int	petit;
	int	j;

	j = 0;
	while (liste_a->p->next != NULL)
	{	
		petit = trouver_valeur_min(liste_a, 14, 14);
		if (trouver_position(liste_a, petit)
			<= (nb_chains(liste_a) / 2))
			j = 1;
		else
			j = 0;
		while (liste_a->p->nombre != petit)
		{
			if (j == 1)
				ra(liste_a);
			if (j == 0)
				rra(liste_a);
		}
		pb(liste_a, liste_b);
	}
	big_sort_1(liste_a, liste_b, j, retour);
}

void	big_sort_1(t_liste *liste_a, t_liste *liste_b, int j, int *retour)
{
	while (liste_b->p != NULL)
	{	
		{
			retour = trouver_bonne_position(liste_a,
					liste_b->p->nombre, retour);
			if (retour[0] <= (nb_chains(liste_a) / 2))
				j = 1;
			else
				j = 0;
			while (retour[1] != liste_a->p->nombre)
			{
				if (j == 1)
					ra(liste_a);
				if (j == 0)
					rra(liste_a);
			}
			pa(liste_a, liste_b);
		}
	}
	big_sort_2(liste_a, j);
}

void	big_sort_2(t_liste *liste_a, int j)
{
	if (trouver_position_min(liste_a) <= nb_chains(liste_a) / 2)
			j = 1;
	else
			j = 0;
	while (liste_a->p->nombre != trouver_valeur_min(liste_a, 1000, 1000))
	{
		if (j == 1)
			ra(liste_a);
		if (j == 0)
			rra(liste_a);
	}
}

void	smaller_sort(t_liste *liste_a)
{
	if (liste_a->p->nombre > liste_a->p->next->nombre)
	{
		sa(liste_a);
		return ;
	}
}

void	sort_3(t_liste *liste_a)
{
	if (liste_a->p->nombre > liste_a->p->next->nombre
		&& liste_a->p->nombre > liste_a->p->next->next->nombre
		&& liste_a->p->next->next->nombre < liste_a->p->nombre)
		ra(liste_a);
	if (liste_a->p->nombre < liste_a->p->next->nombre
		&& liste_a->p->nombre > liste_a->p->next->next->nombre
		&& liste_a->p->next->next->nombre < liste_a->p->next->nombre)
		rra(liste_a);
	if (liste_a->p->nombre < liste_a->p->next->nombre
		&& liste_a->p->nombre < liste_a->p->next->next->nombre
		&& liste_a->p->next->next->nombre < liste_a->p->next->nombre)
	{
		sa(liste_a);
		ra(liste_a);
	}		
	if (liste_a->p->nombre > liste_a->p->next->nombre
		&& liste_a->p->nombre < liste_a->p->next->next->nombre)
		sa(liste_a);
	if (liste_a->p->nombre > liste_a->p->next->nombre
		&& liste_a->p->nombre > liste_a->p->next->next->nombre)
	{
		sa(liste_a);
		rra(liste_a);
	}
}
