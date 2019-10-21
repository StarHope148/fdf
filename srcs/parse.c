/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 14:41:21 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/21 16:21:57 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_vertex		**ft_malloc_tab(t_env *fdf)
{
	t_vertex	**vtab;
	int			i;

	if ((vtab = (t_vertex **)ft_memalloc(sizeof(t_vertex *)
			* fdf->map.nbl)) == NULL)
		return (NULL);
	i = 0;
	while (i < fdf->map.nbl)
	{
		if ((vtab[i] = (t_vertex *)ft_memalloc(sizeof(t_vertex)
				* fdf->map.nbcol)) == NULL)
			return (NULL);
		i++;
	}
	return (vtab);
}

void				ft_calc_min_max_z(t_env *fdf)
{
	if (fdf->map.tab[fdf->map.r][fdf->map.c].z < fdf->map.min)
		fdf->map.min = fdf->map.tab[fdf->map.r][fdf->map.c].z;
	if (fdf->map.tab[fdf->map.r][fdf->map.c].z > fdf->map.max)
		fdf->map.max = fdf->map.tab[fdf->map.r][fdf->map.c].z;
}

int					ft_fill_map(t_env *fdf, int fd)
{
	char		*line;
	char		**split;

	while (get_next_line(fd, &line) == 1)
	{
		if ((split = ft_strsplit(line, ' ')) == NULL)
			return (-1);
		free(line);
		fdf->map.c = 0;
		while (fdf->map.c < fdf->map.nbcol)
		{
			fdf->map.tab[fdf->map.r][fdf->map.c].x = fdf->map.c;
			fdf->map.tab[fdf->map.r][fdf->map.c].y = fdf->map.r;
			fdf->map.tab[fdf->map.r][fdf->map.c].z = ft_atoi(split[fdf->map.c]);
			if (ft_color_fill(fdf, split[fdf->map.c], fdf->map.c, fdf->map.r)
					== -1)
				return (-1);
			ft_calc_min_max_z(fdf);
			free(split[fdf->map.c]);
			fdf->map.c++;
		}
		free(split);
		fdf->map.r++;
	}
	return (0);
}

int					ft_count_lines_columns(t_env *fdf, char *filename)
{
	char		*line;
	int			fd;

	fd = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (-1);
	if ((get_next_line(fd, &line)) <= 0)
		return (-1);
	fdf->map.nbcol = ft_split_count(line, ' ');
	free(line);
	fdf->map.nbl++;
	while (get_next_line(fd, &line) > 0)
	{
		fdf->map.nbl++;
		free(line);
	}
	if ((close(fd)) == -1)
		return (-1);
	return (0);
}

int					ft_create_map(t_env *fdf, char *filename)
{
	int			fd;

	if ((ft_count_lines_columns(fdf, filename)) == -1)
		return (-1);
	if ((fdf->map.tab = ft_malloc_tab(fdf)) == NULL)
		return (-1);
	fd = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (-1);
	if ((ft_fill_map(fdf, fd)) == -1)
		return (-1);
	if (fdf->map.r != fdf->map.nbl)
		return (-1);
	if ((close(fd)) == -1)
		return (-1);
	return (0);
}
