/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 13:38:43 by slord             #+#    #+#             */
/*   Updated: 2022/08/09 14:37:31 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	dernier_liste(t_liste *liste)
{
	t_element	*actuel;

	actuel = liste->p;
	while (actuel->next != NULL)
	{
		actuel = actuel->next;
	}
	return (actuel->nombre);
}

void	afficherliste(t_liste *liste)
{
	t_element	*actuel;

	actuel = liste->p;
	while (actuel != NULL)
	{
		printf("%d -> ", actuel->nombre);
		actuel = actuel->next;
	}
	printf("NULL\n");
}

int	trouver_valeur_max(t_liste *liste)
{
	int			valeur_max;
	t_element	*actuel;

	actuel = liste->p;
	valeur_max = actuel->nombre;
	while (actuel->next != NULL)
	{
		if (valeur_max < actuel->next->nombre)
			valeur_max = actuel->next->nombre;
		actuel = actuel->next;
	}
	return (valeur_max);
}

void	small_sort(t_liste *liste_a, t_liste *liste_b, int *retour)
{
	int	petit;
	int	j;

	j = 0;
	while (nb_chains(liste_a) > 3)
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
	sort_3(liste_a);
	big_sort_1(liste_a, liste_b, j, retour);
}

//fonction qui trouve la position du nombre le plus petit dans une liste
int	trouver_position_min(t_liste *liste)
{
	int			position_min;
	int			i;
	int			min;
	t_element	*actuel;

	actuel = liste->p;
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
