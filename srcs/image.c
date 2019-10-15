/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:20:17 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/15 19:28:56 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_reprint(t_env *fdf)
{
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, fdf->width, fdf->height);
	fdf->data = (int *)mlx_get_data_addr(fdf->img_ptr, &fdf->bpp,
											&fdf->size_l, &fdf->endian);
	ft_link_points(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	ft_print_menu(fdf);
	return (0);
}

int		ft_link_points(t_env *fdf)
{
	int		r;
	int		c;

	if ((fdf->pro = ft_malloc_t_pro(fdf)) == NULL)
		return (-1);
	if (fdf->projection_mod == 0)
		ft_iso(fdf);
	else
		ft_ortho(fdf);
	r = 0;
	while (r < fdf->map.nbl)
	{
		c = 0;
		while (c < fdf->map.nbcol)
		{
			if (c + 1 < fdf->map.nbcol)
			{
				fdf->pix.xcur = fdf->pro[r][c].px;
				fdf->pix.ycur = fdf->pro[r][c].py;
				fdf->pix.xnext = fdf->pro[r][c + 1].px;
				fdf->pix.ynext = fdf->pro[r][c + 1].py;
				bresenham(fdf, fdf->map.tab[r][c].color);
			}
			if (r + 1 < fdf->map.nbl)
			{
				fdf->pix.xcur = fdf->pro[r][c].px;
				fdf->pix.ycur = fdf->pro[r][c].py;
				fdf->pix.xnext = fdf->pro[r + 1][c].px;
				fdf->pix.ynext = fdf->pro[r + 1][c].py;
				bresenham(fdf, fdf->map.tab[r][c].color);
			}
			c++;
		}
		r++;
	}
	return (0);
}
