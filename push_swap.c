/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 12:12:46 by slord             #+#    #+#             */
/*   Updated: 2022/06/15 15:39:05 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	Liste	*liste_a;
	Liste	*liste_b;
	int		i;

	i = argc;
	liste_a = initialisation();
	liste_b = initialisation();	
	while (argc > 1)
	{
		add_list(liste_a, atoi(argv[argc - 1]));
		argc--;
	}
	printf("%d", trouver_min(liste_a));
	premier_sort(liste_a, liste_b);
	afficherListe(liste_a);
	afficherListe(liste_b);
	printf("%d",liste_a->premier->nombre);
	
}
