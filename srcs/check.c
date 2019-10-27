/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 16:12:23 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/27 21:20:51 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_check_file(char *filename)
{
	int		fd;
	char	*line;
	int		len;

	if ((fd = open(filename, O_RDONLY)) == -1)
		return (-4);
	if (get_next_line(fd, &line) < 1)
		return (-2);
	len = ft_split_count(line, ' ');
	free(line);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_split_count(line, ' ') != len)
		{
			free(line);
			return (-3);
		}
		free(line);
	}
	if ((close(fd) == -1))
		return (-1);
	return (0);
}
