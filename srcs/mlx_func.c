/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:10:29 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/15 19:29:00 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"



int				ft_mlx(t_env *fdf)
{
	if ((fdf->mlx_ptr = mlx_init()) == NULL)
		return (-1);
	fdf->win_ptr = mlx_new_window(fdf->mlx_ptr, fdf->width,
									fdf->height, "FDF");
	if (fdf->win_ptr == NULL)
		return (-1);
	fdf->img_ptr = mlx_new_image(fdf->mlx_ptr, fdf->width, fdf->height);
	fdf->data = (int *)mlx_get_data_addr(fdf->img_ptr, &fdf->bpp,
											&fdf->size_l, &fdf->endian);
	mlx_hook(fdf->win_ptr, 2, 0, ft_key_hook, fdf);
	if (ft_link_points(fdf) == -1)
		return (-1);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, fdf->height - 200, 220, WHITE, "elevate  [7]/[8]");
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->img_ptr, 0, 0);
	ft_print_menu(fdf);

	mlx_loop(fdf->mlx_ptr);
	return (0);
}
