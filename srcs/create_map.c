/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 14:41:21 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/07 16:19:47 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_fill_map(t_env *fdf, char *filename)
{
	char		*line;
	char		**split;
	int			fd;

	fd = 0;
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (-1);
	if ((fdf->map.map = ft_tab2d_new(fdf->map.nbcol, fdf->map.nbl)) == NULL)
		return (-1);
	fdf->map.y = 0;
	while (get_next_line(fd, &line) > 0)
	{
		printf("FILL = %s\n", line);						//DEBUG
		fdf->map.x = 0;
		split = ft_strsplit(line, ' ');
		while (fdf->map.x < (int)fdf->map.nbcol)
		{
			fdf->map.map[fdf->map.y][fdf->map.x] = ft_atoi(split[fdf->map.x]);
			fdf->map.x++;
			free(split[fdf->map.x]);
		}
		fdf->map.y++;
	}
	if ((close(fd)) == -1)
		return (-1);
	return (0);
}

int		ft_count_lines_columns(t_env *fdf, char *filename)
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
	printf("nb lignes = %zu\tnb colonnes = %zu\n", fdf->map.nbl, fdf->map.nbcol);			//DEBUG
	if ((ft_fill_map(fdf, filename)) == -1)
		return (-1);
	return (0);
}