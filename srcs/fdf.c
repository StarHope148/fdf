/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:04:58 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/06 18:12:23 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_init_struct(t_env *fdf)
{
	fdf->mlx_ptr = NULL;
	fdf->win_ptr = NULL;
	fdf->img_ptr = NULL;
	fdf->data = NULL;
	fdf->bpp = 0;
	fdf->size_l = 0;
	fdf->endian = 0;
	fdf->map.x = 0;
	fdf->map.y = 0;
	fdf->map.nbl = 0;
	fdf->map.nbcol = 0;
	fdf->map.map = NULL;
}

int			ft_fdf(char *filename)
{
	t_env		fdf;

	ft_init_struct(&fdf);
	if ((ft_create_map(&fdf, filename)) == -1)
		return (-1);
	return (0);
}
//create the map the array of t_point
//display it with MLX
//free it