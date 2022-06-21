/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:28:34 by slord             #+#    #+#             */
/*   Updated: 2022/06/21 19:17:28 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}
//fonction verifie les information envoye par lutilisateur
int validation_nombres(int argc, char **argv)
{
	int	i;
	char  *j;

	i = argc;
	j  = argv[0];
	//while (i > 1)
	//{
		//if (ft_isdigit(argv[i - 1]) == 0)
			//return (0);
		
	//}
	return (1);
}
int validation_doublon(Liste *liste)
{
	Element	*actuel;
	Element	*compare;

	compare = liste->premier;
	while (compare->next != NULL)
	{
		actuel = compare->next;
		while (actuel)
		{
			if (actuel->nombre == compare->nombre)
				return(0);
			actuel = actuel->next;
		}
		compare = compare->next;
	}
	return (1);
}