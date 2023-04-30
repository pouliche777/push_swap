/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:04:57 by slord             #+#    #+#             */
/*   Updated: 2022/08/10 15:53:41 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include "../libft/libft.h"

typedef struct s_element
{
	int					nombre;
	struct s_element	*next;
}	t_element;

typedef struct s_liste
{
	t_element	*p;
}	t_liste;

int		push_swap(int argc, char **argv);
t_liste	*initialisation(void);
void	add_list(t_liste *liste, int nb);
void	afficherliste(t_liste *liste);
void	sa(t_liste *liste);
void	pa(t_liste *liste_a, t_liste *liste_b);
void	ra(t_liste *liste_a);
void	supression(t_liste *liste_chainee);
void	add_last(t_liste *liste, int nb);
int		remove_last(t_liste *liste);
void	rra(t_liste *liste_a);
void	ss(t_liste *liste_a, t_liste *liste_b);
void	rb(t_liste *liste_b);
void	rrb(t_liste *liste_b);
void	pb(t_liste *liste_a, t_liste *liste_b);
void	sb(t_liste *liste);
void	big_sort(t_liste *liste_a, t_liste *liste_b, int *retour);
int		trouver_position_min(t_liste *liste);
int		trouver_valeur_min(t_liste *liste, int chunk, int i);
int		nb_chains(t_liste *liste);
int		trouver_valeur_max(t_liste *liste);
int		trouver_position(t_liste *liste, int min_relatif);
int		*trouver_bonne_position(t_liste *liste, int nb_a_push, int *retour);
int		dernier_liste(t_liste *liste);
int		validation_nombres(int argc, char **argv);
int		validation_doublon(t_liste *liste);
void	smaller_sort(t_liste *liste_a);
void	small_sort(t_liste *liste_a, t_liste *liste_b, int *retour);
void	grosse_string(char *str, t_liste *liste_a, t_liste *liste_b);
int		ft_str_isdigit(char *str);
void	big_sort_1(t_liste *liste_a, t_liste *liste_b, int j, int *retour);
void	big_sort_2(t_liste *liste_a, int j);
int		*b_p1(t_liste *liste, int *retour, t_element *actuel, int push);
void	sort_3(t_liste *liste_a);
void	sort_choice(t_liste *liste_a, t_liste *liste_b);
void	free_stacks(t_liste *a, t_liste *liste_b);
void	free_tab(char **tab);
long	ft_atol(const char *str);
void	ft_error(void);
void	grosse_string_1(t_liste *liste_a, t_liste *liste_b, char **tab, int i);
int		ft_isdigit(int c);
void	ft_error_1(int argc, char **argv);
void	sort_100(t_liste *liste_a, t_liste *liste_b, int *retour);
void	sorted(t_liste *liste_a, t_liste *liste_b);
int		ft_atoi1(const char *str);

#endif