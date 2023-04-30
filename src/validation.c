/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/21 16:28:34 by slord             #+#    #+#             */
/*   Updated: 2022/08/17 16:44:01 by slord            ###   ########.fr       */
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

int	validation_nombres(int argc, char **argv)
{
	int		i;
	char	*j;

	i = argc;
	j = argv[0];
	while (i > 1)
	{
		if (ft_str_isdigit(argv[i - 1]) == 0)
			return (0);
		i--;
	}
	return (1);
}

int	validation_doublon(t_liste *liste)
{
	t_element	*actuel;
	t_element	*compare;

	compare = liste->p;
	while (compare->next != NULL)
	{
		actuel = compare->next;
		while (actuel)
		{
			if (actuel->nombre == compare->nombre)
				return (0);
			actuel = actuel->next;
		}
		compare = compare->next;
	}
	return (1);
}

void	grosse_string(char *str, t_liste *liste_a, t_liste *liste_b)
{
	int		i;
	char	**tab;

	i = 0;
	tab = ft_split(str, ' ');
	while (tab[i])
	{	
		if (ft_strlen(tab[i]) > 11 || ft_atol(tab[i]) < INT_MIN
			|| ft_atol(tab[i]) > INT_MAX)
		{
			free_stacks(liste_a, liste_b);
			free_tab(tab);
			ft_error();
		}
		i++;
	}
	grosse_string_1(liste_a, liste_b, tab, i);
}

void	grosse_string_1(t_liste *liste_a, t_liste *liste_b, char **tab, int i)
{
	while (tab[i - 1])
	{
		add_list(liste_a, ft_atoi(tab[i - 1]));
		i--;
	}
	i = 0;
	while (tab[i])
	{	
		if (ft_str_isdigit(tab[i]) == 0)
		{
			free_stacks(liste_a, liste_b);
			free_tab(tab);
			ft_error();
		}
		i++;
	}
	free_tab(tab);
}
