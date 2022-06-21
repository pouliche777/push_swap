/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:10:33 by slord             #+#    #+#             */
/*   Updated: 2022/06/21 16:27:16 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(Liste *liste)
{
	int	temp;

	if (liste->premier == NULL || liste->premier->next == NULL)
		return ;
	temp = liste->premier->nombre;
	liste->premier->nombre = liste->premier->next->nombre;
	liste->premier->next->nombre = temp;
	printf("sb\n");
}

void	rb(Liste *liste_b)
{
	int	temp;

	if (liste_b->premier == NULL)
		return ;
	temp = liste_b->premier->nombre;
	supression(liste_b);
	add_last(liste_b, temp);
	printf("rb\n");
}

void	rrb(Liste *liste_b)
{
	int	temp;

	if (liste_b->premier == NULL)
		return ;
	temp = remove_last(liste_b);
	add_list(liste_b, temp);
	printf("rrb\n");
}

void	pa(Liste *liste_a, Liste *liste_b)
{
	Element	*temp_1;

	if (liste_b->premier == NULL)
		return ;
	temp_1 = liste_b->premier;
	liste_b->premier = liste_b->premier->next;
	add_list(liste_a, temp_1->nombre);
	free(temp_1);
	printf("pa\n");
}