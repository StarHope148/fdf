/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 17:19:32 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/10 17:55:24 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_3d_2d(t_env *fdf, int x, int y, int z)
{
	if(z == 0)
		z = 1;
   	fdf->map.x = 10 * x / z;
   	fdf->map.y = 10 * y / z;
}