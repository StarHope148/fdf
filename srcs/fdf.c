/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 15:04:58 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/16 15:44:56 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"


void		ft_init_struct(t_env *fdf)
{
	fdf->mlx_ptr = NULL;
	fdf->win_ptr = NULL;
	fdf->img_ptr = NULL;
	fdf->data = NULL;
	fdf->width = 2000;
	fdf->height = 1200;
	fdf->bpp = 0;
	fdf->size_l = 0;
	fdf->endian = 0;
	ft_init_map(fdf);
	ft_init_display(fdf);
	ft_init_menu(fdf);
	ft_init_bresenham(fdf);
	ft_init_segment_drawing_coordinate(fdf);
}

void		ft_choose_focal_lenght(t_env *fdf)
{
	long	ref;
	
	ref = fdf->map.nbl * fdf->map.nbcol;
	
	if (ref < 250)
		fdf->fl = 4000;
	else if (ref < 500)
		fdf->fl = 3500;
	else if (ref < 15000)
		fdf->fl = 1000;
	else if (ref < 50000)
		fdf->fl = 500;
	else if (ref > 100000)
		fdf->fl = 200;

}

int			ft_fdf_init(char *filename)
{
	t_env		fdf;

	ft_init_struct(&fdf);
	if (ft_create_map(&fdf, filename) == -1)
		return (-1);
	printf("nbcol = %d\tnbl = %d\n", fdf.map.nbcol, fdf.map.nbl);			//DEBUG
	ft_choose_focal_lenght(&fdf);
	if (ft_mlx(&fdf) == -1)
		return (-1);
	return (0);
}
//create the array of t_vertex
//display it with MLX
//free it
