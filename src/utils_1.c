/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/09 11:40:00 by slord             #+#    #+#             */
/*   Updated: 2022/08/17 16:39:06 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	int		i;
	long	sign;
	long	nb;

	i = 0;
	sign = 1;
	nb = 0;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + str[i] - 48;
		i++;
	}
	if (str[i - 1] == '-')
		ft_error();
	return (nb * sign);
}

void	ft_error(void)
{
	write(2, "Error\n", 6);
	exit (0);
}

int	ft_str_isdigit(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_error_1(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		exit (0);
	if (argc < 2)
		ft_error();
	i = 2;
	while (i < argc)
	{
		if (ft_strlen(argv[i]) > 11 || ft_atol(argv[i]) < INT_MIN
			|| ft_atol(argv[i]) > INT_MAX)
			ft_error();
		i++;
	}
	if (argc == 2 && argv[1][0] == '\0')
		exit(0);
}

void	sort_100(t_liste *liste_a, t_liste *liste_b, int *retour)
{
	int	petit;
	int	j;

	j = 0;
	while (liste_a->p->next != NULL)
	{	
		petit = trouver_valeur_min(liste_a, 7, 7);
		if (trouver_position(liste_a, petit)
			<= (nb_chains(liste_a) / 2))
			j = 1;
		else
			j = 0;
		while (liste_a->p->nombre != petit)
		{
			if (j == 1)
				ra(liste_a);
			if (j == 0)
				rra(liste_a);
		}
		pb(liste_a, liste_b);
	}
	big_sort_1(liste_a, liste_b, j, retour);
}
