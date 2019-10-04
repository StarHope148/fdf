/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/04 16:12:23 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/04 16:24:11 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		ft_check_file(char *filename)
{
	int		fd;
	if ((fd = open(filename, O_RDONLY)) == 0)
		return (-1);
	return (0);
}