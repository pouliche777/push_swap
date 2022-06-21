/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_tri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:04:06 by slord             #+#    #+#             */
/*   Updated: 2022/06/21 14:53:44 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//fonction qui trouve la position du nombre le plus petit dans une liste
int	trouver_position_min(Liste *liste)
{
	int		position_min;
	int		i;
	int		min;
	Element	*actuel;

	actuel = liste->premier;
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
int	trouver_position(Liste *liste, int min_relatif)
{
	Element	*actuel;
	int		i;

	i = 0;
	actuel = liste->premier;
	while (actuel->nombre != min_relatif && actuel->next != NULL)
	{
		actuel = actuel->next;
		i++;
	}
	return (i);
}
//fonction qui trouve et renvoie la valeur minimum
int trouver_valeur_min(Liste *liste, int chunk)
{
	int valeur_min;
	Element	*actuel;
	int i;
	int j;

	i = chunk;
	actuel = liste->premier;
	valeur_min = actuel->nombre;
	while(actuel->next !=NULL && chunk != 0)
	{
		if (valeur_min > actuel->next->nombre)
			valeur_min =  actuel->next->nombre;
		actuel =actuel->next;
		chunk--;
	}
	actuel = liste->premier;
	j = trouver_nombre_chainons(liste) - i;
	while(j > 0 && actuel->next != NULL)
	{
		actuel = actuel->next;
		j--;	
	}
	while(actuel->next !=NULL)
	{
		if (valeur_min > actuel->next->nombre)
			valeur_min =  actuel->next->nombre;
		actuel =actuel->next;
	}
	return (valeur_min);
}

int	trouver_nombre_chainons(Liste *liste)
{
	Element	*actuel;
	int		i;

	actuel = liste->premier;
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
int trouver_valeur_max(Liste *liste, int chunk)
{
	int valeur_max;
	Element	*actuel;
	int i;
	int j;

	i = chunk;
	if (!liste->premier->nombre)
		return (0);
	if (liste->premier->next == NULL) 
		return (liste->premier->nombre);
	actuel = liste->premier;
	valeur_max = actuel->nombre;
	while(actuel->next !=NULL && chunk != 0)
	{
		if (valeur_max < actuel->next->nombre)
			valeur_max =  actuel->next->nombre;
		actuel =actuel->next;
		chunk--;
	}
	actuel = liste->premier;
	j = trouver_nombre_chainons(liste) - i;
	while(j > 0)
	{
		actuel = liste->premier;
		j--;	
	}
	while(actuel->next !=NULL)
	{
		if (valeur_max < actuel->next->nombre)
			valeur_max =  actuel->next->nombre;
		actuel =actuel->next;
	}
	return (valeur_max);
}
int	*trouver_bonne_position(Liste *liste, int nb_a_push)
{
	int		bonne_position;
	int 	*retour;
	Element	*actuel;
	retour = malloc(sizeof(int) * 2);
	actuel = liste->premier;
	bonne_position = 0;
	retour[0] = bonne_position;
	retour[1] = liste->premier->nombre;
	if (liste->premier->next == NULL)
		return (retour);
	if (liste->premier->nombre > nb_a_push && dernier_liste(liste) < nb_a_push)
		return (retour);
	if (nb_a_push < trouver_valeur_min(liste, 1000))
		while (actuel)
		{
			if (actuel->nombre == trouver_valeur_min(liste, 1000))
			{
				retour[0] = bonne_position;
				retour[1] = actuel->nombre;
				return (retour);
			}
			actuel = actuel->next;
			bonne_position++;
		}
	if (nb_a_push > trouver_valeur_max(liste, 1000))
		while (actuel)
		{
			if (actuel->nombre == trouver_valeur_max(liste, 1000))
			{
				retour[0] = bonne_position;
				retour[1] = actuel->nombre;
				return (retour);
			}
			actuel = actuel->next;
			bonne_position++;
		}
	while (actuel->next != NULL)
	{
		if (actuel->nombre < nb_a_push && actuel->next->nombre > nb_a_push)
		{
			retour[0] = bonne_position;
			retour[1] = actuel->next->nombre;
			return (retour);
		}
		actuel = actuel->next;
		bonne_position++;
	}
	return (retour);
}
int dernier_liste(Liste *liste)
{
	Element *actuel;

	actuel = liste->premier;
	while (actuel->next != NULL)
	{
		actuel = actuel->next;
	}
	return (actuel->nombre);
}