/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcanteau <jcanteau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/14 20:32:58 by jcanteau          #+#    #+#             */
/*   Updated: 2019/10/15 13:25:59 by jcanteau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static int		ft_ishex(char c)
{
	const char      *digits = "0123456789ABCDEF";
	int                     i;

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

void	ft_color(t_env *fdf,long color)
{
	(void)fdf;
	(void)color;
}