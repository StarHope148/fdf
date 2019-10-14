/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:10:29 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/14 15:48:19 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_pro		**ft_malloc_t_pro(t_env *fdf)
{
	t_pro	**vtab;
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
	return (vtab);
}

int			ft_mlx(t_env *fdf)
{
	if ((fdf->mlx_ptr = mlx_init()) == NULL)
		return (-1);
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->width, fdf->height, "FDF");
	if (fdf->win_ptr == NULL)
		return (-1);
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, fdf->width, fdf->height);
	fdf->data = (int *)mlx_get_data_addr(fdf->img_ptr, &fdf->bpp, &fdf->size_l, &fdf->endian);
	mlx_key_hook(fdf->win_ptr, ft_key_hook, fdf);

	if ((fdf->pro = ft_malloc_t_pro(fdf)) == NULL)
		return (-1);
	if (ft_link_points(fdf) == -1)
		return (-1);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);

	mlx_loop(fdf->mlx_ptr);
	return (0);
}