/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tool.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 15:32:45 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/20 14:59:30 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		ft_ishex(char c)
{
	const char		*digits = "0123456789ABCDEF";
	int				i;

	i = 0;
	while (i < 16)
	{
		if (c == ' ')
			return (-1);
		if (digits[i] == ft_toupper(c))
			return (i);
		i++;
	}
	return (-1);
}

int				ft_ahextoi(char *str)
{
	unsigned long	result;
	size_t			i;

	result = 0;
	i = 0;
	while (ft_ishex(str[i]) >= 0)
	{
		result = result * 16 + ft_ishex(str[i]);
		i++;
	}
	return ((int)result);
}

int				ft_color_fill(t_env *fdf, char *split, int x, int y)
{
	if (ft_strchr(split, ',') != NULL)
	{
		if (ft_strchr(split, 'x') == NULL)
			return (-1);
		fdf->map.tab[y][x].defcolor = ft_ahextoi(ft_strchr(split, 'x') + 1);
		fdf->map.tab[y][x].color = fdf->map.tab[y][x].defcolor;
	}
	else
	{
		fdf->map.tab[y][x].color = WHITE;
		fdf->map.tab[y][x].defcolor = WHITE;
	}
	return (0);
}
