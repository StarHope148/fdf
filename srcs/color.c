/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 20:32:58 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/16 17:45:29 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			ft_contrast_level(t_env *fdf)
{
	int				r;
	int				c;

	r = 0;
	while (r < fdf->map.nbl)
	{
		c = 0;
		while (c < fdf->map.nbcol)
		{
			if (fdf->map.tab[r][c].z < 0)
				fdf->map.tab[r][c].color = CYAN;
			else if (fdf->map.tab[r][c].z == 0)
				fdf->map.tab[r][c].color = WHITE;
			else if (fdf->map.tab[r][c].z >= 1)
				fdf->map.tab[r][c].color = GREEN;
			c++;
		}
		r++;
	}
}

void			ft_default_color(t_env *fdf)
{
	int				r;
	int				c;

	r = 0;
	while (r < fdf->map.nbl)
	{
		c = 0;
		while (c < fdf->map.nbcol)
		{
			fdf->map.tab[r][c].color = fdf->map.tab[r][c].defcolor;
			c++;
		}
		r++;
	}
}

void			ft_map_real_2(t_env *fdf, int r, int c)
{
	if (fdf->map.tab[r][c].z >= 10 && fdf->map.tab[r][c].z < 20)
		fdf->map.tab[r][c].color = DARK_GREEN;
	else if (fdf->map.tab[r][c].z >= 20 && fdf->map.tab[r][c].z < 40)
		fdf->map.tab[r][c].color = OLIVE;
	else if (fdf->map.tab[r][c].z >= 40 && fdf->map.tab[r][c].z < 80)
		fdf->map.tab[r][c].color = BROWN;
	else if (fdf->map.tab[r][c].z >= 80)
		fdf->map.tab[r][c].color = WHITE;
}

void			ft_map_real(t_env *fdf)
{
	int				r;
	int				c;

	r = 0;
	while (r < fdf->map.nbl)
	{
		c = 0;
		while (c < fdf->map.nbcol)
		{
			if (fdf->map.tab[r][c].z < 1)
				fdf->map.tab[r][c].color = BLUE;
			else if (fdf->map.tab[r][c].z == 1)
				fdf->map.tab[r][c].color = SAND;
			else if (fdf->map.tab[r][c].z >= 2 && fdf->map.tab[r][c].z < 10)
				fdf->map.tab[r][c].color = GREEN;
			else
				ft_map_real_2(fdf, r, c);
			c++;
		}
		r++;
	}
}

void			ft_color_choice(t_env *fdf)
{
	if (fdf->colormod == DEFAULT_MAP_COLOR)
		ft_default_color(fdf);
	else if (fdf->colormod == CARTOGARPHY)
		ft_map_real(fdf);
	else if (fdf->colormod == CONTRAST)
		ft_contrast_level(fdf);
}
