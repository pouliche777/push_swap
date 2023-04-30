/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_tri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:04:06 by slord             #+#    #+#             */
/*   Updated: 2022/08/08 18:32:56 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	trouver_position(t_liste *liste, int chunk)
{
	t_element	*actuel;
	int			i;

	i = 0;
	actuel = liste->p;
	while (actuel->nombre != chunk && actuel->next != NULL)
	{
		actuel = actuel->next;
		i++;
	}
	return (i);
}

//fonction qui trouve et renvoie la valeur minimum
int	trouver_valeur_min(t_liste *liste, int chunk, int i)
{
	int			valeur_min;
	t_element	*actuel;
	int			j;

	actuel = liste->p;
	valeur_min = actuel->nombre;
	while (actuel->next != NULL && chunk != 0)
	{
		if (valeur_min > actuel->next->nombre)
			valeur_min = actuel->next->nombre;
		actuel = actuel->next;
		chunk--;
	}
	actuel = liste->p;
	j = nb_chains(liste) - i + 1;
	while (j-- > 0 && actuel->next != NULL)
		actuel = actuel->next;
	while (actuel->next != NULL)
	{
		if (valeur_min > actuel->next->nombre)
			valeur_min = actuel->next->nombre;
		actuel = actuel->next;
	}
	return (valeur_min);
}

int	nb_chains(t_liste *liste)
{
	t_element	*actuel;
	int			i;

	actuel = liste->p;
	if (!liste)
		return (0);
	i = 1;
	while (actuel->next != NULL)
	{
		actuel = actuel->next;
		i++;
	}
	return (i);
}

int	*trouver_bonne_position(t_liste *liste, int nb_a_push, int *retour)
{
	int			bonne_position;
	t_element	*actuel;

	actuel = liste->p;
	bonne_position = 0;
	retour[0] = bonne_position;
	retour[1] = liste->p->nombre;
	if (nb_a_push < trouver_valeur_min(liste, 1000, 1000))
	{
		while (actuel)
		{
			if (actuel->nombre == trouver_valeur_min(liste, 1000, 1000))
			{
				retour[0] = bonne_position;
				retour[1] = actuel->nombre;
				return (retour);
			}
			actuel = actuel->next;
			bonne_position++;
		}
	}
	return (b_p1(liste, retour, actuel, nb_a_push));
}

int	*b_p1(t_liste *liste, int *retour, t_element *actuel, int push)
{
	if (push > trouver_valeur_max(liste) || !liste->p->nombre)
	{
		while (actuel)
		{
			if (actuel->nombre == trouver_valeur_max(liste))
			{
				retour[1] = actuel->nombre;
				return (retour);
			}
			actuel = actuel->next;
			retour[0]++;
		}
	}
	while (actuel->next != NULL)
	{
		if (actuel->nombre < push && actuel->next->nombre > push)
		{
			retour[1] = actuel->next->nombre;
			return (retour);
		}
		actuel = actuel->next;
		retour[0]++;
	}
	return (retour);
}
