/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 14:53:23 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/04 16:07:15 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int			ft_error(void)
{
	ft_putstr("file is invalid\n");
	return (1);
}

int			ft_usage(void)
{
    ft_putstr("usage: ./fdf [map_file.fdf]\n");
    return (1);
}

int			main(int ac, char **av)
{
    if (ac != 2)
        return (ft_usage());
    if ((ft_check_file(av[1])) == 0)
        return (ft_error());
    //if file is good, start fdf
    return (0);
}