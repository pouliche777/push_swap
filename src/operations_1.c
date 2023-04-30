/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 15:10:33 by slord             #+#    #+#             */
/*   Updated: 2022/08/17 16:44:21 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_liste *liste)
{
	int	temp;

	if (liste->p == NULL || liste->p->next == NULL)
		return ;
	temp = liste->p->nombre;
	liste->p->nombre = liste->p->next->nombre;
	liste->p->next->nombre = temp;
	printf("sb\n");
}

void	rb(t_liste *liste_b)
{
	int	temp;

	if (liste_b->p == NULL)
		return ;
	temp = liste_b->p->nombre;
	supression(liste_b);
	add_last(liste_b, temp);
	printf("rb\n");
}

void	rrb(t_liste *liste_b)
{
	int	temp;

	if (liste_b->p == NULL)
		return ;
	temp = remove_last(liste_b);
	add_list(liste_b, temp);
	printf("rrb\n");
}

void	pa(t_liste *liste_a, t_liste *liste_b)
{
	t_element	*temp_1;

	if (liste_b->p == NULL)
		return ;
	temp_1 = liste_b->p;
	liste_b->p = liste_b->p->next;
	add_list(liste_a, temp_1->nombre);
	free(temp_1);
	printf("pa\n");
}

int	ft_atoi1(const char *str)
{
	int	i;
	int	sign;
	int	nb;

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
