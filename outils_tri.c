/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   outils_tri.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/15 13:04:06 by slord             #+#    #+#             */
/*   Updated: 2022/06/16 18:19:49 by slord            ###   ########.fr       */
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
	while (actuel->nombre != min_relatif)
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
	while(j > 0)
	{
		actuel = liste->premier;
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