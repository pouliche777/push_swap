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
	int	i;
	int j;
	Element *actuel;
	int	petit;

	i = 0;
	j = 0;
	actuel = liste_a->premier->next->nombre;
	petit = liste_a->premier->nombre;
	while (liste_a)
	{
		while (actuel->nombre != NULL)
		{
			if (petit < actuel->next->nombre)
				actuel = actuel->next;
				i++;
			if (petit < actuel->next->nombre)
			{
				petit = actuel->nombre;
				actuel = actuel->next;
				j = i; 
				i++;
			}	 
		}
		while (j > - 1)
		{
			ra(liste_a);
			j--;
		}
		pa(liste_a, liste_b);
		i = 0;
		j = 0;
	}
