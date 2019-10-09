/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 18:20:17 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/09 20:04:35 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_link_points(t_env *fdf)
{
	int		curr;
	int		x0;
	int		y0;
	int		x1;
	int		y1;
	int		i;

	i = 0;
	while (curr < fdf->map.nbl - 1)
	{
		/* x0 = fdf->map.map[i].x;
		y0 = fdf->map.map[i].y;							--> browse the array of struct t_vertex and pick x and y coordinate
		x1 = fdf->map.map[i + 1].x;
		y1 = fdf->map.map[i + 1].y; */
		bresenham(fdf, x0, y0, x1, y1);
		curr++;
		i++;
	}
}