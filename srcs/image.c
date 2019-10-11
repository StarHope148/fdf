/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:20:17 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/11 15:18:54 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_link_points(t_env *fdf)
{
/* 	fdf->map.y = 0;
	while (fdf->map.y < fdf->map.nbl)
	{
		fdf->map.x = 0;
		while (fdf->map.x < fdf->map.nbcol)
		{
			bresenham(fdf, fdf->map.x * SCL, fdf->map.y * SCL, fdf->map.x + 1 * SCL, fdf->map.y * SCL);
			bresenham(fdf, fdf->map.x * SCL, fdf->map.y * SCL, fdf->map.x * SCL, fdf->map.y + 1 * SCL);
			fdf->map.x++;
		}
		fdf->map.y++;
	} */

	int		r;
	int		c;

	r = 0;
	while (r < fdf->map.nbl)
	{
		c = 0;
		while (c < fdf->map.nbcol)
		{
			//ft_3d_2d(fdf, fdf->map.tab[r][c].x, fdf->map.tab[r][c].y, fdf->map.tab[r][c].z);
			if (c + 1 < fdf->map.nbcol)
				bresenham(fdf, fdf->map.tab[r][c].x * SCL, fdf->map.tab[r][c].y * SCL, fdf->map.tab[r][c + 1].x * SCL, fdf->map.tab[r][c + 1].y * SCL);
			if (r + 1 < fdf->map.nbl)
				bresenham(fdf, fdf->map.tab[r][c].x * SCL, fdf->map.tab[r][c].y * SCL, fdf->map.tab[r + 1][c].x * SCL, fdf->map.tab[r + 1][c].y * SCL);
			c++;
		}
		r++;
	}
}