/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:19:32 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/13 17:01:18 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_pro		**ft_malloc_t_pro(t_env *fdf)
{
	t_pro	**vtab;
	int			c;
	int			r;
	if ((vtab = (t_pro **)ft_memalloc(sizeof(t_pro *) * fdf->map.nbl)) == NULL)
		return (NULL);
	r = 0;
	while (r < fdf->map.nbl)
	{
		if ((vtab[r] = (t_pro *)ft_memalloc(sizeof(t_pro) * fdf->map.nbcol)) == NULL)
			return (NULL);
		r++;
	}
	r = 0;
	while (r < fdf->map.nbl)
	{
		c = 0;
		while (c < fdf->map.nbcol)
		{
			vtab[r][c].xx = fdf->map.tab[r][c].x;
			vtab[r][c].yy = fdf->map.tab[r][c].y;
			vtab[r][c].zz = fdf->map.tab[r][c].z;
			c++;
		}
		r++;
	}
	return (vtab);
}

int					ft_3d_2d(t_env *fdf)
{
	int		r;
	int		c;
	int		test;

	test = 0;
	r = 0;
	if ((fdf->pro = ft_malloc_t_pro(fdf)) == NULL)
		return (-1);
	while (r < fdf->map.nbl)
	{
		c = 0;
		while (c < fdf->map.nbcol)
		{
			if(fdf->map.tab[r][c].z == 0)
				fdf->map.tab[r][c].z = 1;
			fdf->pro[r][c].px = (int)(fdf->cx + ((fdf->map.tab[r][c].x * FL) / (fdf->map.tab[r][c].z)));
			fdf->pro[r][c].py = (int)(fdf->cy + ((fdf->map.tab[r][c].y * FL) / (fdf->map.tab[r][c].z)));
			printf("tab[%d][%d]:\tx = %d | y = %d | z = %d\t\t\t--->\tx' = %d | y' = %d\n", r, c, fdf->map.tab[r][c].x, fdf->map.tab[r][c].y, fdf->map.tab[r][c].z, fdf->pro[r][c].px, fdf->pro[r][c].py);	//DEBUG
			c++;
		}
		r++;
	}
	printf("-----------------------------------------------------\n");
	return (0);
}

/*
px = cx + ((x * f) / (z + 2.5))
py = cy + ((y * f) / (z + 2.5))
 
cx et cy définissent la position centrale du rendu, ils sont égaux à f dans les exemples
px et py sont les coordonnées cartésiennes "compatibles écran" qui serviront à dessiner les points
f est le facteur d'agrandissement, 64 dans les exemples
2.5 est une valeur arbitraire pour rendre Z toujours positif et "avancé devant la caméra", sinon la caméra serait au centre du cube
*/