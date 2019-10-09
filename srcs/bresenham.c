/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bresenham.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:14:40 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/09 18:08:56 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	bresenham(t_env *fdf,int x0, int y0, int x1, int y1)
{
	int deltax = x1 - x0;
    int deltay = y1 - y0;
    int deltaerr = ft_abs(deltay / deltax);	// Assume deltax != 0 (line is not vertical),
           					// note that this division needs to be done in a way that preserves the fractional part
    int error = 0.0; 		// No error at start
    int y = y0;
	int	x = x0;
	while (x < x1)
	{ 
         //mlx_pixel_put(mlx->id, mlx->win, x, y, 0xFFFFFF);
		 fdf->data[y * WIN_W + x] = 0xFFFFFF;  //[current height * max width + current width]
         error = error + deltaerr;
         if (error >= 0.5)
		 {
             y = y + ft_sign(deltay) * 1;
             error = error - 1.0;
		 }
		 x++;
	}
} 