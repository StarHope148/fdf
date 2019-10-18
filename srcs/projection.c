/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:19:32 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/18 15:05:02 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_pro		**ft_malloc_t_pro(t_env *fdf)
{
	t_pro		**vtab;
	int			r;

	if ((vtab = (t_pro **)ft_memalloc(sizeof(t_pro *) * fdf->map.nbl)) == NULL)
		return (NULL);
	r = 0;
	while (r < fdf->map.nbl)
	{
		if ((vtab[r] = (t_pro *)ft_memalloc(sizeof(t_pro)
						* fdf->map.nbcol)) == NULL)
			return (NULL);
		r++;
	}
	return (vtab);
}

void		ft_iso(t_env *fdf)
{
	int		r;
	int		c;

	r = 0;
	while (r < fdf->map.nbl)
	{
		c = 0;
		while (c < fdf->map.nbcol)
		{
			fdf->pro[r][c].px = fdf->cx * 2 + ((fdf->map.tab[r][c].x
								- fdf->map.tab[r][c].y) * cos(fdf->ang))
								* fdf->fl * 0.01 + fdf->cx;
			fdf->pro[r][c].py = fdf->cy * 2 + (-fdf->map.tab[r][c].z * fdf->el
								+ ((fdf->map.tab[r][c].x + fdf->map.tab[r][c].y)
								* sin(fdf->ang))) * fdf->fl * 0.01 + fdf->cy;
			c++;
		}
		r++;
	}
}

void		ft_ortho(t_env *fdf)
{
	int		r;
	int		c;

	r = 0;
	while (r < fdf->map.nbl)
	{
		c = 0;
		while (c < fdf->map.nbcol)
		{
			if (fdf->map.tab[r][c].z == 0
				|| fdf->map.tab[r][c].z + fdf->dist == 0)
				fdf->map.tab[r][c].z += 1;
			fdf->pro[r][c].px = fdf->cx + (((fdf->map.tab[r][c].x * fdf->fl)
								+ fdf->dist)) / 100;
			fdf->pro[r][c].py = fdf->cy + (((fdf->map.tab[r][c].y * fdf->fl)
								+ fdf->dist)) / 100;
			c++;
		}
		r++;
	}
}
