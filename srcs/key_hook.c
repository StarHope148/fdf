/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_hook.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 15:41:09 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/13 18:40:11 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void 	ft_move(int keycode, t_env *fdf)
{
	if (keycode == LEFT_ARROW)
	{
		fdf->cx -= 20;
		ft_link_points(fdf);
	}
	else if (keycode == RIGHT_ARROW)
	{
		fdf->cx += 20;
		ft_link_points(fdf);
	}
	else if (keycode == UP_ARROW)
	{
		fdf->cy -= 20;
		ft_link_points(fdf);
	}
	else if (keycode == DOWN_ARROW)
	{
		fdf->cy += 20;
		ft_link_points(fdf);
	}
}

void	ft_zoom(int	keycode, t_env *fdf)
{
	if (keycode == ONE_NUM_PAD)
		fdf->fl += 5;
	else if (keycode == TWO_NUM_PAD)
		fdf->fl -= 5;
	ft_link_points(fdf);
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
	else
		ft_putnbr(keycode);
		ft_putstr(" ");
	ft_reprint(fdf);
	return (0);
}
