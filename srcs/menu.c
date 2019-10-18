/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:17:05 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/18 15:00:59 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_print_color_setup(t_env *fdf)
{
	if (fdf->colormod == DEFAULT_MAP_COLOR)
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 20, WHITE,
						"Color setup: Default map color");
	else if (fdf->colormod == CARTOGARPHY)
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 20, WHITE,
						"Color setup: Cartographic visualization");
	else if (fdf->colormod == CONTRAST)
		mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, 20, 20, WHITE,
			"Color setup: Contrast leveling [<0 cyan | =0 white | >0 green]");
}

int			ft_backmenu(t_env *fdf)
{
	int			i;

	fdf->menu.backmenu_ptr = mlx_new_image(fdf->mlx_ptr, 340, 180);
	if (fdf->menu.backmenu_ptr == NULL)
		return (-1);
	fdf->menu.menu_data = (int *)mlx_get_data_addr(fdf->menu.backmenu_ptr,
										&fdf->bpp, &fdf->size_l, &fdf->endian);
	i = 0;
	while (i < 340 * 180)
	{
		fdf->menu.menu_data[i] = fdf->menu.color;
		i++;
	}
	mlx_put_image_to_window(fdf->mlx_ptr, fdf->win_ptr, fdf->menu.backmenu_ptr,
							fdf->width - 355, 20);
	return (0);
}

int			ft_print_menu(t_env *fdf)
{
	if (ft_backmenu(fdf) == -1)
		return (-1);
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, fdf->width - 350, 20, BLACK,
					"---------------------------------");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, fdf->width - 350, 40, BLACK,
					"| move                 [arrows] |");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, fdf->width - 350, 60, BLACK,
					"| scale                 [1]/[2] |");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, fdf->width - 350, 80, BLACK,
					"| elevate               [7]/[8] |");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, fdf->width - 350, 100, BLACK,
					"| switch COLOR              [3] |");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, fdf->width - 350, 120, BLACK,
					"| switch PROJECTION         [0] |");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, fdf->width - 350, 140, BLACK,
					"| rotate X axis         [9]/[6] |");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, fdf->width - 350, 160, BLACK,
					"| move                 [arrows] |");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, fdf->width - 350, 180, BLACK,
					"---------------------------------");
	return (0);
}
