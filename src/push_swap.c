/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 12:12:46 by slord             #+#    #+#             */
/*   Updated: 2022/08/10 16:04:16 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_choice(t_liste *liste_a, t_liste *liste_b)
{
	int	*retour;

	retour = malloc(sizeof(int) * 2);
	if (validation_doublon(liste_a) == 0)
	{
		free(retour);
		free_stacks(liste_a, liste_b);
		ft_error();
	}	
	if (nb_chains(liste_a) == 2)
		smaller_sort(liste_a);
	if (nb_chains(liste_a) == 3)
		sort_3(liste_a);
	if (nb_chains(liste_a) == 5 || nb_chains(liste_a) == 4)
		small_sort(liste_a, liste_b, retour);
	if (nb_chains(liste_a) > 100)
		big_sort(liste_a, liste_b, retour);
	if (nb_chains(liste_a) > 5 && nb_chains(liste_a) < 101)
		sort_100(liste_a, liste_b, retour);
	free(retour);
}

void	free_stacks(t_liste *a, t_liste *liste_b)
{
	while (a->p != NULL)
		supression(a);
	free(a);
	free(liste_b);
}

void	free_tab(char **tab)
{
	int	i;

	i = -1;
	while (tab[++i])
		free(tab[i]);
	free(tab);
}

void	sorted(t_liste *liste_a, t_liste *liste_b)
{
	t_element	*actuel;

	actuel = liste_a->p;
	while (actuel->next != NULL)
	{
		if (actuel->nombre > actuel->next->nombre)
			return ;
		actuel = actuel->next;
	}
	free_stacks(liste_a, liste_b);
	exit (0);
}

int	main(int argc, char **argv)
{
	t_liste	*a;
	t_liste	*liste_b;
	int		i;

	ft_error_1(argc, argv);
	i = argc;
	a = initialisation();
	liste_b = initialisation();
	if (argc == 2)
		grosse_string(argv[1], a, liste_b);
	while (i > 1 && argc > 2)
	{
		if (validation_nombres(argc, argv) == 0)
		{
			free_stacks(a, liste_b);
			ft_error();
		}
		add_list(a, ft_atoi(argv[i - 1]));
		i--;
	}
	sorted(a, liste_b);
	sort_choice(a, liste_b);
	free_stacks(a, liste_b);
}
