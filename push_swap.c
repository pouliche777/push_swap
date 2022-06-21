/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 12:12:46 by slord             #+#    #+#             */
/*   Updated: 2022/06/21 19:25:24 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	Liste	*liste_a;
	Liste	*liste_b;
	int		i;


	if (argc == 1)
		return (1);
	i = argc;
	liste_a = initialisation();
	liste_b = initialisation();
	while (i > 1)
	{
		add_list(liste_a, atoi(argv[i - 1]));
		i--;
	}
	if (validation_doublon(liste_a) == 0 || validation_nombres(argc, argv) == 0)
	{
		write(2, "error", 5);
		return (0);
	}
	if (trouver_nombre_chainons(liste_a) <= 5 && trouver_nombre_chainons(liste_a) > 2)
		small_sort(liste_a, liste_b);
	if (trouver_nombre_chainons(liste_a) <= 500 && trouver_nombre_chainons(liste_a) >= 6)
		premier_sort(liste_a, liste_b);
	afficherListe(liste_a);
	afficherListe(liste_b);
	printf("%d",liste_a->premier->nombre);
}
