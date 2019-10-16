/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:14:40 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/16 17:41:20 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	bresenham(t_env *fdf, int color)
{
	fdf->dx = ft_abs(fdf->pix.xnext - fdf->pix.xcur);
	fdf->sx = fdf->pix.xcur < fdf->pix.xnext ? 1 : -1;
	fdf->dy = -(ft_abs(fdf->pix.ynext - fdf->pix.ycur));
	fdf->sy = fdf->pix.ycur < fdf->pix.ynext ? 1 : -1;
	fdf->err = fdf->dx + fdf->dy;
	while (1)
	{
		if ((fdf->pix.ycur * fdf->width + fdf->pix.xcur < fdf->width
				* fdf->height) && (fdf->pix.ycur >= 0 && fdf->pix.xcur >= 0)
				&& (fdf->pix.ycur < fdf->height && fdf->pix.xcur < fdf->width))
			fdf->data[fdf->pix.ycur * fdf->width + fdf->pix.xcur] = color;
		if (fdf->pix.xcur == fdf->pix.xnext && fdf->pix.ycur == fdf->pix.ynext)
			break ;
		fdf->e2 = 2 * fdf->err;
		if (fdf->e2 >= fdf->dy)
		{
			fdf->err += fdf->dy;
			fdf->pix.xcur += fdf->sx;
		}
		if (fdf->e2 <= fdf->dx)
		{
			fdf->err += fdf->dx;
			fdf->pix.ycur += fdf->sy;
		}
	}
}
