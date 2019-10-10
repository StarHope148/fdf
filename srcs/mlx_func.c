/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:10:29 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/10 14:31:08 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			ft_mlx(t_env *fdf)
{
	if ((fdf->mlx_ptr = mlx_init()) == NULL)
		return (-1);
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, WIN_W, WIN_H, "FDF");
	if (fdf->win_ptr == NULL)
		return (-1);
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, WIN_W, WIN_H);
	fdf->data = (int *)mlx_get_data_addr(fdf->img_ptr, &fdf->bpp, &fdf->size_l, &fdf->endian);
	mlx_key_hook(fdf->win_ptr, ft_key_hook, fdf);

	//ft_link_points(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);

	mlx_loop(fdf->mlx_ptr);
	return (0);
}