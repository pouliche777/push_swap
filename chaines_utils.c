/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chaines_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 15:50:31 by slord             #+#    #+#             */
/*   Updated: 2022/06/21 16:27:18 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

Liste	*initialisation(void)
{
	Liste	*liste;
	Element	*element;
	Element *chaine_supp;

	liste = malloc(sizeof(Liste));
	element = malloc(sizeof(Element));
	element->nombre = 0;
	element->next = NULL;
	liste->premier = element;
	chaine_supp = liste->premier;
	liste->premier = liste->premier->next;
	free(chaine_supp);
	return (liste);
}

void	add_list(Liste *liste, int nb)
{
	Element	*nouveau;

	nouveau = malloc(sizeof(*nouveau));
	nouveau->nombre = nb;
	nouveau->next = liste->premier;
	liste->premier = nouveau;
}
 void afficherListe(Liste *liste)
{
   
    Element *actuel = liste->premier;

    while (actuel != NULL)
    {
        printf("%d -> ", actuel->nombre);
        actuel = actuel->next;
    }
    printf("NULL\n");
}
void supression(Liste *liste_chainee)
{
	Element *chaine_supp;

	chaine_supp = liste_chainee->premier;
	liste_chainee->premier = liste_chainee->premier->next;
	free(chaine_supp);
}
void	add_last(Liste *liste, int nb)
{
	Element	*temp;

	temp = liste->premier;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = (Element *)malloc(sizeof(Element));
	temp->next->nombre = nb;
	temp->next->next = NULL;
}
int	remove_last (Liste *liste)
{
	Element	*temp;
	int		valeur_derniere;

	temp = liste->premier;
	while (temp->next->next != NULL)
		temp = temp->next;
	valeur_derniere = temp->next->nombre;
	free (temp->next);
	temp->next = NULL;
	return (valeur_derniere);
}
