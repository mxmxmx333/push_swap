/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbonengl <mbonengl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 12:10:19 by mbonengl          #+#    #+#             */
/*   Updated: 2024/06/21 18:54:08 by mbonengl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h> /*size_t, malloc, free*/
# include <limits.h> //limits
# include <unistd.h> //write
# include <stddef.h> //NULL, size_t
# include <stdint.h> //SIZE_MAX

typedef struct s_stack
{
	int				number;
	size_t			pos;
	size_t			cost;
	int				dir_a;
	int				dir_b;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

typedef struct s_clean_input
{
	char					*raw;
	char					*clean;
	int						number;
	char					*compare;
	struct s_clean_input	*next;
}	t_clean_input;

typedef struct s_all
{
	t_stack			*stack_a;
	t_stack			*stack_b;
	t_clean_input	*input;
	char			**split;
	size_t			ssa;
	size_t			ssb;
}	t_all;

/*input & filling*/
void	fill_stack_a(t_all *meta);
int		is_filled_a(t_all *meta);
void	create_stack_b(t_all *meta);

/*meta_utils*/
void	free_meta(t_all *meta);
void	reindex_a(t_all *meta);
void	reindex_b(t_all *meta);
void	clearinput(t_all *meta);

/*basic utils*/
char	*ft_itoa(int n);
int		ft_atoi(const char *nptr, int *nbr);
void	ft_putstr(char *s);
int		ft_strlen(char *s);
char	*ft_strdup(const char *s);
char	**ft_split(char const *s, char c);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
void	ft_free(void **ptr);
void	error(void);

/*ops*/
//rotations
void	ra(t_all *meta, int x);
void	rb(t_all *meta, int x);
void	rr(t_all *meta);
void	rrr(t_all *meta);
void	rra(t_all *meta, int x);
void	rrb(t_all *meta, int x);
//pushes
void	pa(t_all *meta);
void	pb(t_all *meta);
//swaps
void	sa(t_all *meta, int x);
void	sb(t_all *meta, int x);
void	ss(t_all *meta);

/*targeting*/
void	get_all_targets_a(t_all *meta);
void	get_all_targets_b(t_all *meta);

/*costs*/
void	put_direction(t_stack *node, int a, int b);
void	getcosts_a(t_all *meta);

/*input control*/
void	checkdupes(t_all *meta);
void	cleaninput(t_all *meta);
int		checkinputs(int argc, char **argv, t_all *meta);
int		checkformat(char *input);
void	convertback(t_all *meta);
void	convertnumbers(t_all *meta);

/*sorting*/
void	push_swap(t_all *meta);
void	push_to_b(t_all *meta);
void	push_to_a(t_all *meta);

/*sorting helpers*/
void	a_pos_pos(t_all *meta, t_stack *to_push, t_stack *target);
void	a_neg_neg(t_all *meta, t_stack *to_push, t_stack *target);
void	a_pos_neg(t_all *meta, t_stack *to_push, t_stack *target);
void	a_neg_pos(t_all *meta, t_stack *to_push, t_stack *target);
t_stack	*get_min_a(t_all *meta);

/*main functions*/

#endif