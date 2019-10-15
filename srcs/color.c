/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 20:32:58 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/15 18:26:00 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void			ft_contrast_level(t_env* fdf)
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
				fdf->map.tab[r][c].color = GREEN;
			else if (fdf->map.tab[r][c].z >= 1)
				fdf->map.tab[r][c].color = WHITE;
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
			if (fdf->map.tab[r][c].z < 0)
				fdf->map.tab[r][c].color = BLUE;
			else if (fdf->map.tab[r][c].z == 0)
				fdf->map.tab[r][c].color = SAND;
			else if (fdf->map.tab[r][c].z >= 1 && fdf->map.tab[r][c].z < 10)
				fdf->map.tab[r][c].color = GREEN;
			else if (fdf->map.tab[r][c].z >= 10 && fdf->map.tab[r][c].z < 40)
				fdf->map.tab[r][c].color = TEAL;		
			else if (fdf->map.tab[r][c].z >= 40 && fdf->map.tab[r][c].z < 80)
				fdf->map.tab[r][c].color = BROWN;				
			else if (fdf->map.tab[r][c].z >= 80)
				fdf->map.tab[r][c].color = WHITE;
			c++;
		}
		r++;
	}
}

void			ft_color_choice(t_env *fdf)
{
	if (fdf->colormod == 0)
		ft_map_real(fdf);
	else if (fdf->colormod == 1)
		ft_default_color(fdf);
	else if (fdf->colormod == 2)
		ft_contrast_level(fdf);
}

static int		ft_ishex(char c)
{
	const char		*digits = "0123456789ABCDEF";
	int				i;

	i = 0;
	while (i < 16)
	{
		if (c == ' ')
			return (-1);
		if (digits[i] == ft_toupper(c))
			return (i);
		i++;
	}
	return (-1);
}

int				ft_ahextoi(char *str)
{
	unsigned long	result;
	size_t			i;

	result = 0;
	i = 0;
	while (ft_ishex(str[i]) >= 0)
	{
		result = result * 16 + ft_ishex(str[i]);
		i++;
	}
	return ((int)result);
}

void			ft_color_fill(t_env *fdf, char *split, int x, int y)
{
	if (ft_strchr(split, ',') != NULL)
	{
		fdf->map.tab[y][x].defcolor = ft_ahextoi(ft_strchr(split, 'x') + 1);
		fdf->map.tab[y][x].color = fdf->map.tab[y][x].defcolor;
	}
	else
	{
		fdf->map.tab[y][x].color = WHITE;
		fdf->map.tab[y][x].defcolor = WHITE;
	}
}
