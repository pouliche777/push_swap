/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chaines_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:50:31 by slord             #+#    #+#             */
/*   Updated: 2022/08/08 20:45:02 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_liste	*initialisation(void)
{
	t_liste		*liste;
	t_element	*element;
	t_element	*chaine_supp;

	liste = malloc(sizeof(t_liste));
	element = malloc(sizeof(t_element));
	element->nombre = 0;
	element->next = NULL;
	liste->p = element;
	chaine_supp = liste->p;
	liste->p = liste->p->next;
	free(chaine_supp);
	return (liste);
}

void	add_list(t_liste *liste, int nb)
{
	t_element	*nouveau;

	nouveau = malloc(sizeof(*nouveau));
	nouveau->nombre = nb;
	nouveau->next = liste->p;
	liste->p = nouveau;
}

void	supression(t_liste *liste_chainee)
{
	t_element	*chaine_supp;

	chaine_supp = liste_chainee->p;
	liste_chainee->p = liste_chainee->p->next;
	free(chaine_supp);
}

void	add_last(t_liste *liste, int nb)
{
	t_element	*temp;

	temp = liste->p;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = (t_element *)malloc(sizeof(t_element));
	temp->next->nombre = nb;
	temp->next->next = NULL;
}

int	remove_last(t_liste *liste)
{
	t_element	*temp;
	int			valeur_derniere;

	temp = liste->p;
	while (temp->next->next != NULL)
		temp = temp->next;
	valeur_derniere = temp->next->nombre;
	free (temp->next);
	temp->next = NULL;
	return (valeur_derniere);
}
