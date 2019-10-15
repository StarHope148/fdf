/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 19:17:05 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/15 19:37:31 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_print_menu(t_env *fdf)
{
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, fdf->width - 220, 20, WHITE,
					"====================");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, fdf->width - 220, 40, WHITE,
					"| move    [arrows] |");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, fdf->width - 220, 60, WHITE,
					"| scale    [1]/[2] |");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, fdf->width - 220, 80, WHITE,
					"| elevate  [7]/[8] |");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, fdf->width - 220, 100, WHITE,
					"| switch color [3] |");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, fdf->width - 220, 120, WHITE,
					"| move    [arrows] |");
	mlx_string_put(fdf->mlx_ptr, fdf->win_ptr, fdf->width - 220, 140, WHITE,
					"====================");
}
