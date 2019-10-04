/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 14:53:23 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/04 15:18:07 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int        ft_usage(void)
{
    ft_putstr("usage: ./fdf [map_file.fdf]\n");
    return (1);
}

int        main(int ac, char **av)
{
    if (ac != 2)
        return (ft_usage());
    //check the file
    //if file is good, start fdf
    return (0);
}