/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slord <slord@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 13:04:57 by slord             #+#    #+#             */
/*   Updated: 2022/06/21 19:05:13 by slord            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct Element Element;
struct Element
{
    int nombre;
    Element *next;
};

typedef struct Liste Liste;
struct Liste
{
    Element *premier;
};

int push_swap(int argc, char **argv);
Liste	*initialisation(void);
void    add_list(Liste *liste, int nb);
void    afficherListe(Liste *liste);
void    sa(Liste *liste);
void    pa(Liste *liste_a, Liste *liste_b);
void    ra(Liste *liste_a);
void    supression(Liste *liste_chainee);
void    add_last(Liste *liste, int nb);
int     remove_last(Liste *liste);
void    rra(Liste *liste_a);
void    ss(Liste *liste_a, Liste *liste_b);
void	rb(Liste *liste_b);
void	rrb(Liste *liste_b);
void	pb(Liste *liste_a, Liste *liste_b);
void	sb(Liste *liste);
void    premier_sort(Liste *liste_a, Liste *liste_b);
int	    trouver_position_min(Liste *liste);
int     trouver_valeur_min(Liste *liste, int chunk);
int	    trouver_nombre_chainons(Liste *liste);
int     trouver_valeur_max(Liste *liste, int chunk);
int	    trouver_position(Liste *liste, int min_relatif);
int	    *trouver_bonne_position(Liste *liste, int nb_a_push);
int     dernier_liste(Liste *liste);
int     validation_nombres(int argc, char **argv);
int     validation_doublon(Liste *liste);
void 	smaller_sort(Liste *liste_a);
void 	small_sort(Liste *liste_a, Liste *liste_b);

#endif