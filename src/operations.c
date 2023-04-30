/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 16:18:23 by slord             #+#    #+#             */
/*   Updated: 2022/08/17 16:43:35 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_liste *liste)
{
	int	temp;

	if (liste->p == NULL || liste->p->next == NULL)
		return ;
	temp = liste->p->nombre;
	liste->p->nombre = liste->p->next->nombre;
	liste->p->next->nombre = temp;
	printf("sa\n");
}

void	pb(t_liste *liste_a, t_liste *liste_b)
{
	t_element	*temp_1;

	if (liste_a->p == NULL)
		return ;
	temp_1 = liste_a->p;
	liste_a->p = liste_a->p->next;
	add_list(liste_b, temp_1->nombre);
	free(temp_1);
	printf("pb\n");
}

void	ra(t_liste *liste_a)
{
	int	temp;

	if (liste_a->p == NULL)
		return ;
	temp = liste_a->p->nombre;
	supression(liste_a);
	add_last(liste_a, temp);
	printf("ra\n");
}

void	rra(t_liste *liste_a)
{
	int	temp;

	if (liste_a->p == NULL)
		return ;
	temp = remove_last(liste_a);
	add_list(liste_a, temp);
	printf("rra\n");
}

void	ss(t_liste *liste_a, t_liste *liste_b)
{
	sa(liste_a);
	sb(liste_b);
}
