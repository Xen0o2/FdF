/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alecoutr <alecoutr@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 18:11:44 by alecoutr          #+#    #+#             */
/*   Updated: 2022/11/11 21:59:13 by alecoutr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../fdf.h"

int	next_word_length(char const *s, char c)
{
	int	length;

	length = 0;
	while (*s && *s == c)
		s++;
	while (*s && *s != c)
	{
		s++;
		length++;
	}
	return (length);
}

int	get_sep_nbr(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s != c && *s)
		{
			count++;
			while (*s != c && *s)
				s++;
		}
	}
	return (count + 1);
}

char	*create_malloc(char **tab, int length)
{
	*tab = malloc((length + 1) * sizeof(char));
	if (!*tab)
		return (NULL);
	return (*tab);
}

char	**ft_freeall(char **tab, int length)
{
	int	i;

	i = 0;
	while (i < length)
		free(tab[i++]);
	free(tab);
	return (0);
}

char	**ft_split(char const *s, char c)
{
	t_split	all;

	if (!s)
		return (0);
	all.sep = get_sep_nbr(s, c);
	all.tab = malloc(all.sep * sizeof(char *));
	if (!all.tab)
		return (NULL);
	all.i = 0;
	while (all.i < all.sep - 1)
	{
		all.j = 0;
		while (*s && *s == c)
			s++;
		all.length = next_word_length(s, c);
		if (!create_malloc(&all.tab[all.i], all.length))
			return (ft_freeall(all.tab, all.i));
		while (all.j < all.length)
			all.tab[all.i][all.j++] = *s++;
		all.tab[all.i++][all.j] = 0;
	}
	all.tab[all.i] = 0;
	return (all.tab);
}