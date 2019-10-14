/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:19:32 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/14 16:47:51 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_iso(t_env *fdf)
{
	int		r;
	int		c;
	int		nextx;
	int		nexty;

	r = 0;
	while (r < fdf->map.nbl)
	{
		c = 0;
		while (c < fdf->map.nbcol)
		{
			nextx = (fdf->pro[r][c].px - fdf->pro[r][c].py) * fdf->fl + fdf->cx;
			nexty = ((fdf->pro[r][c].px + fdf->pro[r][c].py) / 2) * fdf->fl + fdf->cy;
			fdf->pro[r][c].px = nextx;
			fdf->pro[r][c].py = nexty;
			c++;
		}
		r++;
	}
}

int			ft_3d_2d(t_env *fdf)
{
	int		r;
	int		c;

	r = 0;
	while (r < fdf->map.nbl)
	{
		c = 0;
		while (c < fdf->map.nbcol)
		{
			if(fdf->map.tab[r][c].z == 0 || fdf->map.tab[r][c].z + fdf->dist == 0)
				fdf->map.tab[r][c].z += 1;
			fdf->pro[r][c].px = fdf->cx + ((fdf->map.tab[r][c].x * fdf->fl) / (fdf->map.tab[r][c].z + fdf->dist));
			fdf->pro[r][c].py = fdf->cy + ((fdf->map.tab[r][c].y * fdf->fl) / (fdf->map.tab[r][c].z + fdf->dist));
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