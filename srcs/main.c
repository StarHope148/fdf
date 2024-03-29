/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 14:53:23 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/29 15:06:55 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_error(int error)
{
	if (error == -2)
		ft_putendl_fd("file is empty", 2);
	else if (error == -3)
		ft_putendl_fd("file format is invalide", 2);
	else if (error == -4)
		ft_putendl_fd("file not found or open() failed", 2);
	else if (error == -5)
		ft_putendl_fd("you tried to read over an infinite file", 2);
	else if (error == -6)
	{
		ft_putstr_fd("error during the parsing due to wrong color format ", 2);
		ft_putendl_fd("or exceding max/min value authorized", 2);
	}
	else
		ft_putendl_fd("an error occured", 2);
	return (EXIT_FAILURE);
}

int		ft_usage(void)
{
	ft_putendl_fd("usage: ./fdf [map_file.fdf]", 2);
	return (EXIT_FAILURE);
}

int		main(int ac, char **av)
{
	int		error;

	if (ac != 2)
		return (ft_usage());
	if (ft_strcmp(av[1], "/dev/zero") == 0)
		return (ft_error(-5));
	if ((error = ft_check_file(av[1])) < 0)
		return (ft_error(error));
	if ((error = ft_fdf_init(av[1])) < 0)
		return (ft_error(error));
	return (0);
}
