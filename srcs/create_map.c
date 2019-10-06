/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 14:41:21 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/06 19:25:38 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_fill_map(t_env *fdf, int fd)
{
	char		*line;
	char		**split;

	if ((fdf->map.map = ft_tab2d_new(fdf->map.nbcol, fdf->map.nbl)) == NULL)
		return (-1);
	fdf->map.y = 0;
	get_next_line(fd, &line);
	printf("%s\n", line);						//DEBUG
	while (get_next_line(fd, &line) > 0)
	{
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

int		ft_count_lines_columns(t_env *fdf, int fd)
{
	char		*line;

	if ((get_next_line(fd, &line)) < 1)
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
	int			fd;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (-1);
	if ((ft_count_lines_columns(fdf, fd)) == -1)
		return (-1);
	printf("nb lignes = %zu\tnb colonnes = %zu\n", fdf->map.nbl, fdf->map.nbcol);			//DEBUG
	if ((fd = open(filename, O_RDONLY)) == -1)
		return (-1);
	if ((ft_fill_map(fdf, fd)) == -1)
		return (-1);
	return (0);
}