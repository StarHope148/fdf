/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:20:17 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/13 18:29:04 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/* void	ft_rotate_z(t_env *fdf, double val)
{
	int		r;
	int		c;
	double	nextx;
	double 	nexty;
	double	ang;

	ang = 0 + val;
	r = 0;
	while (r < fdf->map.nbl)
	{
		c = 0;
		while (c < fdf->map.nbcol)
		{
			nextx = (cos(ang) * fdf->pro[r][c].xx) - (sin(ang) * fdf->pro[r][c].yy);
			nexty = (sin(ang) * fdf->pro[r][c].xx) + (cos(ang) * fdf->pro[r][c].yy);
			fdf->pro[r][c].xx = nextx;
			fdf->pro[r][c].yy = nexty;
			
			xx = (cos(a)*x) - (sin(a)*y)
			yy = (sin(a)*x) + (cos(a)*y) 
			
			c++;
		}
		r++;
	}
} */

int		ft_reprint(t_env *fdf)
{
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, fdf->width, fdf->height);
	fdf->data = (int *)mlx_get_data_addr(fdf->img_ptr, &fdf->bpp, &fdf->size_l, &fdf->endian);
	ft_link_points(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	return (0);
}

int		ft_link_points(t_env *fdf)
{
	int		r;
	int		c;

	if ((ft_3d_2d(fdf)) == -1)
		return (-1);
	r = 0;
	while (r < fdf->map.nbl)
	{
		c = 0;
		while (c < fdf->map.nbcol)
		{
			if (c + 1 < fdf->map.nbcol)
				bresenham(fdf, fdf->pro[r][c].px, fdf->pro[r][c].py, fdf->pro[r][c + 1].px, fdf->pro[r][c + 1].py);
			if (r + 1 < fdf->map.nbl)
				bresenham(fdf, fdf->pro[r][c].px, fdf->pro[r][c].py, fdf->pro[r + 1][c].px, fdf->pro[r + 1][c].py);
			c++;

		}
		r++;
	}
	return (0);
}