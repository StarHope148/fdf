/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:32:45 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/29 14:37:03 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_vertex		**ft_malloc_tab(t_env *fdf)
{
	t_vertex	**vtab;
	int			i;

	if ((vtab = (t_vertex **)ft_memalloc(sizeof(t_vertex *)
			* fdf->map.nbl)) == NULL)
		return (NULL);
	i = 0;
	while (i < fdf->map.nbl)
	{
		if ((vtab[i] = (t_vertex *)ft_memalloc(sizeof(t_vertex)
				* fdf->map.nbcol)) == NULL)
			return (NULL);
		i++;
	}
	return (vtab);
}

static int		ft_ishex(char c)
{
	const char		*digits = "0123456789ABCDEF";
	int				i;

	i = 0;
	while (i < 16)
	{
		if (c == ' ')
			return (-1);
		if (digits[i] == ft_toupper(c))
			return (i);
		i++;
	}
	return (-1);
}

int				ft_ahextoi(char *str)
{
	unsigned long	result;
	size_t			i;

	result = 0;
	i = 0;
	while (ft_ishex(str[i]) >= 0)
	{
		result = result * 16 + ft_ishex(str[i]);
		i++;
	}
	return ((int)result);
}

int				ft_color_fill(t_env *fdf, char *split, int x, int y)
{
	if (ft_strchr(split, ',') != NULL)
	{
		if (ft_strchr(split, 'x') == NULL)
			return (-1);
		fdf->map.tab[y][x].defcolor = ft_ahextoi(ft_strchr(split, 'x') + 1);
		fdf->map.tab[y][x].color = fdf->map.tab[y][x].defcolor;
	}
	else
	{
		fdf->map.tab[y][x].color = WHITE;
		fdf->map.tab[y][x].defcolor = WHITE;
	}
	return (0);
}

int				ft_parsing_fail(t_env *fdf)
{
	int		r;

	r = 0;
	while (r < fdf->map.nbl)
	{
		free(fdf->map.tab[r]);
		r++;
	}
	free(fdf->map.tab);
	return (-6);
}
