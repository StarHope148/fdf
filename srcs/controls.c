/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 16:52:55 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/21 16:37:06 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_move(int keycode, t_env *fdf)
{
	if (fdf->projection_mod == ISO)
	{
		if (keycode == LEFT_ARROW)
			fdf->cx -= MOVE_SPEED;
		else if (keycode == RIGHT_ARROW)
			fdf->cx += MOVE_SPEED;
		else if (keycode == UP_ARROW)
			fdf->cy -= MOVE_SPEED;
		else if (keycode == DOWN_ARROW)
			fdf->cy += MOVE_SPEED;
	}
	else if (fdf->projection_mod == ORTHO)
	{
		if (keycode == LEFT_ARROW)
			fdf->cx -= MOVE_SPEED / 2;
		else if (keycode == RIGHT_ARROW)
			fdf->cx += MOVE_SPEED / 2;
		else if (keycode == UP_ARROW)
			fdf->cy -= MOVE_SPEED / 2;
		else if (keycode == DOWN_ARROW)
			fdf->cy += MOVE_SPEED / 2;
	}
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
		fdf->el -= 0.01;
}

void	ft_rotate(int keycode, t_env *fdf)
{
	if (keycode == NINE_NUM_PAD)
		fdf->ang += 0.03;
	else if (keycode == SIX_NUM_PAD)
		fdf->ang -= 0.03;
}
