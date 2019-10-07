/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 16:12:23 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/07 13:59:26 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_check_file(char *filename)
{
	int		fd;
	char	*line;
	int		len;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (-1);
	if (get_next_line(fd, &line) < 1)
	{
		ft_putstr("file is empty\n");
		return (-1);
	}
	printf("CHECK line = \"%s\"\n", line);			//DEBUG
	len = ft_split_count(line, ' ');
	free(line);
	while (get_next_line(fd, &line) > 0)
	{
		printf("CHECK line = \"%s\"\n", line);			//DEBUG
		if (ft_split_count(line, ' ') != len)
		{
			ft_putstr("file format is incorrect\n");
			return (-1);
		}
	}
	free(line);
	if ((close(fd) == -1))
		return (-1);
	return (0);
}
