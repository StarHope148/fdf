/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 16:12:23 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/04 17:17:43 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_check_file(char *filename)
{
	int		fd;
	char	*whole_file;
	char	*line;
	int		len;

	if ((fd = open(filename, O_RDONLY)) == 0)
		return (-1);
	if (get_next_line(fd, &line) < 1)
	{
		ft_putstr("file is empty\n");
		return (-1);
	}
	len = ft_strlen(line);
	if (line)
		free(line);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strlen(line) != len)
			{
				ft_putstr("lines lenght are different\n");
				return (-1);
			}
		whole_file = ft_strjoinfree(whole_file, line);
	}
	return (0);
}