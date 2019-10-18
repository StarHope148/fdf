/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:41:09 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/18 15:57:31 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_switch_color(t_env *fdf)
{
	if (fdf->colormod >= 2)
		fdf->colormod = 0;
	else
		fdf->colormod++;
	ft_color_choice(fdf);
}

int		ft_key_hook(int keycode, t_env *fdf)
{
	if (keycode == ESC)
		exit(0);
	else if (keycode == LEFT_ARROW || keycode == RIGHT_ARROW ||
				keycode == UP_ARROW || keycode == DOWN_ARROW)
		ft_move(keycode, fdf);
	else if (keycode == ONE_NUM_PAD || keycode == TWO_NUM_PAD)
		ft_zoom(keycode, fdf);
	else if (keycode == FOUR_NUM_PAD || keycode == FIVE_NUM_PAD)
		ft_distance(keycode, fdf);
	else if (keycode == SEVEN_NUM_PAD || keycode == EIGHT_NUM_PAD)
		ft_elevation(keycode, fdf);
	else if (keycode == NINE_NUM_PAD || keycode == SIX_NUM_PAD)
		ft_rotate(keycode, fdf);
	else if (keycode == ZERO_NUM_PAD)
	{
		fdf->projection_mod = (fdf->projection_mod == 0 ? 1 : 0);
		fdf->cx = CX_O + fdf->projection_mod * 100;
		fdf->cy = CY_O + fdf->projection_mod * 250;
	}
	else if (keycode == THREE_NUM_PAD)
		ft_switch_color(fdf);
	ft_link_points(fdf);
	ft_print(fdf);
	return (0);
}
