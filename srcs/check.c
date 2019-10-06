/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 16:12:23 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/06 13:34:54 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_check_file(char *filename)
{
	int		fd;
	char	*whole_file;
	char	*line;
	int		len;

	whole_file = NULL;
	line = NULL;
	if ((fd = open(filename, O_RDONLY)) == 0)
		return (-1);
	if (get_next_line(fd, &line) < 1)
	{
		ft_putstr("file is empty\n");
		return (-1);
	}
	len = ft_split_count(line, ' ');
	free(line);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_split_count(line, ' ') != len)
			{
				ft_putstr("file format is incorrect\n");
				return (-1);
			}
	}
	printf("len = %d\n", len);					//DEBUG
	return (0);
}