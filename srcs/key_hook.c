/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:41:09 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/13 17:02:19 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_reprint(t_env *fdf)
{
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, fdf->width, fdf->height);
	fdf->data = (int *)mlx_get_data_addr(fdf->img_ptr, &fdf->bpp, &fdf->size_l, &fdf->endian);
	ft_link_points(fdf);
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	mlx_destroy_image(fdf->mlx_ptr, fdf->img_ptr);
	return (0);
}

void 	ft_move(int keycode, t_env *fdf)
{
	if (keycode == LEFT_ARROW)
	{
		fdf->cx -=10;
		ft_link_points(fdf);
	}
	else if (keycode == RIGHT_ARROW)
	{
		fdf->cx += 10;
		ft_link_points(fdf);
	}
	else if (keycode == UP_ARROW)
	{
		fdf->cy -= 10;
		ft_link_points(fdf);
	}
	else if (keycode == DOWN_ARROW)
	{
		fdf->cy += 10;
		ft_link_points(fdf);
	}
}

int		ft_key_hook(int keycode, t_env *fdf)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == LEFT_ARROW || keycode == RIGHT_ARROW ||
			 keycode == UP_ARROW || keycode == DOWN_ARROW)
		ft_move(keycode, fdf);
	else if (keycode == E)
	{
		ft_rotate_z(fdf, 0.1);
		ft_link_points(fdf);
	}
	else
		ft_putnbr(keycode);
		ft_putstr(" ");
	ft_reprint(fdf);
	return (0);
}
