/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_start_up.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 14:10:29 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/21 16:20:13 by jcanteau         ###   ########.fr       */
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
	if (ft_print(fdf) == -1)
		return (-1);
	mlx_hook(fdf->win_ptr, 2, (1L << 0), ft_key_hook, fdf);
	mlx_loop(fdf->mlx_ptr);
	return (0);
}
