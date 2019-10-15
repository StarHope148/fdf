/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:41:09 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/15 19:27:49 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_move(int keycode, t_env *fdf)
{
	if (keycode == LEFT_ARROW)
		fdf->cx -= 4;
	else if (keycode == RIGHT_ARROW)
		fdf->cx += 4;
	else if (keycode == UP_ARROW)
		fdf->cy -= 4;
	else if (keycode == DOWN_ARROW)
		fdf->cy += 4;
}

void	ft_zoom(int keycode, t_env *fdf)
{
	if (keycode == ONE_NUM_PAD)
		fdf->fl *= 1.05;
	else if (keycode == TWO_NUM_PAD)
		fdf->fl *= 0.952380;
}

void	ft_distance(int keycode, t_env *fdf)
{
	if (keycode == FIVE_NUM_PAD)
		fdf->dist += 1;
	else if (keycode == FOUR_NUM_PAD)
		fdf->dist -= 1;
}

void	ft_elevation(int keycode, t_env *fdf)
{
	if (keycode == SEVEN_NUM_PAD)
		fdf->el += 0.01;
	else if (keycode == EIGHT_NUM_PAD)
		fdf->el = (fdf->el <= 0.01) ? 0 : fdf->el - 0.01;
}

void	ft_rotate(int keycode, t_env *fdf)
{
	if (keycode == NINE_NUM_PAD)
		fdf->ang += 0.01;
	else
		fdf->ang -= 0.01;
}

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
	else if (keycode == I)
	{
		fdf->projection_mod = (fdf->projection_mod == 0 ? 1 : 0);
		fdf->cx = CX_O + fdf->projection_mod * 100;
		fdf->cy = CY_O + fdf->projection_mod * 250;
	}
	else if (keycode == THREE_NUM_PAD)
		ft_switch_color(fdf);
	else
	{
		ft_putnbr(keycode);
		ft_putstr(" ");
	}
	ft_link_points(fdf);
	ft_reprint(fdf);
	return (0);
}
