/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:20:17 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/18 20:54:33 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_print(t_env *fdf)
{
 	if (fdf->img_ptr == NULL)
	{
		fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, fdf->width, fdf->height);
		if (fdf->img_ptr == NULL)
			return (-1);
		fdf->data = (int *)mlx_get_data_addr(fdf->img_ptr, &fdf->bpp,
												&fdf->size_l, &fdf->endian);
		if (fdf->data == NULL)
			return (-1);
	}
	ft_bzero(fdf->data, fdf->width * fdf->height * 4);
	//mlx_clear_window(fdf->mlx_ptr, fdf->win_ptr);
	if (ft_link_points(fdf) == -1)
		return (-1);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	if (ft_print_menu(fdf) == -1)
		return (-1);
	ft_print_color_setup(fdf);
	return (0);
}

void	ft_link_right(t_env *fdf, int r, int c)
{
	fdf->pix.xcur = fdf->pro[r][c].px;
	fdf->pix.ycur = fdf->pro[r][c].py;
	fdf->pix.xnext = fdf->pro[r][c + 1].px;
	fdf->pix.ynext = fdf->pro[r][c + 1].py;
	bresenham(fdf, fdf->map.tab[r][c].color);
}

void	ft_link_down(t_env *fdf, int r, int c)
{
	fdf->pix.xcur = fdf->pro[r][c].px;
	fdf->pix.ycur = fdf->pro[r][c].py;
	fdf->pix.xnext = fdf->pro[r + 1][c].px;
	fdf->pix.ynext = fdf->pro[r + 1][c].py;
	bresenham(fdf, fdf->map.tab[r][c].color);
}

int		ft_link_points(t_env *fdf)
{
	int		r;
	int		c;

	if (fdf->pro == NULL)
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
				ft_link_right(fdf, r, c);
			if (r + 1 < fdf->map.nbl)
				ft_link_down(fdf, r, c);
			c++;
		}
		r++;
	}
	return (0);
}
