/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 14:41:21 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/10 16:54:52 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static t_vertex		**ft_malloc_tab(t_env *fdf)
{
	t_vertex	**vtab;
	int			i;

	if ((vtab = malloc(sizeof(t_vertex *) * fdf->map.nbl)) == NULL)
		return (NULL);
	i = 0;
	while (i < fdf->map.nbl)
	{
		if ((vtab[i] = malloc(sizeof(t_vertex) * fdf->map.nbcol)) == NULL)
			return (NULL);
		i++;
	}
	return (vtab);
}

int					ft_fill_map(t_env *fdf, char *filename)
{
	char		*line;
	char		**split;
	int			fd;
//	int			a = 0;

	fd = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (-1);
	if ((fdf->map.tab = ft_malloc_tab(fdf)) == NULL)
		return (-1);
	while (get_next_line(fd, &line) == 1)
	{
		printf("FILL = %s\n", line);						//DEBUG
		split = NULL;
		split = ft_strsplit(line, ' ');
/* 		a = 0;
		while (split[a])
		{
			printf("---SPLIT[%d] = %s\n", a, split[a]);
			a++;
		} */
		fdf->map.x = 0;
		while (fdf->map.x < fdf->map.nbcol)
		{
			fdf->map.tab[fdf->map.y][fdf->map.x].z = ft_atoi(split[fdf->map.x]);
			free(split[fdf->map.x]);
			fdf->map.x++;
		}
		free(split);
		fdf->map.y++;
	}
	if (fdf->map.y != fdf->map.nbl)
		return (-1);
	if ((close(fd)) == -1)
		return (-1);
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

int			ft_create_map(t_env *fdf, char *filename)
{
	if ((ft_count_lines_columns(fdf, filename)) == -1)
		return (-1);
	printf("nb lignes = %d\tnb colonnes = %d\n", fdf->map.nbl, fdf->map.nbcol);			//DEBUG
	if ((ft_fill_map(fdf, filename)) == -1)
		return (-1);
	return (0);
}