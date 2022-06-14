/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:18:23 by slord             #+#    #+#             */
/*   Updated: 2022/06/01 16:44:33 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sa(Liste *liste)
{
	int	temp;

	if (liste->premier == NULL || liste->premier->next == NULL)
		return ;
	temp = liste->premier->nombre;
	liste->premier->nombre = liste->premier->next->nombre;
	liste->premier->next->nombre = temp;
	printf("sa\n");
}

void	pb(Liste *liste_a, Liste *liste_b)
{
	Element	*temp_1;

	if (liste_a->premier == NULL)
		return ;
	temp_1 = liste_a->premier;
	liste_a->premier = liste_a->premier->next;
	add_list(liste_b, temp_1->nombre);
	free(temp_1);
	printf("pb\n");
}

void ra(Liste *liste_a)
{
	int	temp;

	if (liste_a->premier == NULL)
		return ;
	temp = liste_a->premier->nombre;
	supression(liste_a);
	add_last(liste_a, temp);
	printf("ra\n");
}

void rra(Liste *liste_a)
{
	int	temp;

	if (liste_a->premier == NULL)
		return ;
	temp = remove_last(liste_a);
	add_list(liste_a, temp);
	printf("rra\n");
}

void ss(Liste *liste_a, Liste *liste_b)
{
	sa(liste_a);
	sb(liste_b);
}