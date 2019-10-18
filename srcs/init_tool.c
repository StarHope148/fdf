/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tool.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:23:19 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/18 16:36:43 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void		ft_init_map(t_env *fdf)
{
	fdf->map.c = 0;
	fdf->map.r = 0;
	fdf->map.nbl = 0;
	fdf->map.nbcol = 0;
	fdf->map.min = 0;
	fdf->map.max = 0;
	fdf->map.tab = NULL;
}

void		ft_init_menu(t_env *fdf)
{
	fdf->menu.backmenu_ptr = NULL;
	fdf->menu.menu_data = NULL;
	fdf->menu.width = 340;
	fdf->menu.height = 180;
	fdf->menu.pos_x = 355;
	fdf->menu.pos_y = 20;
	fdf->menu.color = SILVER;
}

void		ft_init_bresenham(t_env *fdf)
{
	fdf->dx = 0;
	fdf->sx = 0;
	fdf->dy = 0;
	fdf->sy = 0;
	fdf->err = 0;
	fdf->e2 = 0;
}

void		ft_init_display(t_env *fdf)
{
	fdf->projection_mod = 0;
	fdf->cx = CX_O;
	fdf->cy = CY_O;
	fdf->fl = 4000;
	fdf->el = 0.1;
	fdf->dist = 50;
	fdf->colormod = 0;
	fdf->ang = 0.523599;
	fdf->pro = NULL;
}

void		ft_init_segment_drawing_coordinate(t_env *fdf)
{
	fdf->pix.xcur = 0;
	fdf->pix.ycur = 0;
	fdf->pix.xnext = 0;
	fdf->pix.ynext = 0;
}
