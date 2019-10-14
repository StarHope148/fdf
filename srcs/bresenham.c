/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:14:40 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/14 18:35:56 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	  bresenham(t_env *fdf, int x0, int y0, int x1, int y1)
{
	int dx =  ft_abs(x1 - x0);
	int sx = x0 < x1 ? 1 : -1;
	int dy = -(ft_abs(y1 - y0));
	int sy = y0 < y1 ? 1 : -1;
	int err = dx + dy;  /* error value e_xy */
	int	e2;
	while (1)
	{   /* loop */
		if ((y0 * fdf->width + x0 < fdf->width * fdf->height) 
				&& (y0 >= 0 && x0 >= 0) 
				&& (y0 < fdf->height && x0 < fdf->width))
			fdf->data[y0 * fdf->width + x0] = 0xFFFFFF;  //[current height * max width + current width]
		if (x0 == x1 && y0 == y1)
			 break;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy; /* e_xy+e_x > 0 */
			x0 += sx;
		}
		if (e2 <= dx) /* e_xy+e_y < 0 */
		{
			err += dx;
			y0 += sy;
		}
	}
}
